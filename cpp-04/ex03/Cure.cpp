/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 08:38:55 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/12 08:38:55 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

#include "AMateria.hpp"
#include "Logger.hpp"

Cure::Cure() : AMateria() {
    LOG_DEBUG("Default Cure constructor called");
    _type = "cure";
}

Cure::Cure(const Cure& other) : AMateria() {
    LOG_DEBUG("Cure Copy constructor called");
    *this = other;
}

Cure& Cure::operator=(const Cure& other) {
    LOG_DEBUG("Cure Assignment operator called");
    if (this != &other) {
        this->_type = "cure";
    }
    return *this;
}

Cure::~Cure() { LOG_DEBUG("Cure Destructor called"); }

AMateria* Cure::clone() const { return new Cure(); }
