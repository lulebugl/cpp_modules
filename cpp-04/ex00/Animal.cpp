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

Animal::Animal() : _type("Unknown") {
    std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
    std::cout << "Animal Copy constructor called" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal Assignment operator called" << std::endl;
    if (this != &other) {
        this->_type = other._type;
    }
    return (*this);
}

Animal::~Animal() { std::cout << "Animal Destructor called" << std::endl; }

std::string Animal::getType() const { return _type; }

void Animal::makeSound() const {
    std::cout << "Unknown animal make a weird sound!" << std::endl;
}
