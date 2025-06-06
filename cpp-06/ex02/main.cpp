/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 23:19:13 by llebugle          #+#    #+#             */
/*   Updated: 2025/06/06 23:19:18 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base* generate(void) {
    switch (rand() % 3) {
        case 0: {
            std::cout << "created class A\n";
            return new A();
        }
        case 1: {
            std::cout << "created class B\n";
            return new B();
        }
        case 2: {
            std::cout << "created class C\n";
            return new C();
        }
        default: return new A();
    }
}

void identify(Base* p) {
    A* testA(dynamic_cast<A*>(p));
    B* testB(dynamic_cast<B*>(p));
    C* testC(dynamic_cast<C*>(p));

    std::cout << "identifying ptr...\n";
    if (testA) {
        std::cout << "It's a class A ptr\n";
    } else if (testB) {
        std::cout << "It's a class B ptr\n";
    } else if (testC) {
        std::cout << "It's a class C ptr\n";
    }
}

void identify(Base& p) {
    std::cout << "identifying ref...\n";
    try {
        A testA(dynamic_cast<A&>(p));
        std::cout << "It's a class A ref\n";
    } catch (std::exception& e) {};
    try {
        B testB(dynamic_cast<B&>(p));
        std::cout << "It's a class B ref\n";
    } catch (std::exception& e) {};
    try {
        C testC(dynamic_cast<C&>(p));
        std::cout << "It's a class C ref\n";
    } catch (std::exception& e) {};

}

int main() {
    // seeding time for rand;
    srand(static_cast<unsigned int>(time(NULL)));
    
    Base* test = generate();
    identify(test);
    identify(*test);
    return 0;
}
