/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cell.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:49:32 by lgrigore          #+#    #+#             */
/*   Updated: 2026/02/03 05:17:33 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <cstring>
#include <iostream>

#include "../../include/StaticTabulizer.hpp"

StaticTabulizer::Cell::Cell()
    : content(""),
      borderMask(BORDER_NONE),
      letterCase(LETTER_CASE_DEFAULT),
      verticalAlignment(V_ALIGN_TOP),
      horizontalAlignment(H_ALIGN_LEFT) {}

StaticTabulizer::Cell::Cell(const Cell& other)
    : content(other.content),
      borderMask(other.borderMask),
      letterCase(other.letterCase),
      verticalAlignment(other.verticalAlignment),
      horizontalAlignment(other.horizontalAlignment) {}

StaticTabulizer::Cell::~Cell() {}

StaticTabulizer::Cell::Cell(const std::string& content_, BorderMask borderMask_,
           LetterCase letterCase_, VAlign verticalAlignment_,
           HAlign horizontalAlignment_)
    : content(content_),
      borderMask(borderMask_),
      letterCase(letterCase_),
      verticalAlignment(verticalAlignment_),
      horizontalAlignment(horizontalAlignment_) {}

bool StaticTabulizer::Cell::hasBorder(Border border) const { return (borderMask & border) != 0; }

StaticTabulizer::Cell& StaticTabulizer::Cell::operator=(const Cell& rhs) {
  if (this != &rhs) {
    content = rhs.content;
    borderMask = rhs.borderMask;
    letterCase = rhs.letterCase;
    verticalAlignment = rhs.verticalAlignment;
    horizontalAlignment = rhs.horizontalAlignment;
  }
  return *this;
}

const std::string StaticTabulizer::Cell::getContent() const {
  std::string result = content;
  switch (letterCase) {
    case LETTER_CASE_ALL_UPPER:
      for (size_t i = 0; i < result.size(); ++i)
        result[i] = std::toupper(result[i]);
      break;
    case LETTER_CASE_ALL_LOWER:
      for (size_t i = 0; i < result.size(); ++i)
        result[i] = std::tolower(result[i]);
      break;
    case LETTER_CASE_DEFAULT:
    default:
      break;
  }

  return result;
}

VAlign StaticTabulizer::Cell::getVerticalAlignment() const { return verticalAlignment; }

HAlign StaticTabulizer::Cell::getHorizontalAlignment() const { return horizontalAlignment; }

StaticTabulizer::Cell::IntersectionMask StaticTabulizer::Cell::getIntersectionMask(Cell::Corner corner) const {
  IntersectionMask result = 0;

  switch (corner) {
    case Cell::TOP_LEFT:
      if (hasBorder(BORDER_TOP)) result |= Cell::INTERSECTION_HAS_RIGHT;
      if (hasBorder(BORDER_LEFT)) result |= Cell::INTERSECTION_HAS_BOTTOM;
      break;

    case Cell::TOP_RIGHT:
      if (hasBorder(BORDER_TOP)) result |= Cell::INTERSECTION_HAS_LEFT;
      if (hasBorder(BORDER_RIGHT)) result |= Cell::INTERSECTION_HAS_BOTTOM;
      break;

    case Cell::BOTTOM_LEFT:
      if (hasBorder(BORDER_BOTTOM)) result |= Cell::INTERSECTION_HAS_RIGHT;
      if (hasBorder(BORDER_LEFT)) result |= Cell::INTERSECTION_HAS_TOP;
      break;

    case Cell::BOTTOM_RIGHT:
      if (hasBorder(BORDER_BOTTOM)) result |= Cell::INTERSECTION_HAS_LEFT;
      if (hasBorder(BORDER_RIGHT)) result |= Cell::INTERSECTION_HAS_TOP;
      break;

    default:
      break;
  }

  return result;
}