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

#include <iostream>

#include "AMateria.hpp"
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
    for (int i = 0; i < INVENTORY_SLOTS; i++) {
        _inventory[i] = NULL;
    }
    *this = other;
}

Character& Character::operator=(const Character& other) {
    LOG_DEBUG("Character Assignment operator called");
    if (this != &other) {
        this->_name = other._name;
        for (int i = 0; i < INVENTORY_SLOTS; i++) {
            if (_inventory[i]) {
                delete _inventory[i];
                _inventory[i] = NULL;
            }
            if (other._inventory[i]) {
                _inventory[i] = other._inventory[i]->clone();
            }
        }
    }
    return *this;
}

Character::~Character() {
    LOG_DEBUG("Character Destructor called");
    for (int i = 0; i < INVENTORY_SLOTS; i++) {
        if (_inventory[i]) delete _inventory[i];
    }
}

std::string const& Character::getName() const { return _name; }

void Character::equip(AMateria* m) {
    if (!m) {
        LOG_WARNING("Cannot equip NULL materia");
        return;
    }

    for (int i = 0; i < INVENTORY_SLOTS; i++) {
        if (_inventory[i] == NULL) {
            std::cout << "Equipped " << m->getType() << " materia in slot " << i
                      << "\n";
            _inventory[i] = m;
            return;
        }
    }
    std::cout << "Inventory is full, cannot equip " << m->getType() << "\n";
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= INVENTORY_SLOTS) {
        LOG_WARNING("Invalid inventory index: " << idx);
        return;
    }
    if (_inventory[idx] == NULL) {
        std::cout << "No materia in slot " << idx << " to unequip\n";
        return;
    }
    std::cout << "Unequipped " << _inventory[idx]->getType() << " from slot "
              << idx << "\n";
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= INVENTORY_SLOTS) {
        LOG_WARNING("Invalid materia slot index: " << idx);
        return;
    }
    if (_inventory[idx] == NULL) {
        std::cout << "No materia in slot " << idx << "\n";
        return;
    }
    std::cout << _name << ": ";
    _inventory[idx]->use(target);
}
