/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:34:28 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/12 08:59:17 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Logger.hpp"

void test_materia() {
    AMateria* cure = new Cure();

    AMateria* cloneCure = cure->clone();

    std::cout << cure->getType() << "\n";
    std::cout << "cloned " << cloneCure->getType() << "\n";
    delete cloneCure;
    delete cure;

    AMateria* ice = new Ice();
    AMateria* cloneIce = cure->clone();

    std::cout << ice->getType() << "\n";
    std::cout << "cloned " << cloneIce->getType() << "\n";
}

int main() {
    Logger::setLevel(LOG_LEVEL_INFO);

    test_materia();
    return 0;
}
