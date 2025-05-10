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
#include <sstream>

#include "Logger.hpp"

Brain::Brain() {
    LOG_DEBUG("Default Brain constructor called");
    for (int i = 0; i < IDEAS_COUNT; i++) {
        _ideas[i] = "";
    }
}

Brain::Brain(const Brain& other) {
    LOG_DEBUG("Brain Copy constructor called");
    *this = other;
}

Brain& Brain::operator=(const Brain& other) {
    LOG_DEBUG("Brain Assignment operator called");
    if (this != &other) {
        for (int i = 0; i < IDEAS_COUNT; i++) {
            this->_ideas[i] = other._ideas[i];
        }
    }
    return (*this);
}

Brain::~Brain() { LOG_DEBUG("Brain Destructor called"); }

void Brain::setIdea(const std::string& idea, int idx) {
    if (idea.empty()) return;
    if (idx < 0 || idx >= IDEAS_COUNT) {
        std::stringstream ss;
        ss << "Idea index out of range: " << idx;
        LOG_ERROR(ss.str());
        return ;
    }
    _ideas[idx] = idea;
}

std::string Brain::getIdea(int idx) const {
    if (idx < 0 || idx >= IDEAS_COUNT) {
        std::stringstream ss;
        ss << "Idea index out of range: " << idx;
        LOG_ERROR(ss.str());
        return "";
    }
    return _ideas[idx];
}
