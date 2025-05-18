/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:58:58 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/12 11:58:58 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

#include <iostream>

#include "Logger.hpp"

MateriaSource::MateriaSource() {
    LOG_DEBUG("Default MateriaSource constructor called");
    for (int i = 0; i < NB_TEMPLATES; i++) {
        _templates[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    LOG_DEBUG("MateriaSource Copy constructor called");
    for (int i = 0; i < NB_TEMPLATES; i++) {
        _templates[i] = other._templates[i] ? other._templates[i]->clone() : 0;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    LOG_DEBUG("MateriaSource Assignment operator called");
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            delete _templates[i];
            _templates[i] =
                other._templates[i] ? other._templates[i]->clone() : 0;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    LOG_DEBUG("MateriaSource Destructor called");
    for (int i = 0; i < NB_TEMPLATES; i++) {
        delete _templates[i];
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; i++) {
        if (_templates[i] == 0) {
            _templates[i] = m->clone();
            return;
        }
    }
    std::cout << "The Materia slots are full\n";
}

AMateria* MateriaSource::createMateria(std::string const& type) {
    for (int i = 0; i < 4; i++) {
        if (_templates[i] && _templates[i]->getType() == type) {
            return _templates[i]->clone();
        }
    }
    std::cout << "Materia type " << type << " doesn't exist\n";
    return 0;
}
