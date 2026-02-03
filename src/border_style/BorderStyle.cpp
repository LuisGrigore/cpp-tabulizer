/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BorderStyle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 04:18:17 by lgrigore          #+#    #+#             */
/*   Updated: 2026/02/03 14:12:03 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/BorderStyle.hpp"

BorderStyle::BorderStyle(const char* horizontal, const char* vertical,
                         const char* topLeft, const char* topRight,
                         const char* bottomLeft, const char* bottomRight,
                         const char* cross, const char* rightT,
                         const char* leftT, const char* bottomT,
                         const char* topT)
    : horizontal(horizontal),
      vertical(vertical),
      topLeft(topLeft),
      topRight(topRight),
      bottomLeft(bottomLeft),
      bottomRight(bottomRight),
      cross(cross),
      rightT(rightT),
      leftT(leftT),
      bottomT(bottomT),
      topT(topT) {}

BorderStyle BorderStyle::ascii() {
  return BorderStyle("-", "|", "+", "+", "+", "+", "+", "+", "+", "+", "+");
}
BorderStyle BorderStyle::unicode() {
  return BorderStyle("─", "│", "┌", "┐", "└", "┘", "┼", "┤", "├", "┬", "┴");
}
BorderStyle BorderStyle::unicodeRounded() {
  return BorderStyle("─", "│", "╭", "╮", "╰", "╯", "┼", "┤", "├", "┬", "┴");
}
BorderStyle BorderStyle::unicodeDouble() {
  return BorderStyle("═", "║", "╔", "╗", "╚", "╝", "╬", "╣", "╠", "╦", "╩");
}
BorderStyle BorderStyle::unicodeBold() {
  return BorderStyle("━", "┃", "┏", "┓", "┗", "┛", "╋", "┫", "┣", "┳", "┻");
}
BorderStyle BorderStyle::unicodeDashed() {
  return BorderStyle("╌", "╎", "┌", "┐", "└", "┘", "┼", "┤", "├", "┬", "┴");
}
BorderStyle BorderStyle::minimal() {
  return BorderStyle("─", "│", " ", " ", " ", " ", " ", " ", " ", " ", " ");
}
