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

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "Default ScavTrap constructor called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

void ScavTrap::guardGate() {
    if (_hitPoints == 0) {
        std::cout << "Scavtrap " << _name << " is dead.\n";
        return;
    }
    std::cout << "Scavtrap " << _name << " is now in gate keeper mode.\n";
}

void ScavTrap::attack(const std::string& target) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        std::cout << "Scavtrap " << _name << " attacks " << target
                  << ", causing " << _attackDamage << " points of damage!\n";
        _energyPoints--;
    } else if (_hitPoints > 0) {
        std::cout << "Scavtrap " << _name << " has no energy left.\n";
    } else {
        std::cout << "Scavtrap " << _name << " is dead.\n";
    }
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    if (_debugMode) {
        std::cout << "Scavtrap constructor called" << std::endl;
    }
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    if (_debugMode) {
        std::cout << "Copy Scavtrap constructor called" << std::endl;
    }
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (_debugMode) {
        std::cout << "Assignment operator called" << std::endl;
    }
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return (*this);
}

ScavTrap::~ScavTrap() {
    if (_debugMode) {
        std::cout << "Scavtrap Destructor called" << std::endl;
    }
}
