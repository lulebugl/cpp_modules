/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:49:38 by llebugle          #+#    #+#             */
/*   Updated: 2025/06/10 19:23:14 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <iostream>
#include <sstream>
#include <vector>

#include "PmergeMe.hpp"

template <typename Container>
void printContainer(Container& container) {
    for (typename Container::const_iterator it = container.begin();
         it != container.end(); ++it) {
        std::cout << *it << " ";
    }
}

template <typename Container>
Container parseArguments(const std::string& str) {
    Container int_container;

    std::istringstream iss(str);
    std::string        token;

    while (iss >> token) {
        try {
            int value = std::stoi(token);
            int_container.push_back(value);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error parsing argument: " << e.what() << std::endl;
        }
    }

    return int_container;
}

// use deque and vector
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: ./PmergeMe 'sequence of positive integers'\n";
        return 0;
    }

    std::string      numbers = argv[1];
    std::vector<int> vec = parseArguments<std::vector<int> >(numbers);
    std::deque<int>  deque = parseArguments<std::deque<int> >(numbers);

    std::cout << "Before:   ";
    printContainer(vec);
    std::cout << "\nAfter:    ";
    printContainer(vec);
    std::cout << "\n";

    return 0;
}
