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
#include <vector>

template <typename Container>
class PmergeMe {
   public:
    typedef typename Container::iterator       iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::value_type     value_type;
    // typedef typename Container::size_type      size_type;
    // static double benchmark(const std::string& args, std::vector<int>&
    // result); static double benchmark(int ac, char** argv, std::vector<int>&
    // result); static double benchmark(const std::string& args,
    // std::deque<int>& result); static double benchmark(int ac, char** argv,
    // std::deque<int>& result);

    // static void FordJohnsonSort(std::vector<int>& vec);
    // static void FordJohnsonSort(std::deque<int>& vec);
    // static void sort(std::deque<int>& deque);
    // static void mergeInsert(std::vector<int>& vec);

    // static long long JacobsthalNumber(size_t number);

   private:
    typedef typename Container::iterator Iterator;

    struct SortingBuffers {
        Container main;
        Container pending;
        Container left;
    };
    // static void sortPairs(Iterator start, Iterator end, int order);
    // static void mergeInsert(std::vector<int>& main, std::vector<int>& pend,
    //                         int odd, std::vector<int>& left,
    //                         std::vector<int>& vec, bool is_odd, int order);
    // static void mergeInsert(SortingBuffers<std::vector<int> > test, int odd,
    //                         std::vector<int>& vec, bool is_odd, int order);

    /****************************************************/
    /*          TEMPLATE IMPLEMENTATION BELOW           */
    /************************************************** */

   public:
    static double benchmark(const std::string& args, Container& result) {
        result = createContainer(args);

        std::cout << "Before:   ";
        printContainer(result);
        clock_t start = clock();

        // FordJohnsonSort(result);

        clock_t end = clock();
        std::cout << "After:    ";
        printContainer(result);
        return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    }
    
    static double benchmark(int argc, char* argv[], Container& result) {
        result = createContainer(argc, argv);

        std::cout << "Before:   ";
        printContainer(result);
        clock_t start = clock();

        // FordJohnsonSort(result);

        clock_t end = clock();
        std::cout << "After:    ";
        printContainer(result);
        return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    }

   private:
    // void FordJohnsonSort(Container& vec) {
    //     static int order = 1;
    //     int        total_units = vec.size() / order;

    //     if (total_units < 2)
    //         return;

    //     bool                         is_odd = total_units % 2 == 1;
    //     typename Container::iterator end =
    //         vec.begin() + ((order * total_units) - (is_odd * order));

    //     sortPairs(vec.begin(), end, order);

    //     order *= 2;
    //     FordJohnsonSort(vec);
    //     order /= 2;

    //     Container main;
    //     Container pend;
    //     Container left;
    //     int       odd = 0;

    //     main.push_back(*(vec.begin() + order - 1));
    //     main.push_back(*(vec.begin() + order * 2 - 1));

    //     for (Iterator it = vec.begin() + order * 2; it < end; it += order) {
    //         pend.push_back(*(it + order - 1));
    //         it += order;
    //         main.push_back(*(it + order - 1));
    //     }

    //     if (is_odd)
    //         odd = *(end + order - 1);  // Save the odd pair if any

    //     left.insert(left.end(), end + (order * is_odd),
    //                 vec.end());  // Save the leftover elements that cannot
    //                 form
    //                              // pairs on their own.

    //     // Perform insertion.
    //     if (is_odd || !pend.empty())
    //         mergeInsert(main, pend, odd, left, vec, is_odd, order);
    //     std::cout << "\n";
    //     printContainer(vec);
    // }

    static void printContainer(const Container& container) {
        for (typename Container::const_iterator it = container.begin();
             it != container.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "\n";
    }

    static Container createContainer(int argc, char** argv) {
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

    static Container createContainer(const std::string& str) {
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
};

// void mergeInsert(std::vector<int>& main, std::vector<int>& pend, int odd,
//                  std::vector<int>& left, std::vector<int>& vec, bool is_odd,
//                  int order) {
//     Iterator end;

//     // If 'pend' has only one element, sort using normal binary search.
//     if (pend.size() == 1) {
//         end = std::upper_bound(main.begin(), main.end(), *pend.begin());
//         main.insert(end, *pend.begin());
//     } else if (pend.size() > 1) {
//         // Process 'pend' using the Jacobsthal sequence to determine
//         insertion
//         // indices.
//         size_t jc = 3;  // Start with the 3rd Jacobsthal number
//         size_t count = 0;
//         size_t idx;
//         size_t decrease;

//         // Sort 'pend' into 'main' using binary search 'upper_bound' with
//         // Jacobsthal as optimization.
//         while (!pend.empty()) {
//             idx = JacobsthalNumber(jc) - JacobsthalNumber(jc - 1);
//             if (idx > pend.size())
//                 idx = pend.size();

//             decrease = 0;
//             while (idx) {
//                 // Determine the insertion point based on the
//                 JacobsthalNumber
//                 // index and insert the element.
//                 end = main.begin();
//                 if (JacobsthalNumber(jc + count) - decrease <= main.size())
//                     end =
//                         main.begin() + JacobsthalNumber(jc + count) -
//                         decrease;
//                 else
//                     end = main.end();
//                 // Binary sort
//                 end = std::upper_bound(main.begin(), end,
//                                        *(pend.begin() + idx - 1));
//                 main.insert(end, *(pend.begin() + idx - 1));
//                 pend.erase(pend.begin() + idx - 1);

//                 idx--;
//                 decrease++;
//                 count++;
//             }
//             jc++;
//         }
//     }

//     std::vector<int> yaslam;

//     // If there is an odd element, sort it using normal binary search.
//     if (is_odd) {
//         end = std::upper_bound(main.begin(), main.end(), odd);
//         main.insert(end, odd);
//     }
//     // Rebuild 'main' based on the sorted last elements.
//     for (Iterator i = main.begin(); i != main.end(); i++) {
//         Iterator it = std::find(vec.begin(), vec.end(), *i);
//         yaslam.insert(yaslam.end(), it - (order - 1), it + 1);
//     }
//     yaslam.insert(yaslam.end(), left.begin(), left.end());
//     vec = yaslam;
// }

#endif
