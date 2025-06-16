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

// use deque and vector
int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Usage: ./PmergeMe 'sequence of positive integers'\n";
        return 0;
    }

    try {
        std::vector<int> vec;
        std::deque<int>  deque;

        double time_vec = 0;
        double time_deque = 0;

        if (argc == 2) {
            time_vec = PmergeMe::benchmark(argv[1], vec);
            time_deque = PmergeMe::benchmark(argv[1], deque);
        } else {
            time_vec = PmergeMe::benchmark(argc, argv, vec);
            time_deque = PmergeMe::benchmark(argc, argv, deque);
        }

        std::cout << "Time to process a range of " << vec.size()
                  << " elements with std::vector : " << time_vec << " ms\n";
        std::cout << "Time to process a range of " << deque.size()
                  << " elements with std::deque  : " << time_deque << " ms\n";
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
