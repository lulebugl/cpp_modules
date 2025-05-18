/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:54:40 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/09 19:54:40 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#include <iostream>

#include "Logger.hpp"

WrongAnimal::WrongAnimal() : _type("Unknown") {
    LOG_DEBUG("Default WrongAnimal constructor called");
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    LOG_DEBUG("WrongAnimal Copy constructor called");
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    LOG_DEBUG("WrongAnimal Assignment operator called");
    if (this != &other) {
        this->_type = other._type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() { LOG_DEBUG("WrongAnimal Destructor called"); }

std::string WrongAnimal::getType() const { return _type; }

void WrongAnimal::makeSound() const {
    std::cout << "Unknown animal makes a weird sound!" << std::endl;
}
