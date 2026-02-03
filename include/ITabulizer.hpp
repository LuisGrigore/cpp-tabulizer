/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ITabulizer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 04:20:59 by lgrigore          #+#    #+#             */
/*   Updated: 2026/02/03 04:21:19 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_TABULIZER_HPP
#define I_TABULIZER_HPP

#include <string>

typedef unsigned char BorderMask;

enum Border {
  BORDER_NONE = 0,
  BORDER_TOP = 1 << 0,
  BORDER_BOTTOM = 1 << 1,
  BORDER_LEFT = 1 << 2,
  BORDER_RIGHT = 1 << 3,
  BORDER_ALL = BORDER_TOP | BORDER_BOTTOM | BORDER_LEFT | BORDER_RIGHT
};

enum LetterCase {
  LETTER_CASE_ALL_UPPER,
  LETTER_CASE_ALL_LOWER,
  LETTER_CASE_DEFAULT,
};

enum HAlign {
  H_ALIGN_LEFT,
  H_ALIGN_CENTER,
  H_ALIGN_RIGHT,
};

enum VAlign {
  V_ALIGN_TOP,
  V_ALIGN_CENTER,
  V_ALIGN_BOTTOM,
};

class ITabulizer {
 public:
  virtual ~ITabulizer() {};
  virtual void setCell(const unsigned int row, const unsigned int col,
                       const std::string content, const LetterCase letterCase,
                       const HAlign horizontalAlignment,
                       const VAlign verticalAlignment,
                       const BorderMask border) = 0;
  virtual void display() = 0;
};

#endif
