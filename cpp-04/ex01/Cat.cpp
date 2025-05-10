/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:12:30 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/06 20:12:30 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

#include "Logger.hpp"

Cat::Cat() : Animal(), _brain(new Brain) {
    LOG_DEBUG("Default Cat constructor called");
    _type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other) {
    LOG_DEBUG("Cat Copy constructor called");
    _brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other) {
    LOG_DEBUG("Cat Assignment operator called");
    if (this != &other) {
        Brain*  newBrain = new Brain(*other._brain);
        Animal::operator=(other);
        delete _brain;
        _brain = newBrain;
    }
    return *this;
}

Cat::~Cat() {
    LOG_DEBUG("Cat Destructor called");
    delete _brain;
}

void Cat::makeSound() const { std::cout << "Meooow" << std::endl; }

void Cat::setIdea(const std::string& idea, int idx) {
    _brain->setIdea(idea, idx);
}

std::string Cat::getIdea(int idx) const { return _brain->getIdea(idx); }

void Cat::showBrain() const {
    for (int i = 0; i < Brain::IDEAS_COUNT; i++) {
        std::string currentIdea = _brain->getIdea(i);
        if (!currentIdea.empty()) {
            std::cout << "- " << currentIdea << "\n";
        }
    }
}
