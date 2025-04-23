/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 01:24:15 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/23 01:24:15 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool Point::_debugMode = false;

Point::Point(void) : _x(0), _y(0) {
    if (_debugMode) {
        std::cout << "Default constructor called" << std::endl;
    }
}

Point::~Point(void) {
    if (_debugMode) {
        std::cout << "Destructor called" << std::endl;
    }
}

Point::Point(const float& x, const float& y) : _x(Fixed(x)), _y(Fixed(y)) {
    if (_debugMode) {
        std::cout << "Copy constructor called" << std::endl;
    }
}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {
    if (_debugMode) {
        std::cout << "Copy constructor called" << std::endl;
    }
}

Point& Point::operator=(const Point& other) {
    if (_debugMode) {
        std::cout << "Assignment operator called" << std::endl;
    }
    (void)other;
    return (*this);
}

Point Point::operator-(const Point& other) const {
    return Point((_x - other._x).toFloat(), (_y - other._y).toFloat());
}

const Fixed& Point::getX() const { return _x; }
const Fixed& Point::getY() const { return _y; }
