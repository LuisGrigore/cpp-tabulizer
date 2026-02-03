/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TabulizerFactory.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 04:30:20 by lgrigore          #+#    #+#             */
/*   Updated: 2026/02/03 14:11:41 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABULIZER_FACTORY_HPP
#define TABULIZER_FACTORY_HPP

#include "BorderStyle.hpp"
#include "ITabulizer.hpp"

class TabulizerFactory {
 public:
  static ITabulizer* createStaticTabulizer(const unsigned int maxCellWidth,
                                           const unsigned int maxCellHeight,
                                           const bool flex,
                                           BorderStyle borderStyle);
};

#endif
