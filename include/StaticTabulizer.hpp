/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StaticTabulizer.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:57:14 by lgrigore          #+#    #+#             */
/*   Updated: 2026/02/03 05:08:23 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATIC_TABULIZER_HPP
#define STATIC_TABULIZER_HPP

#include "BorderStyle.hpp"
#include "ITabulizer.hpp"

class StaticTabulizer : public ITabulizer {
 private:
  class Cell {
   private:
    std::string content;
    BorderMask borderMask;
    LetterCase letterCase;
    VAlign verticalAlignment;
    HAlign horizontalAlignment;

   public:
    enum Corner { TOP_LEFT, TOP_RIGHT, BOTTOM_LEFT, BOTTOM_RIGHT };
    typedef unsigned char IntersectionMask;

    enum Intersection {
      INTERSECTION_HAS_NONE = 0,
      INTERSECTION_HAS_TOP = 1 << 0,
      INTERSECTION_HAS_BOTTOM = 1 << 1,
      INTERSECTION_HAS_LEFT = 1 << 2,
      INTERSECTION_HAS_RIGHT = 1 << 3,
    };
    Cell();
    Cell(const Cell& other);
    ~Cell();
    Cell(const std::string& content, BorderMask borderMask,
         LetterCase letterCase, VAlign verticalAlignment,
         HAlign horizontalAlignment);
    Cell& operator=(const Cell& rhs);
    bool hasBorder(Border border) const;
    const std::string getContent() const;
    VAlign getVerticalAlignment() const;
    HAlign getHorizontalAlignment() const;
    IntersectionMask getIntersectionMask(Cell::Corner corner) const;
  };
  static const int MAX_CONTENT_SIZE = 64;
  static const int MAX_ROWS = 1024;
  static const int MAX_COLS = 10;

  const unsigned int maxCellWidth;
  const unsigned int maxCellHeight;
  const bool flex;
  const BorderStyle borderStyle;

  Cell cells[MAX_ROWS][MAX_COLS];
  unsigned int rowHeights[MAX_ROWS];
  unsigned int colWidths[MAX_COLS];
  unsigned int nDisplayableRows;
  unsigned int nDisplayableCols;

  StaticTabulizer& operator=(const StaticTabulizer& rhs);
  std::string getIntersectionChar(Cell::IntersectionMask intersectionMask) const;
  Cell::IntersectionMask getCornerIntersectionMask(unsigned int row, unsigned int col,
                                             Cell::Corner corner);

 public:
  StaticTabulizer();
  StaticTabulizer(const unsigned int maxCellWidth,
                  const unsigned int maxCellHeight, const bool flex,
                  BorderStyle borderStyle);
  StaticTabulizer(const StaticTabulizer& other);
  virtual ~StaticTabulizer();
  virtual void setCell(const unsigned int row, const unsigned int col,
                       const std::string content, const LetterCase letterCase,
                       const HAlign horizontalAlignment,
                       const VAlign verticalAlignment,
                       const BorderMask borderMask);
  virtual void display();
};

#endif
