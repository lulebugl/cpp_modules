/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 09:52:16 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/24 09:52:16 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>

#include "ClapTrap.hpp"

void ScavTrap::guardGate() {
    if (_hitPoint == 0) {
        std::cout << "Scavtrap " << _name << " is dead.\n";
        return;
    }
    std::cout << "Scavtrap " << _name << " is now in gate keeper mode.\n";
}

void ScavTrap::attack(const std::string& target) {
    if (_EnergyPoint > 0 && _hitPoint > 0) {
        std::cout << "Scavtrap " << _name << " attacks " << target
                  << ", causing " << _AttackDamage << " points of damage!\n";
        _EnergyPoint--;
    } else if (_hitPoint > 0) {
        std::cout << "Scavtrap " << _name << " has no energy left.\n";
    } else {
        std::cout << "Scavtrap " << _name << " is dead.\n";
    }
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    if (_debugMode) {
        std::cout << "Default Scavtrap constructor called" << std::endl;
    }
    _hitPoint = 100;
    _EnergyPoint = 50;
    _AttackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    if (_debugMode) {
        std::cout << "Copy Scavtrap constructor called" << std::endl;
    }
    (void)other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (_debugMode) {
        std::cout << "Assignment operator called" << std::endl;
    }
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoint = other._hitPoint;
        this->_EnergyPoint = other._EnergyPoint;
        this->_AttackDamage = other._AttackDamage;
    }
    return (*this);
}

ScavTrap::~ScavTrap() {
    if (_debugMode) {
        std::cout << "Scavtrap Destructor called" << std::endl;
    }
}
