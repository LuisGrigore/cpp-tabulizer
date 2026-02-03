/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TabulizerFactory.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 04:37:51 by lgrigore          #+#    #+#             */
/*   Updated: 2026/02/03 05:09:42 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/TabulizerFactory.hpp"
#include "../../include/StaticTabulizer.hpp"

ITabulizer* TabulizerFactory::createStaticTabulizer(
    const unsigned int maxCellWidth, const unsigned int maxCellHeight,
    const bool flex, BorderStyle borderStyle) {
  return new StaticTabulizer(maxCellWidth, maxCellHeight, flex, borderStyle);
}