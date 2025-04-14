/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 03:02:21 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/14 03:02:22 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : _type("") {}
Weapon::Weapon(std::string type) : _type(type) {}
Weapon::~Weapon() {}

void Weapon::setType(const std::string& type) { _type = type; }

std::string Weapon::getType() const { return _type; }
