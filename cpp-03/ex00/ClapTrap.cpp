/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 04:35:30 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/24 04:35:30 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

bool ClapTrap::_debugMode = true;

void ClapTrap::attack(const std::string& target) {
    if (_EnergyPoint > 0 && _hitPoint > 0) {
        std::cout << "ClapTrap " << _name << " attacks " << target
                  << ", causing " << _AttackDamage << " points of damage!\n";
        _EnergyPoint--;
    } else if (_hitPoint > 0) {
        std::cout << "ClapTrap " << _name << " has no energy left.\n";
    } else {
        std::cout << "ClapTrap " << _name << " is dead.\n";
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoint == 0) {
        std::cout << "ClapTrap " << _name << " is already dead.\n";
        return;
    }
    if (_hitPoint <= amount) {
        std::cout << "Claptrap " << _name << " took " << amount << " damage.\n";
        _hitPoint = 0;
        std::cout << "ClapTrap " << _name << " is dead.\n";
    } else {
        std::cout << "Claptrap " << _name << " took " << amount << " damage.\n";
        _hitPoint -= amount;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoint == 0) {
        std::cout << "ClapTrap " << _name << " is already dead.\n";
        return;
    }
    if (_EnergyPoint > 0) {
        if (_hitPoint > std::numeric_limits<unsigned int>::max() - amount) {
            _hitPoint = std::numeric_limits<unsigned int>::max();
            std::cout << "ClapTrap " << _name
                      << " has regained health to maximum capacity.\n";
        } else {
            _hitPoint += amount;
            std::cout << "ClapTrap " << _name << " has regained " << amount
                      << " hit points.\n";
        }
        _EnergyPoint--;
    } else {
        std::cout << "ClapTrap " << _name << " has no energy left.\n";
    }
}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoint(10), _EnergyPoint(10), _AttackDamage(0) {
    if (_debugMode) {
        std::cout << "Default constructor called" << std::endl;
    }
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    if (_debugMode) {
        std::cout << "Copy constructor called" << std::endl;
    }
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (_debugMode) {
        std::cout << "Assignment operator called" << std::endl;
    }
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoint = other._hitPoint;
        this->_AttackDamage = other._AttackDamage;
        this->_EnergyPoint = other._EnergyPoint;
    }
    return (*this);
}

ClapTrap::~ClapTrap() {
    if (_debugMode) {
        std::cout << "Destructor called" << std::endl;
    }
}
