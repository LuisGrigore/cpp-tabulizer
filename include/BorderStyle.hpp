/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BorderStyle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 04:18:07 by lgrigore          #+#    #+#             */
/*   Updated: 2026/02/03 04:19:16 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BORDER_STYLE_HPP
#define BORDER_STYLE_HPP

struct BorderStyle {
  const char* horizontal;   // ─
  const char* vertical;     // │
  const char* topLeft;      // ┌
  const char* topRight;     // ┐
  const char* bottomLeft;   // └
  const char* bottomRight;  // ┘

  const char* cross;    // ┼
  const char* rightT;   // ┤
  const char* leftT;    // ├
  const char* bottomT;  // ┴
  const char* topT;     // ┬

  BorderStyle(const char* horizontal, const char* vertical, const char* topLeft,
              const char* topRight, const char* bottomLeft,
              const char* bottomRight, const char* cross, const char* rightT,
              const char* leftT, const char* bottomT, const char* topT);

  static BorderStyle ascii();
  static BorderStyle unicode();
  static BorderStyle unicodeRounded();
  static BorderStyle unicodeDouble();
  static BorderStyle unicodeBold();
  static BorderStyle unicodeDashed();
  static BorderStyle minimal();
};

#endif
