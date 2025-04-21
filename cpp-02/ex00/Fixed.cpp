/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:16:15 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/20 21:16:15 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

const int Fixed::_fixedPoint = 8;

Fixed::Fixed(void) {
    std::cout << "Default constructor called" << std::endl;
    _number = 0;
    return;
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    this->_number = other._number;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
    std::cout << "Assignment operator called" << std::endl;
    if (this != &fixed) {
        this->_number = fixed._number;
    }
    return (*this);
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
    return;
}

void Fixed::setRawBits(int raw) { _number = raw; }

int Fixed::getRawBits() const { return _number; }
