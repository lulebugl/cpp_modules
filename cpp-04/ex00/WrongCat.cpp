/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:36:08 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/06 20:36:08 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat() : WrongAnimal() {
    std::cout << "Default WrongCat constructor called" << std::endl;
    _type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal() {
    std::cout << "WrongCat Copy constructor called" << std::endl;
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "WrongCat Assignment operator called" << std::endl;
    if (this != &other) {
        this->_type = other._type;
    }
    return (*this);
}

WrongCat::~WrongCat() { std::cout << "Cat Destructor called" << std::endl; }

void WrongCat::makeSound() const { std::cout << "Meooow" << std::endl; }
