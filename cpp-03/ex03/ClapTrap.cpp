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
#include <limits>

bool ClapTrap::_debugMode = true;

ClapTrap::ClapTrap() : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    if (_debugMode) {
        std::cout << "ClapTrap constructor called" << std::endl;
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
        this->_hitPoints = other._hitPoints;
        this->_attackDamage = other._attackDamage;
        this->_energyPoints = other._energyPoints;
    }
    return (*this);
}

ClapTrap::~ClapTrap() {
    if (_debugMode) {
        std::cout << "ClapTrap Destructor called" << std::endl;
    }
}

void ClapTrap::attack(const std::string& target) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        std::cout << "ClapTrap " << _name << " attacks " << target
                  << ", causing " << _attackDamage << " points of damage!\n";
        _energyPoints--;
    } else if (_hitPoints > 0) {
        std::cout << "ClapTrap " << _name << " has no energy left.\n";
    } else {
        std::cout << "ClapTrap " << _name << " is dead.\n";
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is already dead.\n";
        return;
    }
    if (_hitPoints <= amount) {
        std::cout << "ClapTrap " << _name << " took " << amount << " damage.\n";
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " is dead.\n";
    } else {
        std::cout << "ClapTrap " << _name << " took " << amount << " damage.\n";
        _hitPoints -= amount;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is already dead.\n";
        return;
    }
    if (_energyPoints > 0) {
        if (_hitPoints > std::numeric_limits<unsigned int>::max() - amount) {
            _hitPoints = std::numeric_limits<unsigned int>::max();
            std::cout << "ClapTrap " << _name
                      << " has regained health to maximum capacity.\n";
        } else {
            _hitPoints += amount;
            std::cout << "ClapTrap " << _name << " has regained " << amount
                      << " hit points.\n";
        }
        _energyPoints--;
    } else {
        std::cout << "ClapTrap " << _name << " has no energy left.\n";
    }
}

void ClapTrap::displayStatus() const {
    if (_hitPoints <= 0) {
        std::cout << _name << " is dead.";
        return;
    }
    std::cout << "ClapTrap name: " << _name << std::endl;
    std::cout << "Hit points: " << _hitPoints << std::endl;
    std::cout << "Energy points: " << _energyPoints << std::endl;
    std::cout << "Attack damage: " << _attackDamage << std::endl;
}
