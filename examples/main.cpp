/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:03:31 by lgrigore          #+#    #+#             */
/*   Updated: 2026/02/03 04:46:04 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tabulizer.hpp"

int main() {
  // Tabla grande: ancho máximo 10, alto máximo 3, flex=true
  ITabulizer* table = TabulizerFactory::createStaticTabulizer(20, 5, true, BorderStyle::unicodeDouble());

  // Fila 0
  table->setCell(0, 0,
                "Nameeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
                "eeeeeeeeeeeeee",
                LETTER_CASE_ALL_UPPER, H_ALIGN_CENTER, V_ALIGN_CENTER, BORDER_ALL);
  table->setCell(0, 1, "Last Name", LETTER_CASE_DEFAULT, H_ALIGN_CENTER, V_ALIGN_CENTER, BORDER_ALL);
  table->setCell(0, 2, "FA", LETTER_CASE_DEFAULT, H_ALIGN_CENTER, V_ALIGN_CENTER, BORDER_ALL);
  table->setCell(0, 3, "FA", LETTER_CASE_DEFAULT, H_ALIGN_CENTER, V_ALIGN_CENTER, BORDER_ALL);
  table->setCell(0, 4, "FA", LETTER_CASE_DEFAULT, H_ALIGN_CENTER, V_ALIGN_CENTER, BORDER_ALL);
  table->setCell(0, 5, "FA", LETTER_CASE_DEFAULT, H_ALIGN_CENTER, V_ALIGN_CENTER, BORDER_ALL);

  table->setCell(1, 0,
                "Nameeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
                "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
                "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee",
                LETTER_CASE_ALL_LOWER, H_ALIGN_CENTER, V_ALIGN_CENTER, BORDER_ALL);
  table->setCell(1, 1, "Last Name", LETTER_CASE_DEFAULT, H_ALIGN_LEFT, V_ALIGN_TOP, BORDER_ALL);
  table->setCell(1, 2, "FA", LETTER_CASE_DEFAULT, H_ALIGN_CENTER, V_ALIGN_CENTER, BORDER_ALL);
  table->setCell(1, 3, "FA", LETTER_CASE_DEFAULT, H_ALIGN_CENTER, V_ALIGN_CENTER, BORDER_ALL);
  table->setCell(1, 4, "FA", LETTER_CASE_DEFAULT, H_ALIGN_CENTER, V_ALIGN_CENTER, BORDER_ALL);
  table->setCell(1, 5, "FA", LETTER_CASE_DEFAULT, H_ALIGN_CENTER, V_ALIGN_CENTER, BORDER_ALL);

  table->setCell(2, 0,
                "Nameeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
                "eeeeeeeeee",
                LETTER_CASE_DEFAULT, H_ALIGN_CENTER, V_ALIGN_CENTER, BORDER_ALL);
  table->setCell(2, 1, "Last aaaaaaa", LETTER_CASE_DEFAULT, H_ALIGN_RIGHT, V_ALIGN_BOTTOM, BORDER_ALL);
  table->setCell(2, 2, "FA", LETTER_CASE_DEFAULT, H_ALIGN_CENTER, V_ALIGN_CENTER, BORDER_ALL);
  table->setCell(2, 3, "FA", LETTER_CASE_DEFAULT, H_ALIGN_CENTER, V_ALIGN_CENTER, BORDER_ALL);
  table->setCell(2, 4, "FA", LETTER_CASE_DEFAULT, H_ALIGN_CENTER, V_ALIGN_CENTER, BORDER_ALL);
  table->setCell(2, 5, "FA", LETTER_CASE_DEFAULT, H_ALIGN_CENTER, V_ALIGN_CENTER, BORDER_ALL);

  table->setCell(3, 0, "Nameeeeeeeeeeeeeeeeeeeeeeeeeeeeee", LETTER_CASE_DEFAULT, H_ALIGN_CENTER,
                V_ALIGN_CENTER, BORDER_ALL);
  table->setCell(3, 1, "Last aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", LETTER_CASE_DEFAULT,
                H_ALIGN_CENTER, V_ALIGN_BOTTOM, BORDER_ALL);
  table->setCell(3, 2, "FA", LETTER_CASE_DEFAULT, H_ALIGN_CENTER, V_ALIGN_CENTER, BORDER_ALL);
  table->setCell(3, 3, "FA", LETTER_CASE_DEFAULT, H_ALIGN_CENTER, V_ALIGN_CENTER, BORDER_ALL);
  table->setCell(3, 4, "FA", LETTER_CASE_DEFAULT, H_ALIGN_CENTER, V_ALIGN_CENTER, BORDER_ALL);
  table->setCell(3, 5, "FA", LETTER_CASE_DEFAULT, H_ALIGN_CENTER, V_ALIGN_CENTER, BORDER_ALL);

  // Renderizar
  table->display();

  delete table;
  return 0;
}