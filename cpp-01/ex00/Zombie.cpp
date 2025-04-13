/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 21:19:49 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/13 21:19:50 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie(const std::string& name) : _name(name) {}

Zombie::~Zombie() { std::cout << _name << " is destroyed" << std::endl; }

void Zombie::announce(void) const {
    std::cout << _name << ": " << "BraiiiiiiinnnzzzZ...\n";
}
