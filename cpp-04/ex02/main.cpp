/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:34:28 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/06 20:34:30 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    // Animal *Unicorn = new Animal();
    // can't instanciate an abstract class;
    Animal* Snoopy = new Dog();
    Animal* Nyanko = new Cat();

    std::cout << "\n";
    Snoopy->makeSound();
    Nyanko->makeSound();
    std::cout << "\n";

    delete Snoopy;

    return 0;
}
