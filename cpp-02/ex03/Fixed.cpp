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
bool      Fixed::_debugMode = true;

Fixed::Fixed(void) : _number(0) {
    if (_debugMode) {
        std::cout << "Default constructor called" << std::endl;
    }
    return;
}

Fixed::~Fixed(void) {
    if (_debugMode) {
        std::cout << "Destructor called" << std::endl;
    }
    return;
}

Fixed::Fixed(const int number) {
    if (_debugMode) {
        std::cout << "Int constructor called" << std::endl;
    }
    _number = number << _fixedPoint;
    return;
}

Fixed::Fixed(const float number) {
    if (_debugMode) {
        std::cout << "Float constructor called" << std::endl;
    }
    _number = roundf(number * (1 << _fixedPoint));
    return;
}

Fixed::Fixed(const Fixed &other) { this->_number = other._number; }

Fixed &Fixed::operator=(const Fixed &other) {
    if (_debugMode) {
        std::cout << "Copy assignment operator called" << std::endl;
    }
    if (this != &other) {
        this->_number = other._number;
    }
    return (*this);
}

bool Fixed::operator==(const Fixed &other) const {
    return (this->_number == other._number);
}

bool Fixed::operator!=(const Fixed &other) const {
    return (this->_number != other._number);
}

bool Fixed::operator>(const Fixed &other) const {
    return (this->_number > other._number);
}

bool Fixed::operator<(const Fixed &other) const {
    return (this->_number < other._number);
}

bool Fixed::operator>=(const Fixed &other) const {
    return (this->_number >= other._number);
}

bool Fixed::operator<=(const Fixed &other) const {
    return (this->_number <= other._number);
}

Fixed &Fixed::operator++() {
    this->_number++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp = *this;
    this->_number++;
    return tmp;
}

Fixed &Fixed::operator--() {
    this->_number--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp = *this;
    this->_number--;
    return tmp;
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
    if (other.toFloat() == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed(0);
    }
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::min(Fixed &x, Fixed &y) {
    return (x.toFloat() < y.toFloat() ? x : y);
}

const Fixed &Fixed::min(const Fixed &x, const Fixed &y) {
    return (x.toFloat() < y.toFloat() ? x : y);
}

Fixed &Fixed::max(Fixed &x, Fixed &y) {
    return (x.toFloat() > y.toFloat() ? x : y);
}

const Fixed &Fixed::max(const Fixed &x, const Fixed &y) {
    return (x.toFloat() > y.toFloat() ? x : y);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}

int Fixed::toInt() const { return this->_number >> _fixedPoint; }

float Fixed::toFloat() const {
    return static_cast<float>(this->_number) / (1 << _fixedPoint);
}

void Fixed::enableDebug() { _debugMode = true; }
void Fixed::disableDebug() { _debugMode = false; }
