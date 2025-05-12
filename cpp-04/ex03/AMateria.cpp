/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 08:30:15 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/12 08:30:15 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#include "Logger.hpp"

AMateria::AMateria() : _type("") {
    LOG_DEBUG("Default AMateria constructor called");
}

AMateria::AMateria(const std::string& type) : _type(type) {
    LOG_DEBUG("AMateria constructor called");
}

AMateria::AMateria(const AMateria& other) {
    LOG_DEBUG("AMateria Copy constructor called");
    (void)other;
}

AMateria& AMateria::operator=(const AMateria& other) {
    LOG_DEBUG("AMateria Assignment operator called");
    if (this != &other) {
        (void)other;
    }
    return *this;
}

AMateria::~AMateria() { LOG_DEBUG("AMateria Destructor called"); }

std::string const& AMateria::getType() const {
    return _type;
}
