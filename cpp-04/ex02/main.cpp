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
#include <sstream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Logger.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void testAnimalArray() {
    std::cout << Logger::PURPLE << "--- Animal Array Test ---\n"
              << Logger::RESET;

    const int NUM_ANIMALS = 10;
    Animal*   animals[NUM_ANIMALS];

    for (int i = 0; i < NUM_ANIMALS; i++) {
        animals[i] = NULL;
    }

    std::cout << "\nCreating " << NUM_ANIMALS << " animals...\n";
    for (int i = 0; i < NUM_ANIMALS; i++) {
        std::stringstream ss;
        if (i < NUM_ANIMALS / 2) {
            animals[i] = new Dog();
            ss << "I am dog number " << i;
            std::string message = ss.str();
            animals[i]->setIdea(ss.str(), 0);
        } else {
            animals[i] = new Cat();
            ss << "I am cat number " << i;
            animals[i]->setIdea(ss.str(), 0);
        }
    }

    std::cout << "\nLet's hear them!" << std::endl;
    for (int i = 0; i < NUM_ANIMALS; i++) {
        std::cout << "Animal " << i << " says: ";
        animals[i]->makeSound();
    }

    std::cout << "\nCleaning up animals..." << std::endl;
    for (int i = 0; i < NUM_ANIMALS; i++) {
        if (animals[i]) {
            delete animals[i];
        }
    }
}

void testDeepCopy() {
    std::cout << Logger::PURPLE << "\n--- Cat Deep Copy ---\n\n" << Logger::RESET;
    
    
    Cat* originalCat = new Cat();
    originalCat->setIdea("I want fish for dinner", 0);
    originalCat->setIdea("I should take a nap", 1);

    Cat* copiedCat = new Cat(*originalCat);

    copiedCat->setIdea("I want tuna for dinner", 0);
    copiedCat->setIdea("I don't like that dog", 2);

    std::cout << "Original Cat's ideas:" << std::endl;
    originalCat->showBrain();
    std::cout << "\nCopied Cat's ideas:" << std::endl;
    copiedCat->showBrain();

    delete copiedCat;
    delete originalCat;

    std::cout << Logger::PURPLE << "\n--- Dog Deep Copy ---\n\n" << Logger::RESET;
    
    Dog* originalDog = new Dog();
    originalDog->setIdea("cat!", 0);
    originalDog->setIdea("Ball! Ball! Ball!", 1);

    Dog* copiedDog = new Dog();
    *copiedDog = *originalDog;
    copiedDog->setIdea("I need a walk now!", 1);
    copiedDog->setIdea("Squirrel!!!", 2);

    std::cout << "Original Dog's ideas:" << std::endl;
    originalDog->showBrain();
    std::cout << "Copied Dog's ideas:" << std::endl;
    copiedDog->showBrain();

    delete copiedDog;
    delete originalDog;
}

void testShallowCopy() {
    std::cout << Logger::PURPLE << "\n--- Shallow Copy ---\n\n" << Logger::RESET;

    WrongCat* cat1 = new WrongCat();
    cat1->setIdea("I want fish for dinner", 0);
    cat1->setIdea("I should take a nap", 1);

    WrongCat* cat2 = new WrongCat(*cat1);

    std::cout << "Cat1's ideas:" << std::endl;
    cat1->showBrain();
    std::cout << "Cat2's ideas:" << std::endl;
    cat2->showBrain();

    // Modify one cat's idea
    cat2->setIdea("I want tuna for dinner", 0);

    std::cout << "\nAfter modifying Cat2's idea:\n";
    std::cout << "Cat1's ideas:" << std::endl;
    cat1->showBrain();
    std::cout << "Cat2's ideas:" << std::endl;
    cat2->showBrain();

    delete cat2;
    delete cat1;
}

int main() {
    Logger::setLevel(LOG_LEVEL_INFO);

    const WrongAnimal* test = new WrongCat();
    new Animal* test1 = new Animal(); 
    delete test;

    testAnimalArray();
    testDeepCopy();
    // testShallowCopy();

    return 0;
}
