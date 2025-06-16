/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:46:19 by llebugle          #+#    #+#             */
/*   Updated: 2025/06/15 18:46:19 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <sys/time.h>

#include <iostream>
#include <sstream>
#include <string>

class PmergeMe {
   public:
    typedef std::vector<int>::iterator       VecIterator;
    typedef std::vector<int>::const_iterator VecConstIterator;
    typedef std::deque<int>::iterator        DequeIterator;
    typedef std::deque<int>::const_iterator  DequeConstIterator;

    static double benchmark(const std::string& args, std::vector<int>& result);
    static double benchmark(int ac, char** argv, std::vector<int>& result);
    static double benchmark(const std::string& args, std::deque<int>& result);
    static double benchmark(int ac, char** argv, std::deque<int>& result);

    static void FordJohnsonSort(std::vector<int>& vec);
    static void FordJohnsonSort(std::deque<int>& vec);
    static void sort(std::deque<int>& deque);
    // static void mergeInsert(std::vector<int>& vec);

    static long long JacobsthalNumber(size_t number);

   private:
    template <typename Container>
    struct SortingBuffers {
        Container main;
        Container pending;
        Container left;
    };
    static void sortPairs(VecIterator start, VecIterator end, int order);
    static void mergeInsert(std::vector<int>& main, std::vector<int>& pend,
                            int odd, std::vector<int>& left,
                            std::vector<int>& vec, bool is_odd, int order);
    static void mergeInsert(SortingBuffers<std::vector<int> > test, int odd,
                            std::vector<int>& vec, bool is_odd, int order);
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    /*  template implemation below  */
   public:
   private:
};

/* template implementation below */

template <typename Container>
void printContainer(const Container& container) {
    for (typename Container::const_iterator it = container.begin();
         it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

template <typename Container>
Container createContainer(int argc, char** argv) {
    Container int_container;

    for (int i = 1; i < argc; ++i) {
        std::istringstream iss(argv[i]);
        int                value = 0;

        iss >> value;
        if (iss.fail() || !iss.eof() || value < 0)
            throw std::invalid_argument("Failed to parse argument: " +
                                        static_cast<std::string>(argv[i]));
        int_container.push_back(value);
    }

    return int_container;
}

template <typename Container>
Container createContainer(const std::string& str) {
    Container int_container;

    std::istringstream iss(str);
    int                value = 0;

    while (iss >> value) {
        if (iss.fail() || value < 0)
            throw std::invalid_argument("Failed to parse argument");
        int_container.push_back(value);
    }

    return int_container;
}
#endif
