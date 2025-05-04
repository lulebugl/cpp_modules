/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:05:47 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/04 17:05:47 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>

void FragTrap::highFivesGuys() {
    if (_hitPoint > 0) {
        std::cout << _name << " got a positive high five request." << std::endl;
    } else {
        std::cout << _name << " is dead." << std::endl;
    }
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "Default FragTrap constructor called" << std::endl;
    _hitPoint = 100;
    _EnergyPoint = 100;
    _AttackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "Copy FragTrap constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "Assignment FragTrap operator called" << std::endl;
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoint = other._hitPoint;
        this->_EnergyPoint = other._EnergyPoint;
        this->_AttackDamage = other._AttackDamage;
    }
    return (*this);
}

FragTrap::~FragTrap() {
    std::cout << "Destructor FragTrap called" << std::endl;
}
