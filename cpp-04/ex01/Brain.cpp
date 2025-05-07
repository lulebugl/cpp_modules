/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:28:24 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/07 17:28:24 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>

Brain::Brain() {
    std::cout << "Default Brain constructor called" << std::endl;
    for (int i = 0; i < IDEAS_COUNT; i++) {
        _ideas[i] = "";
    }
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain Copy constructor called" << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain Assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < IDEAS_COUNT; i++) {
            this->_ideas[i] = other._ideas[i];
        }
    }
    return (*this);
}

Brain::~Brain() { std::cout << "Brain Destructor called" << std::endl; }

void Brain::setIdea(const std::string& idea, int idx) {
    if (idea.empty()) return;
    if (idx < 0 || idx >= IDEAS_COUNT) {
        throw std::out_of_range("Index out of range");
    }
    _ideas[idx] = idea;
}

std::string Brain::getIdea(int idx) const {
    if (idx < 0 || idx >= IDEAS_COUNT) {
        throw std::out_of_range("Index out of range");
    }
    return _ideas[idx];
}
