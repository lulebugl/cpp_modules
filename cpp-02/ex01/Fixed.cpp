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

#include <cmath>
#include <iostream>

const int Fixed::_fixedPoint = 8;

Fixed::Fixed(void) : _number(0) {
    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::Fixed(const int number) {
    std::cout << "Int constructor called" << std::endl;
    _number = number << _fixedPoint;
    return;
}

Fixed::Fixed(const float number) {
    std::cout << "Float constructor called" << std::endl;
    _number = roundf(number * (1 << _fixedPoint));
    return;
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    this->_number = other._number;
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_number = other._number;
    }
    return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
    return;
}

int Fixed::toInt() const { return this->_number >> _fixedPoint; }

float Fixed::toFloat() const {
    return static_cast<float>(this->_number) / (1 << _fixedPoint);
}
