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
    if (_hitPoints > 0) {
        std::cout << _name << " got a positive high five request." << std::endl;
    } else {
        std::cout << _name << " is dead." << std::endl;
    }
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "Default FragTrap constructor called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "Copy FragTrap constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "Assignment FragTrap operator called" << std::endl;
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return (*this);
}

FragTrap::~FragTrap() {
    std::cout << "Destructor FragTrap called" << std::endl;
}
