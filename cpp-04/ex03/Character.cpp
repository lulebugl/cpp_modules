/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 08:57:11 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/12 08:57:11 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

#include "Logger.hpp"

Character::Character() : _name("anonymous") {
    LOG_DEBUG("Default Character constructor called");
    for (int i = 0; i < INVENTORY_SLOTS; i++) {
        _inventory[i] = NULL;
    }
}

Character::Character(const std::string& name) : _name(name) {
    LOG_DEBUG("Character " << _name << " constructor called");
    for (int i = 0; i < INVENTORY_SLOTS; i++) {
        _inventory[i] = NULL;
    }
}

Character::Character(const Character& other) {
    LOG_DEBUG("Character Copy constructor called");
    *this = other;
}

Character& Character::operator=(const Character& other) {
    LOG_DEBUG("Character Assignment operator called");
    if (this != &other) {
        // operator=(other);
        this->_name = other._name;
        for (int i = 0; i < INVENTORY_SLOTS; i++) {
            if (_inventory[i] != NULL) delete _inventory[i];
            _inventory[i] = other._inventory[i];
        }
    }
    return *this;
}

Character::~Character() {
    LOG_DEBUG("Character Destructor called");
    for (int i = 0; i < INVENTORY_SLOTS; i++) {
        if (_inventory[i] != NULL) delete _inventory[i];
    }
}

std::string const& Character::getName() const { return _name; }
