/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:00:20 by llebugle          #+#    #+#             */
/*   Updated: 2025/06/07 20:00:22 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Array.hpp"

int main() {
    Array<float> test;
    (void)test;
    
    std::cout << "=== Basic Array Test ===\n";
    Array<int> numbers(5);

    for (unsigned int i = 0; i < numbers.size(); i++) {
        numbers[i] = i * 10;
    }

    std::cout << "Array contents: ";
    for (unsigned int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\nArray size: " << numbers.size() << std::endl;

    std::cout << "\n=== Copy Constructor Test ===\n";
    Array<int> copy(numbers);

    std::cout << "Copy contents: ";
    for (unsigned int i = 0; i < copy.size(); i++) {
        std::cout << copy[i] << " ";
    }

    copy[2] = 999;

    std::cout << "\nOriginal after modifying copy: ";
    for (unsigned int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\nModified copy: ";
    for (unsigned int i = 0; i < copy.size(); i++) {
        std::cout << copy[i] << " ";
    }

    std::cout << "\n\n=== Assignment Operator Test ===\n";
    Array<int> other(2);
    other[0] = 100;
    other[1] = 200;

    std::cout << "Before assignment: ";
    for (unsigned int i = 0; i < other.size(); i++) {
        std::cout << other[i] << " ";
    }
    std::cout << " (size: " << other.size() << ")" << std::endl;

    std::cout << "After assignment: ";
    other = numbers;
    for (unsigned int i = 0; i < other.size(); i++) {
        std::cout << other[i] << " ";
    }
    std::cout << " (size: " << other.size() << ")" << std::endl;

    std::cout << "\n=== Exception Test ===\n";
    try {
        std::cout << "Trying invalid index..." << std::endl;
        std::cout << numbers[99];
    } catch (const std::exception& e) {
        std::cout << "Exception : " << e.what() << std::endl;
    }
    
    return 0;
}