/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StaticTabulizerPrivate.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 05:12:38 by lgrigore          #+#    #+#             */
/*   Updated: 2026/02/03 05:12:50 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/StaticTabulizer.hpp"

std::string StaticTabulizer::getIntersectionChar(
    StaticTabulizer::Cell::IntersectionMask intersectionMask) const {
  const bool top = intersectionMask & Cell::INTERSECTION_HAS_TOP;
  const bool bottom = intersectionMask & Cell::INTERSECTION_HAS_BOTTOM;
  const bool left = intersectionMask & Cell::INTERSECTION_HAS_LEFT;
  const bool right = intersectionMask & Cell::INTERSECTION_HAS_RIGHT;

  // 4 direcciones
  if (top && bottom && left && right) return borderStyle.cross;  // ┼

  // 3 direcciones
  if (top && bottom && left) return borderStyle.rightT;    // ┤
  if (top && bottom && right) return borderStyle.leftT;  // ├
  if (left && right && bottom) return borderStyle.bottomT;   // ┬
  if (left && right && top) return borderStyle.topT;   // ┴

  // 2 direcciones (esquinas)
  if (bottom && right) return borderStyle.topLeft;  // ┌
  if (bottom && left) return borderStyle.topRight;  // ┐
  if (top && right) return borderStyle.bottomLeft;  // └
  if (top && left) return borderStyle.bottomRight;  // ┘

  // 1 dirección
  if (top || bottom) return borderStyle.vertical;    // │
  if (left || right) return borderStyle.horizontal;  // ─

  return " ";
}

StaticTabulizer::Cell::IntersectionMask StaticTabulizer::getCornerIntersectionMask(
    unsigned int row, unsigned int col, Cell::Corner corner) {
  Cell::IntersectionMask mask = 0;

  switch (corner) {
    case Cell::TOP_LEFT:
      mask |= cells[row][col].getIntersectionMask(Cell::TOP_LEFT);

      if (col > 0) mask |= cells[row][col - 1].getIntersectionMask(Cell::TOP_RIGHT);

      if (row > 0) mask |= cells[row - 1][col].getIntersectionMask(Cell::BOTTOM_LEFT);

      if (row > 0 && col > 0)
        mask |= cells[row - 1][col - 1].getIntersectionMask(Cell::BOTTOM_RIGHT);
      break;

    case Cell::TOP_RIGHT:
      mask |= cells[row][col].getIntersectionMask(Cell::TOP_RIGHT);

      if (col + 1 < nDisplayableCols)
        mask |= cells[row][col + 1].getIntersectionMask(Cell::TOP_LEFT);

      if (row > 0)
        mask |= cells[row - 1][col].getIntersectionMask(Cell::BOTTOM_RIGHT);

      if (row > 0 && col + 1 < nDisplayableCols)
        mask |= cells[row - 1][col + 1].getIntersectionMask(Cell::BOTTOM_LEFT);
      break;

    case Cell::BOTTOM_LEFT:
      mask |= cells[row][col].getIntersectionMask(Cell::BOTTOM_LEFT);

      if (col > 0)
        mask |= cells[row][col - 1].getIntersectionMask(Cell::BOTTOM_RIGHT);

      if (row + 1 < nDisplayableRows)
        mask |= cells[row + 1][col].getIntersectionMask(Cell::TOP_LEFT);

      if (row + 1 < nDisplayableRows && col > 0)
        mask |= cells[row + 1][col - 1].getIntersectionMask(Cell::TOP_RIGHT);
      break;

    case Cell::BOTTOM_RIGHT:
      mask |= cells[row][col].getIntersectionMask(Cell::BOTTOM_RIGHT);

      if (col + 1 < nDisplayableCols)
        mask |= cells[row][col + 1].getIntersectionMask(Cell::BOTTOM_LEFT);

      if (row + 1 < nDisplayableRows)
        mask |= cells[row + 1][col].getIntersectionMask(Cell::TOP_RIGHT);

      if (row + 1 < nDisplayableRows && col + 1 < nDisplayableCols)
        mask |= cells[row + 1][col + 1].getIntersectionMask(Cell::TOP_LEFT);
      break;

    default:
      break;
  }

  return mask;
}