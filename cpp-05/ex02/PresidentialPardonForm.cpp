/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:14:51 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/30 13:14:51 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#include "Logger.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
    LOG_DEBUG("Default PresidentialPardonForm constructor called");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
{
    LOG_DEBUG("PresidentialPardonForm Copy constructor called");
    (void) other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    LOG_DEBUG("PresidentialPardonForm Assignment operator called");
    if (this != &other)
    {
        // Copy member variables here
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    LOG_DEBUG("PresidentialPardonForm Destructor called");
}
