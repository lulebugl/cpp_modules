/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:12:28 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/06 20:12:28 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal() {
    std::cout << "Default Dog constructor called" << std::endl;
    _type = "Dog";
}

Dog::Dog(const Dog& other) {
    std::cout << "Dog Copy constructor called" << std::endl;
    *this = other;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog Assignment operator called" << std::endl;
    if (this != &other) {
        this->_type = other._type;
    }
    return *this;
}

void Dog::makeSound() const { std::cout << "Wouaf Wouaf!" << std::endl; }

Dog::~Dog() { std::cout << "Dog Destructor called" << std::endl; }
