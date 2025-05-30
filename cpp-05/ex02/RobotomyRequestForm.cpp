/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:14:51 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/30 13:14:51 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include "Logger.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
    LOG_DEBUG("Default RobotomyRequestForm constructor called");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
{
    LOG_DEBUG("RobotomyRequestForm Copy constructor called");
    (void) other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    LOG_DEBUG("RobotomyRequestForm Assignment operator called");
    if (this != &other)
    {
        // Copy member variables here
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    LOG_DEBUG("RobotomyRequestForm Destructor called");
}
