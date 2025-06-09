/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 00:58:07 by llebugle          #+#    #+#             */
/*   Updated: 2025/06/10 00:58:09 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <list>
#include <stack>

#include "MutantStack.hpp"

void print_separator() {
    std::cout << std::setfill('-') << std::setw(25) << "" << std::endl;
    std::cout << std::setfill(' ');
}

int main() {
    const int COL_WIDTH = 12;

    print_separator();
    std::cout << std::setw(COL_WIDTH) << "MutantStack" << "| "
              << "std::list\n";
    print_separator();

    MutantStack<int> mstack;
    std::list<int>   mylist;

    mstack.push(5);
    mylist.push_back(5);
    mstack.push(17);
    mylist.push_back(17);

    std::cout << std::setw(COL_WIDTH) << "Push 5, 17" << "| "
              << "Push 5, 17\n";
    std::cout << std::setw(COL_WIDTH) << "top: " + std::to_string(mstack.top())
              << "| "
              << "back: " << mylist.back() << "\n";

    mstack.pop();
    mylist.pop_back();

    std::cout << std::setw(COL_WIDTH) << "pop()" << "| "
              << "pop_back()\n";
    std::cout << std::setw(COL_WIDTH)
              << "size: " + std::to_string(mstack.size()) << "| "
              << "size: " << mylist.size() << "\n";

    mstack.push(3);
    mylist.push_back(3);
    mstack.push(5);
    mylist.push_back(5);
    mstack.push(737);
    mylist.push_back(737);
    mstack.push(0);
    mylist.push_back(0);

    std::cout << "\nIterating through :\n";
    print_separator();
    std::cout << std::setw(COL_WIDTH) << "MutantStack" << "| "
              << "std::list\n";
    print_separator();

    MutantStack<int>::iterator mit = mstack.begin();
    std::list<int>::iterator   lit = mylist.begin();

    while (mit != mstack.end() || lit != mylist.end()) {
        std::string leftValue =
            (mit != mstack.end()) ? std::to_string(*mit++) : "";
        std::string rightValue =
            (lit != mylist.end()) ? std::to_string(*lit++) : "";

        std::cout << std::setw(COL_WIDTH) << leftValue << "| " << rightValue
                  << "\n";
    }

    std::stack<int> s(mstack);
    return 0;
}
