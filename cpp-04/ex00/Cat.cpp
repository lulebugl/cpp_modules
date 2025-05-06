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

Cat::Cat() : Animal()
{
    std::cout << "Default Cat constructor called" << std::endl;
    _type = "Cat";
}

Cat::Cat(const Cat &other)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    (void) other;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat Assignment operator called" << std::endl;
    if (this != &other)
    {
        // Copy member variables here
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
}
