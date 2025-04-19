/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 03:02:42 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/14 03:03:01 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

#include <iostream>

#include "Weapon.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon)
    : _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

std::string HumanA::getName() const { return _name; }
std::string HumanA::getWeapon() const { return _weapon.getType(); }

void HumanA::setWeaponType(Weapon& weapon) { _weapon = weapon; }

void HumanA::attack() const {
    std::cout << getName() << " attacks with their " << getWeapon() << "\n";
}
