/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StaticTabulizer.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:49:32 by lgrigore          #+#    #+#             */
/*   Updated: 2026/02/06 16:36:58 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/StaticTabulizer.hpp"

#include <algorithm>
#include <cstring>
#include <iostream>

StaticTabulizer::StaticTabulizer()
    : maxCellWidth(10),
      maxCellHeight(1),
      flex(false),
      borderStyle(BorderStyle::ascii()),
      nDisplayableRows(0),
      nDisplayableCols(0) {
  for (unsigned int r = 0; r < MAX_ROWS; ++r) rowHeights[r] = 1;
  for (unsigned int c = 0; c < MAX_COLS; ++c) colWidths[c] = 1;
}

StaticTabulizer::StaticTabulizer(const unsigned int maxCellWidth_,
                                 const unsigned int maxCellHeight_,
                                 const bool flex_, BorderStyle borderStyle_)
    : maxCellWidth(maxCellWidth_),
      maxCellHeight(maxCellHeight_),
      flex(flex_),
      borderStyle(borderStyle_),
      nDisplayableRows(0),
      nDisplayableCols(0) {
  for (unsigned int r = 0; r < MAX_ROWS; ++r) rowHeights[r] = 1;
  for (unsigned int c = 0; c < MAX_COLS; ++c) colWidths[c] = 1;
}

StaticTabulizer::StaticTabulizer(const StaticTabulizer& other)
    : maxCellWidth(other.maxCellWidth),
      maxCellHeight(other.maxCellHeight),
      flex(other.flex),
      borderStyle(other.borderStyle),
      nDisplayableRows(other.nDisplayableRows),
      nDisplayableCols(other.nDisplayableCols) {
  for (unsigned int r = 0; r < MAX_ROWS; ++r)
    rowHeights[r] = other.rowHeights[r];
  for (unsigned int c = 0; c < MAX_COLS; ++c) colWidths[c] = other.colWidths[c];

  for (unsigned int r = 0; r < MAX_ROWS; ++r)
    for (unsigned int c = 0; c < MAX_COLS; ++c) cells[r][c] = other.cells[r][c];
}

StaticTabulizer::~StaticTabulizer() {}

void StaticTabulizer::setCell(unsigned int row, unsigned int col,
                              const std::string& content,
                              const CellOptions& options) {
  if (row >= MAX_ROWS || col >= MAX_COLS) return;

  cells[row][col] = Cell(content, options.border, options.letterCase,
                         options.vAlign, options.hAlign);

  unsigned int cellWidth =
      std::min((unsigned int)content.length(), maxCellWidth);

  unsigned int cellHeight = std::min(
      (unsigned int)((content.length() + maxCellWidth - 1) / maxCellWidth),
      maxCellHeight);

  if (colWidths[col] < cellWidth) colWidths[col] = cellWidth;

  if (rowHeights[row] < cellHeight) rowHeights[row] = cellHeight;

  if (row + 1 > nDisplayableRows) nDisplayableRows = row + 1;

  if (col + 1 > nDisplayableCols) nDisplayableCols = col + 1;
}

void StaticTabulizer::display() {
  unsigned int nRowChars = nDisplayableRows + 1;
  unsigned int nColChars = nDisplayableCols + 1;

  for (unsigned int i = 0; i < nDisplayableRows; i++)
    nRowChars += rowHeights[i];

  for (unsigned int i = 0; i < nDisplayableCols; i++) nColChars += colWidths[i];

  std::string buffer[nRowChars][nColChars + 1];

  for (unsigned int r = 0; r < nRowChars; r++) {
    for (unsigned int c = 0; c < nColChars; c++) {
      buffer[r][c] = " ";
    }
    buffer[r][nColChars] = "\n";
  }

  unsigned int rowCellRef = 0;

  for (unsigned int row = 0; row < nDisplayableRows; row++) {
    unsigned int colCellRef = 0;

    for (unsigned int col = 0; col < nDisplayableCols; col++) {
      unsigned int rowEnd = rowCellRef + rowHeights[row] + 1;
      unsigned int colEnd = colCellRef + colWidths[col] + 1;

      buffer[rowCellRef][colCellRef] = getIntersectionChar(
          getCornerIntersectionMask(row, col, Cell::TOP_LEFT));
      buffer[rowCellRef][colEnd] = getIntersectionChar(
          getCornerIntersectionMask(row, col, Cell::TOP_RIGHT));
      buffer[rowEnd][colCellRef] = getIntersectionChar(
          getCornerIntersectionMask(row, col, Cell::BOTTOM_LEFT));
      buffer[rowEnd][colEnd] = getIntersectionChar(
          getCornerIntersectionMask(row, col, Cell::BOTTOM_RIGHT));

      for (unsigned int c = colCellRef + 1; c < colEnd; c++) {
        if (cells[row][col].hasBorder(BORDER_TOP))
          buffer[rowCellRef][c] = borderStyle.horizontal;
        if (cells[row][col].hasBorder(BORDER_BOTTOM))
          buffer[rowEnd][c] = borderStyle.horizontal;
      }

      for (unsigned int r = rowCellRef + 1; r < rowEnd; r++) {
        if (cells[row][col].hasBorder(BORDER_LEFT))
          buffer[r][colCellRef] = borderStyle.vertical;
        if (cells[row][col].hasBorder(BORDER_RIGHT))
          buffer[r][colEnd] = borderStyle.vertical;
      }

      std::string text = cells[row][col].getContent();

      unsigned int cellInnerWidth = colWidths[col];
      unsigned int cellInnerHeight = rowHeights[row];

      unsigned int textHeight =
          (unsigned int)((text.length() + cellInnerWidth - 1) / cellInnerWidth);
      if (textHeight > cellInnerHeight) textHeight = cellInnerHeight;

      unsigned int padTop = 0;
      if (cellInnerHeight > textHeight) {
        unsigned int freeSpace = cellInnerHeight - textHeight;
        switch (cells[row][col].getVerticalAlignment()) {
          case V_ALIGN_TOP:
            padTop = 0;
            break;
          case V_ALIGN_CENTER:
            padTop = freeSpace / 2;
            break;
          case V_ALIGN_BOTTOM:
            padTop = freeSpace;
            break;
        }
      }

      unsigned int k = 0;

      for (unsigned int line = 0; line < textHeight; line++) {
        unsigned int remaining = text.length() - k;
        unsigned int lineLen = cellInnerWidth;
        if (remaining < lineLen) lineLen = remaining;

        unsigned int padLeft = 0;
        if (cellInnerWidth > lineLen) {
          unsigned int freeSpace = cellInnerWidth - lineLen;
          switch (cells[row][col].getHorizontalAlignment()) {
            case H_ALIGN_LEFT:
              padLeft = 0;
              break;
            case H_ALIGN_CENTER:
              padLeft = freeSpace / 2;
              break;
            case H_ALIGN_RIGHT:
              padLeft = freeSpace;
              break;
          }
        }

        unsigned int bufferRow = rowCellRef + 1 + padTop + line;
        unsigned int bufferCol = colCellRef + 1 + padLeft;

        for (unsigned int c = 0; c < lineLen; c++) {
          if (k < text.length() - 1 && line == textHeight - 1 &&
              c == lineLen - 1) {
            buffer[bufferRow][bufferCol + c] = ".";
            k++;
          } else {
            buffer[bufferRow][bufferCol + c] = text[k++];
          }
        }
      }

      colCellRef = colEnd;
    }

    rowCellRef += rowHeights[row] + 1;
  }

  for (unsigned int r = 0; r < nRowChars; r++) {
    for (unsigned int c = 0; c <= nColChars; c++) {
      std::cout << buffer[r][c];
    }
  }
}

void StaticTabulizer::clear() {
  for (unsigned int r = 0; r < MAX_ROWS; r++) {
    for (unsigned int c = 0; c < MAX_COLS; c++) {
      cells[r][c] = Cell();
    }
    rowHeights[r] = 1;
  }
  for (unsigned int c = 0; c < MAX_COLS; c++) {
    colWidths[c] = 1;
  }
  nDisplayableRows = 0;
  nDisplayableCols = 0;
}

void StaticTabulizer::setCellMaxDimensions(unsigned int maxWidth,
                                           unsigned int maxHeight) {
  maxCellHeight = maxHeight;
  maxCellWidth = maxWidth;
}
