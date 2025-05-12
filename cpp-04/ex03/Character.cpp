/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 08:57:11 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/12 08:57:11 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

#include "Logger.hpp"

Character::Character()
{
    LOG_DEBUG("Default Character constructor called");
}

Character::Character(const Character &other)
{
    LOG_DEBUG("Character Copy constructor called");
    (void) other;
}

Character &Character::operator=(const Character &other)
{
    LOG_DEBUG("Character Assignment operator called");
    if (this != &other)
    {
        // Copy member variables here
    }
    return *this;
}

Character::~Character()
{
    LOG_DEBUG("Character Destructor called");
}
