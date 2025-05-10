/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:12:28 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/06 20:12:28 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

#include "Logger.hpp"

Dog::Dog() : Animal(), _brain(new Brain) {
    LOG_DEBUG("Default Dog constructor called");
    _type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other) {
    LOG_DEBUG("Dog Copy constructor called");
    _brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other) {
    LOG_DEBUG("Dog Assignment operator called");
    if (this != &other) {
        Brain*  newBrain = new Brain(*other._brain);
        Animal::operator=(other);
        delete _brain;
        _brain = newBrain;
    }
    return *this;
}

Dog::~Dog() {
    LOG_DEBUG("Dog Destructor called");
    delete _brain;
}

void Dog::makeSound() const { std::cout << "Wouaf Wouaf!" << std::endl; }

void Dog::setIdea(const std::string& idea, int idx) {
    _brain->setIdea(idea, idx);
}

std::string Dog::getIdea(int idx) const { return _brain->getIdea(idx); }

void Dog::showBrain() const {
    for (int i = 0; i < Brain::IDEAS_COUNT; i++) {
        std::string currentIdea = _brain->getIdea(i);
        if (!currentIdea.empty()) {
            std::cout << "- " << currentIdea << "\n";
        }
    }
    std::cout << "\n";
}
