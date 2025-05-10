/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:12:20 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/06 20:12:20 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>

#include "Logger.hpp"

Animal::Animal() : _type("Unknown") {
    LOG_DEBUG("Default Animal constructor called");
}

Animal::Animal(const Animal& other) {
    LOG_DEBUG("Animal Copy constructor called");
    *this = other;
}

Animal& Animal::operator=(const Animal& other) {
    LOG_DEBUG("Animal Assignment operator called");
    if (this != &other) {
        this->_type = other._type;
    }
    return (*this);
}

Animal::~Animal() { LOG_DEBUG("Animal Destructor called"); }

std::string Animal::getType() const { return _type; }

void Animal::makeSound() const {
    std::cout << "Unknown animal makes a weird sound!" << std::endl;
}
