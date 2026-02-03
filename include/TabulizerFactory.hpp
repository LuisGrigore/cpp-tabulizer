/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TabulizerFactory.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:13:27 by lgrigore          #+#    #+#             */
/*   Updated: 2026/02/03 15:13:28 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABULIZER_FACTORY_HPP
#define TABULIZER_FACTORY_HPP

#include "BorderStyle.hpp"
#include "ITabulizer.hpp"

/**
 * @brief Factory class to create tabulizer instances
 */
class TabulizerFactory {
 public:
  /**
   * @brief Create a static tabulizer
   * @param maxCellWidth Maximum width of a cell
   * @param maxCellHeight Maximum height of a cell
   * @param flex Whether the table flexibly resizes columns
   * @param borderStyle Border style to use
   * @return Pointer to ITabulizer instance
   */
  static ITabulizer* createStaticTabulizer(const unsigned int maxCellWidth,
                                           const unsigned int maxCellHeight,
                                           const bool flex,
                                           BorderStyle borderStyle);
};

#endif  // TABULIZER_FACTORY_HPP
