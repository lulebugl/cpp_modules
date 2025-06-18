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

#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

template <typename Container>
class PmergeMe {
   public:
    typedef typename Container::iterator       iterator;
    typedef typename Container::const_iterator const_iterator;

    // typedef typename Container::value_type     value_type;
    // typedef typename Container::size_type      size_type;

    // static void FordJohnsonSort(std::vector<int>& vec);
    // static void FordJohnsonSort(std::deque<int>& vec);
    // static void sort(std::deque<int>& deque);
    // static void mergeInsert(std::vector<int>& vec);

    // static long long JacobsthalNumber(size_t number);

   private:
    typedef typename Container::iterator Iterator;

    struct FordJohnsonContext {
        // Algorithm state
        bool is_odd;
        int  odd;
        int  total_units;

        // temporary containers
        Container main;
        Container pending;
        Container left;
        FordJohnsonContext() : is_odd(false), odd(0), total_units(0) {};
    };

    /****************************************************/
    /*          TEMPLATE IMPLEMENTATION BELOW           */
    /************************************************** */

   public:
    static double benchmark(const std::string& args, Container& result) {
        result = createContainer(args);

        if (result.empty())
            return 0;
        std::cout << "Before:   ";
        printContainer(result);
        clock_t start = clock();

        FordJohnsonSort(result);

        clock_t end = clock();
        std::cout << "After:    ";
        printContainer(result);
        return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    }

    static double benchmark(int argc, char* argv[], Container& result) {
        result = createContainer(argc, argv);

        Container sorted(result);
        std::sort(sorted.begin(), sorted.end());

        if (result.empty())
            return 0;

        // std::cout << "Before:   ";
        // printContainer(sorted);
        clock_t start = clock();

        FordJohnsonSort(result);

        clock_t end = clock();
        // std::cout << "After:    ";
        // printContainer(result);
        std::cout << ((result == sorted) ? "Sorted" : "Not sorted") << "\n";

        return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    }

   private:
    static void sortPairs(Iterator start, Iterator end, int order) {
        for (Iterator it = start; it < end; it += (order * 2)) {
            const int last_in_x = *(it + (order - 1));
            const int last_in_y = *(it + ((order * 2) - 1));
            if (last_in_x > last_in_y) {
                std::swap_ranges(it, it + order, it + order);
            }
        }
    }

    static void FordJohnsonSort(Container& cont, int order = 1) {
        if (cont.empty() || order <= 0)
            return;

        FordJohnsonContext ctx;

        ctx.total_units = cont.size() / order;

        if (ctx.total_units < 2)
            return;

        ctx.is_odd = ctx.total_units % 2 == 1;
        Iterator end =
            cont.begin() + ((order * ctx.total_units) - (ctx.is_odd * order));

        sortPairs(cont.begin(), end, order);

        FordJohnsonSort(cont, order * 2);

        ctx.main.push_back(*(cont.begin() + order - 1));
        ctx.main.push_back(*(cont.begin() + order * 2 - 1));

        for (Iterator it = cont.begin() + order * 2; it < end; it += order) {
            ctx.pending.push_back(*(it + order - 1));
            it += order;
            ctx.main.push_back(*(it + order - 1));
        }

        if (ctx.is_odd)
            ctx.odd = *(end + order - 1);  // Save the odd pair if any

        ctx.left.insert(ctx.left.end(), end + (order * ctx.is_odd),
                        cont.end());  // Save the leftover elements that cannot
                                      // form pairs on their own.

        if (ctx.is_odd || !ctx.pending.empty())
            mergeInsert(ctx, cont, order);
    }

    static void mergeInsert(FordJohnsonContext& ctx, Container& cont,
                            int order) {
        Iterator end;

        // If 'pend' has only one element, sort using normal binary search.
        if (ctx.pending.size() == 1) {
            end = std::upper_bound(ctx.main.begin(), ctx.main.end(),
                                   *ctx.pending.begin());
            ctx.main.insert(end, *ctx.pending.begin());
        } else if (ctx.pending.size() > 1) {
            // Process 'pend' using the Jacobsthal sequence to determine
            // insertion
            // indices.
            size_t jc = 3;  // Start with the 3rd Jacobsthal number
            size_t count = 0;
            size_t idx;
            size_t decrease;

            // Sort 'pend' into 'main' using binary search 'upper_bound' with
            // Jacobsthal as optimization.
            while (!ctx.pending.empty()) {
                idx = JacobsthalNumber(jc) - JacobsthalNumber(jc - 1);
                if (idx > ctx.pending.size())
                    idx = ctx.pending.size();

                decrease = 0;
                while (idx) {
                    // Determine the insertion point based on the
                    // JacobsthalNumber
                    // index and insert the element.
                    end = ctx.main.begin();
                    if (JacobsthalNumber(jc + count) - decrease <=
                        ctx.main.size())
                        end = ctx.main.begin() + JacobsthalNumber(jc + count) -
                              decrease;
                    else
                        end = ctx.main.end();
                    // Binary sort
                    end = std::upper_bound(ctx.main.begin(), end,
                                           *(ctx.pending.begin() + idx - 1));
                    ctx.main.insert(end, *(ctx.pending.begin() + idx - 1));
                    ctx.pending.erase(ctx.pending.begin() + idx - 1);

                    idx--;
                    decrease++;
                    count++;
                }
                jc++;
            }
        }

        std::vector<int> copy;
        copy.reserve(cont.size());

        // If there is an odd element, sort it using normal binary search.
        if (ctx.is_odd) {
            end = std::upper_bound(ctx.main.begin(), ctx.main.end(), ctx.odd);
            ctx.main.insert(end, ctx.odd);
        }
        // Rebuild 'main' based on the sorted last elements.
        for (Iterator i = ctx.main.begin(); i != ctx.main.end(); i++) {
            Iterator it = std::find(cont.begin(), cont.end(), *i);
            if (it == cont.end()) {
                std::cerr << "Error: Element not found!" << std::endl;
                continue;
            }

            // Safe bounds checking
            Iterator start_it = (it - cont.begin() >= order - 1)
                                    ? it - (order - 1)
                                    : cont.begin();
            Iterator end_it = it + 1;

            copy.insert(copy.end(), start_it, end_it);
        }
        copy.insert(copy.end(), ctx.left.begin(), ctx.left.end());

        // cont = copy;
        Iterator                   container_it = cont.begin();
        std::vector<int>::iterator copy_it = copy.begin();
        while (copy_it != copy.end()) {
            *container_it = *copy_it;
            container_it++;
            copy_it++;
        }
    }

    static void binaryInsert(Container& target, const int& value) {
        Iterator pos = std::upper_bound(target.begin(), target.end(), value);
        target.insert(pos, value);
    }

    static long long JacobsthalNumber(size_t number) {
        return round((pow(2, number + 1) + pow(-1, number)) / 3);
    }

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

    // PmergeMe() {};
    // PmergeMe(const PmergeMe& other) {
    //     (void)other;
    // };
    // PmergeMe& operator=(const PmergeMe& other) {
    //     (void)other;
    //     return *this;
    // };
    // ~PmergeMe() {};
};

#endif
