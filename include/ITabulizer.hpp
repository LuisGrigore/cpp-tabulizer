/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ITabulizer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:11:28 by lgrigore          #+#    #+#             */
/*   Updated: 2026/02/06 16:35:33 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_TABULIZER_HPP
#define I_TABULIZER_HPP

#include <string>

typedef unsigned char BorderMask;  ///< Bitmask for border sides

/**
 * @brief Border sides (bitmask)
 */
enum Border {
  BORDER_NONE = 0,
  BORDER_TOP = 1 << 0,
  BORDER_BOTTOM = 1 << 1,
  BORDER_LEFT = 1 << 2,
  BORDER_RIGHT = 1 << 3,
  BORDER_ALL = BORDER_TOP | BORDER_BOTTOM | BORDER_LEFT | BORDER_RIGHT
};

/**
 * @brief Letter case options for cell content
 */
enum LetterCase {
  LETTER_CASE_ALL_UPPER,
  LETTER_CASE_ALL_LOWER,
  LETTER_CASE_DEFAULT,
};

/**
 * @brief Horizontal alignment options for cell content
 */
enum HAlign {
  H_ALIGN_LEFT,
  H_ALIGN_CENTER,
  H_ALIGN_RIGHT,
};

/**
 * @brief Vertical alignment options for cell content
 */
enum VAlign {
  V_ALIGN_TOP,
  V_ALIGN_CENTER,
  V_ALIGN_BOTTOM,
};

/**
 * @brief Structure representing all configurable options for a table cell
 */
struct CellOptions {
  LetterCase letterCase;  ///< Letter casing
  HAlign hAlign;          ///< Horizontal alignment
  VAlign vAlign;          ///< Vertical alignment
  BorderMask border;      ///< Borders for the cell

  /// Default constructor sets default options
  CellOptions()
      : letterCase(LETTER_CASE_DEFAULT),
        hAlign(H_ALIGN_CENTER),
        vAlign(V_ALIGN_CENTER),
        border(BORDER_NONE) {}
};

/**
 * @brief Interface for a tabular table
 */
class ITabulizer {
 public:
  virtual ~ITabulizer() {}

  /**
   * @brief Set the content of a cell with options
   * @param row Row index
   * @param col Column index
   * @param content Text content for the cell
   * @param options Formatting options for the cell
   */
  virtual void setCell(unsigned int row, unsigned int col,
                       const std::string& content,
                       const CellOptions& options = CellOptions()) = 0;
  virtual void setCellMaxDimensions(unsigned int maxWidth,
                                    unsigned int maxHeight) = 0;

  /**
   * @brief Render the table to the terminal
   */
  virtual void display() = 0;
  /**
   * @brief Clear all cell contents and reset the table
   */
  virtual void clear() = 0;
};

#endif  // I_TABULIZER_HPP
