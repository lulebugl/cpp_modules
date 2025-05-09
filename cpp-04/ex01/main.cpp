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
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Logger.hpp"

void testAnimalArray() {
    std::cout << "\n===== Animal Array Test =====\n" << std::endl;

    const int NUM_ANIMALS = 10;
    Animal*   animals[NUM_ANIMALS];

    for (int i = 0; i < NUM_ANIMALS; i++) {
        animals[i] = NULL;
    }

    std::cout << "Creating " << NUM_ANIMALS << " animals..." << std::endl;
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
    std::cout << "--- Cat Deep Copy ---" << std::endl;
    Cat* originalCat = new Cat();
    originalCat->setIdea("I want fish for dinner", 0);
    originalCat->setIdea("I should take a nap", 1);

    std::cout << "\nOriginal Cat's ideas:" << std::endl;
    originalCat->showBrain();

    Cat* copiedCat = new Cat(*originalCat);

    copiedCat->setIdea("I want tuna for dinner", 0);
    copiedCat->setIdea("I don't like that dog", 2);

    std::cout << "Original Cat's ideas:" << std::endl;
    originalCat->showBrain();
    std::cout << "Copied Cat's ideas:" << std::endl;
    copiedCat->showBrain();

    delete copiedCat;
    delete originalCat;

    std::cout << "\n--- Dog Deep Copy ---" << std::endl;
    Dog* originalDog = new Dog();
    originalDog->setIdea("cat!", 0);
    originalDog->setIdea("Ball! Ball! Ball!", 1);

    std::cout << "\nOriginal Dog's ideas:" << std::endl;
    originalDog->showBrain();
    Dog* copiedDog = new Dog();
    *copiedDog = *originalDog;
    copiedDog->setIdea("I need a walk now!", 1);
    copiedDog->setIdea("Squirrel!!!", 2);

    std::cout << "\nOriginal Dog's ideas:" << std::endl;
    originalDog->showBrain();
    std::cout << "Copied Dog's ideas:" << std::endl;
    copiedDog->showBrain();

    delete copiedDog;
    delete originalDog;
}

int main() {
    Logger::setLevel(LOG_LEVEL_DEBUG);
    Logger::setLevel(LOG_LEVEL_INFO);
    Logger::setLevel(LOG_LEVEL_DEBUG);
    
    const WrongAnimal* test = new WrongCat();

    delete test;
    // try {
    //     testAnimalArray();
    // } catch (const std::exception& e) {
    //     std::cerr << "Exception occurred in testAnimalA: " << e.what()
    //               << std::endl;
    // }
    // try {
    //     testDeepCopy();
    // } catch (const std::exception& e) {
    //     std::cerr << "Exception occurred in testDeepCopy: " << e.what()
    //               << std::endl;
    // }
    return 0;
}
