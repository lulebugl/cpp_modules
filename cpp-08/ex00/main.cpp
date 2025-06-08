/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 22:21:58 by llebugle          #+#    #+#             */
/*   Updated: 2025/06/08 22:22:04 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include <list>
#include <stdexcept>
#include <vector>

#include "easyfind.hpp"

void vectorExample() {
    int              arr[] = {0, 10, 20, 30};
    std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));

    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end();
         it++) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    std::vector<int>::iterator found = easyfind(numbers, 20);
    if (found != numbers.end()) {
        std::cout << "Found element: " << *found << "\n";
        std::cout << "Position: " << (found - numbers.begin()) << "\n";
    }

    std::cout << "* trying a value that isn't in the vector *\n";
    found = easyfind(numbers, 5);
    if (found == numbers.end())
        std::cout << "Element 5 not found\n";
}

void listExample() {
    std::list<int> numList;
    
    for (int i = 0; i < 4; ++i) {
        numList.push_back(i * 100);
        std::cout << numList.back() << " ";
    }
    std::cout << "\n";
    
    std::list<int>::iterator listFound = easyfind(numList, 100);
    if (listFound != numList.end()) {
        std::cout << "Found in list: " << *listFound << "\n";
    } else {
        std::cout << "not found\n";
    }
    
}

int main() {
    std::cout << "== vector example ==\n";
    vectorExample();
    std::cout << "\n== list example ==\n";
    listExample();

    return 0;
}
