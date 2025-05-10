/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:54:43 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/09 19:54:43 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#include <iostream>

#include "Brain.hpp"
#include "Logger.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat() : WrongAnimal(), _brain(new Brain) {
    LOG_DEBUG("Default WrongCat constructor called");
    _type = "Cat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    LOG_DEBUG("WrongCat Copy constructor called");
    _brain = other._brain;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    LOG_DEBUG("WrongCat Assignment operator called");
    if (this != &other) {
        WrongAnimal::operator=(other);
        this->_brain = other._brain;
    }
    return *this;
}

WrongCat::~WrongCat() {
    LOG_DEBUG("WrongCat Destructor called");
    // delete _brain; double free if shared brain
}

void WrongCat::makeSound() const { std::cout << "Meooow" << std::endl; }

void WrongCat::setIdea(const std::string& idea, int idx) {
    _brain->setIdea(idea, idx);
}

std::string WrongCat::getIdea(int idx) const { return _brain->getIdea(idx); }

void WrongCat::showBrain() const {
    for (int i = 0; i < Brain::IDEAS_COUNT; i++) {
        std::string currentIdea = _brain->getIdea(i);
        if (!currentIdea.empty()) {
            std::cout << "- " << currentIdea << "\n";
        }
    }
    std::cout << "\n";
}
