/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:16:29 by llebugle          #+#    #+#             */
/*   Updated: 2025/06/07 15:16:32 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "iter.hpp"

template <typename T>
void print(T const& x) {
    std::cout << x << " ";
}

template <typename T>
void doubleValue(T& x) {
    x *= 2;
}

void addExclamation(std::string& str) {
    str += "!";
}

void testIntegers() {
    int arr[] = {0, 1, 2};

    std::cout << "orginal arr: ";
    ::iter(arr, sizeof(arr) / sizeof(int), print<int>);
    ::iter(arr, sizeof(arr) / sizeof(int), doubleValue<int>);
    std::cout << "\nafter doubling : ";
    ::iter(arr, sizeof(arr) / sizeof(int), print<int>);
    std::cout << "\n";
}

void testStrings() {
    std::string strs[] = {"hello", "c++", "templates"};
    size_t      size = sizeof(strs) / sizeof(std::string);

    std::cout << "Original array: ";
    ::iter(strs, size, print);

    ::iter(strs, size, addExclamation);

    std::cout << "\nAfter adding exclamation: ";
    ::iter(strs, size, print<const std::string>);
    std::cout << "\n";
}

class SquareFunctor {
   public:
    void operator()(int& x) const {
        x = x * x;
    }
};

void testFunctor() {
    int    numArray[] = {1, 2, 3, 4, 5};
    size_t numSize = sizeof(numArray) / sizeof(int);

    std::cout << "Original array: ";
    ::iter(numArray, numSize, print<int>);

    SquareFunctor squarer;
    ::iter(numArray, numSize, squarer);

    std::cout << "\nAfter squaring: ";
    ::iter(numArray, numSize, print<int>);
    std::cout << "\n";
}

int main(void) {
    std::cout << "------\n";
    testIntegers();
    std::cout << "-----\n";
    testStrings();
    std::cout << "-----\n";
    testFunctor();

    return 0;
}
