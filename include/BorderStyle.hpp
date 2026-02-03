/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BorderStyle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:08:10 by lgrigore          #+#    #+#             */
/*   Updated: 2026/02/03 15:08:11 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BORDER_STYLE_HPP
#define BORDER_STYLE_HPP

#include <string>

/**
 * @brief Structure representing the style of table borders.
 *
 * Each member defines a specific character used to render the table.
 * Unicode characters are provided for preview in comments.
 */
struct BorderStyle {
  const char* horizontal;   ///< Horizontal line character ─
  const char* vertical;     ///< Vertical line character │
  const char* topLeft;      ///< Top-left corner ┌
  const char* topRight;     ///< Top-right corner ┐
  const char* bottomLeft;   ///< Bottom-left corner └
  const char* bottomRight;  ///< Bottom-right corner ┘
  const char* cross;        ///< Intersection character ┼
  const char* rightT;       ///< Right T-junction ┤
  const char* leftT;        ///< Left T-junction ├
  const char* bottomT;      ///< Bottom T-junction ┴
  const char* topT;         ///< Top T-junction ┬

  /**
   * @brief Constructor for BorderStyle
   * @param horizontal Horizontal line character
   * @param vertical Vertical line character
   * @param topLeft Top-left corner
   * @param topRight Top-right corner
   * @param bottomLeft Bottom-left corner
   * @param bottomRight Bottom-right corner
   * @param cross Intersection character
   * @param rightT Right T-junction
   * @param leftT Left T-junction
   * @param bottomT Bottom T-junction
   * @param topT Top T-junction
   */
  BorderStyle(const char* horizontal, const char* vertical, const char* topLeft,
              const char* topRight, const char* bottomLeft,
              const char* bottomRight, const char* cross, const char* rightT,
              const char* leftT, const char* bottomT, const char* topT);

  /// Predefined styles
  static BorderStyle ascii();           ///< ASCII style using +, -, |
  static BorderStyle unicode();         ///< Unicode single lines ─│┌┐└┘
  static BorderStyle unicodeRounded();  ///< Rounded corners ╭╮╰╯
  static BorderStyle unicodeDouble();   ///< Double lines ╔═╗╚═╝
  static BorderStyle unicodeBold();     ///< Bold block ▛▀▜▙▄▟
  static BorderStyle unicodeDashed();   ///< Dashed ─ ─
  static BorderStyle minimal();         ///< Minimal style - |
};

#endif  // BORDER_STYLE_HPP
