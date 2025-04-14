/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 03:03:08 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/14 03:03:09 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

#include <string>
#include <iostream>
#include "Weapon.hpp"

HumanB::HumanB() : _name("Human B"), _weapon(0) {}
HumanB::HumanB(const std::string& name) : _name(name), _weapon(0) {}
HumanB::HumanB(const std::string& name, Weapon* weapon)
    : _name(name), _weapon(weapon) {}

HumanB::~HumanB() {}

std::string HumanB::getName() const { return _name; }
std::string HumanB::getWeapon() const {
    if (_weapon) {
        return _weapon->getType();
    }
    return "bare hands";
}

void HumanB::setWeapon(Weapon& weapon) { _weapon = &weapon; }

void HumanB::attack() const {
    std::cout << getName() << " attacks with their " << getWeapon() << "\n";
}
