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

    std::vector<int> vec;
    std::deque<int>  deque;

    double time_vec = 0;
    double time_deque = 0;

    if (argc == 2) {
        time_vec = PmergeMe<std::vector<int> >::benchmark(argv[1], vec, true);
        time_deque = PmergeMe<std::deque<int> >::benchmark(argv[1], deque);
    } else {
        time_vec =
            PmergeMe<std::vector<int> >::benchmark(argc, argv, vec, true);
        time_deque = PmergeMe<std::deque<int> >::benchmark(argc, argv, deque);
    }

    if (time_vec < 0.0 || time_deque < 0.0) {
        std::cerr << "Error\n";
        return 1;
    }

    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << time_vec << " ms\n";
    std::cout << "Time to process a range of " << deque.size()
              << " elements with std::deque  : " << time_deque << " ms\n";

    return 0;
}
