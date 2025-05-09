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

Dog::Dog() : Animal(), _brain(new Brain) {
    std::cout << "Default Dog constructor called" << std::endl;
    _type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog Copy constructor called" << std::endl;
    _brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog Assignment operator called" << std::endl;
    if (this != &other) {
        Brain*  newBrain = new Brain(*other._brain);
        Animal::operator=(other);
        delete _brain;
        _brain = newBrain;
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog Destructor called" << std::endl;
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
