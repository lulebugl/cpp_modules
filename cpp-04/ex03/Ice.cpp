/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 08:38:55 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/12 08:38:55 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

#include "Logger.hpp"
#include <iostream>

Ice::Ice() : AMateria() {
    LOG_DEBUG("Default Ice constructor called");
    _type = "ice";
}

Ice::Ice(const Ice& other) : AMateria() {
    LOG_DEBUG("Ice Copy constructor called");
    *this = other;
}

Ice& Ice::operator=(const Ice& other) {
    LOG_DEBUG("Ice Assignment operator called");
    if (this != &other) {
        this->_type = "ice";
    }
    return *this;
}

Ice::~Ice() { LOG_DEBUG("Ice Destructor called"); }

AMateria* Ice::clone() const { return new Ice(); }

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at "<< target.getName() <<" *\n"; 
}
