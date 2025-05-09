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

Cat::Cat() : Animal(), _brain(new Brain) {
    std::cout << "Default Cat constructor called" << std::endl;
    _type = "Cat";
}

void Cat::makeSound() const { std::cout << "Meooow" << std::endl; }

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat Copy constructor called" << std::endl;
    _brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat Assignment operator called" << std::endl;
    if (this != &other) {
        Brain*  newBrain = new Brain(*other._brain);
        Animal::operator=(other);
        delete _brain;
        _brain = newBrain;
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat Destructor called" << std::endl;
    delete _brain;
}

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
    std::cout << "\n";
}
