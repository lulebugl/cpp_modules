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
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    // {
    //     const Animal* snoopy = new Dog();
    //     const Animal* nyanko = new Cat();

    //     delete snoopy;
    //     delete nyanko;
    // }
    {
        Cat* nyanko = new Cat();
        nyanko->setIdea("what is this dog doing here??", 0);
        nyanko->setIdea("move", 1);
        Cat* nyankoSensei = nyanko;
        nyankoSensei->setIdea("let me through", 3);
        std::cout << "nyankoSensei's brain:\n";
        nyankoSensei->showBrain();

        delete nyanko;
        // delete nyankoSensei;
    }
    return 0;
}
