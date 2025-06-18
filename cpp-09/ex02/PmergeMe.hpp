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
    static double benchmark(const std::string& args, Container& result,
                            bool print = false) {
        try {
            result = createContainer(args);
            return performBenchmark(result, print);
        } catch (const std::exception& e) {
            return -1.0;
        }
    }

    static double benchmark(int argc, char* argv[], Container& result,
                            bool print = false) {
        try {
            result = createContainer(argc, argv);
            return performBenchmark(result, print);
        } catch (const std::exception& e) {
            return -1.0;
        }
    }

    /****************************************************/
    /*          TEMPLATE IMPLEMENTATION BELOW           */
    /************************************************** */

    typedef typename Container::iterator       Iterator;
    typedef typename Container::const_iterator ConstIterator;

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

   private:
    static double performBenchmark(Container& result, bool print) {
        if (result.empty()) {
            throw std::invalid_argument("Invalid arguments");
        }

        Container expected_result(result);
        std::sort(expected_result.begin(), expected_result.end());

        if (hasDuplicates(result)) {

            // IMPROVE ERROR HANDLING specifically for duplicates

            throw std::invalid_argument("Invalid arguments");
        }
        
        if (print) {
            printContainer(result, "Before:   ");
        }

        clock_t start = clock();
        FordJohnsonSort(result);
        clock_t end = clock();

        if (print) {
            printContainer(result, "After:    ");
        }

        bool is_sorted = (result == expected_result);
        std::cout << (is_sorted ? "sorted" : "Sorting failed") << std::endl;
        return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    }

    static void FordJohnsonSort(Container& cont, int order = 1) {
        if (cont.empty())
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
            ctx.odd = *(end + order - 1);

        ctx.left.insert(ctx.left.end(), end + (order * ctx.is_odd), cont.end());
        if (ctx.is_odd || !ctx.pending.empty())
            mergeInsert(ctx, cont, order);
    }

    static void sortPairs(Iterator start, Iterator end, int order) {
        for (Iterator it = start; it < end; it += (order * 2)) {
            const int last_in_x = *(it + (order - 1));
            const int last_in_y = *(it + ((order * 2) - 1));
            if (last_in_x > last_in_y) {
                std::swap_ranges(it, it + order, it + order);
            }
        }
    }

    struct JcBatchProcessor {
        size_t jc_index;  // Jacobsthal sequence index
        size_t processed;
        size_t size;  // difference between consecutive Jacobsthal numbers
        size_t batch_position;

        JcBatchProcessor()
            : jc_index(3), processed(0), size(0), batch_position(0) {}
    };

    /*
    ** Ford-Johnson merge insertion with Jacobsthal optimization:
    ** - Calculate batch sizes using diff between consecutive Jacobsthal numbers
    ** - For each element, determine search boundary using Jacobsthal sequence
    ** - Perform binary search within boundaries for optimal insertion
    ** - Insert pending elements into main chain in Jacobsthal-optimized order
    ** - Handle odd elements (pair leftover) with simple binary insertion
    ** - Reconstruct final sorted container from group representatives
    */
    static void mergeInsert(FordJohnsonContext& ctx, Container& cont,
                            int order) {
        if (ctx.pending.size() == 1) {
            binaryInsert(ctx.main, *ctx.pending.begin());
        } else if (ctx.pending.size() > 1) {
            JcBatchProcessor batch;

            while (!ctx.pending.empty()) {
                batch.size = JacobsthalNumber(batch.jc_index) -
                             JacobsthalNumber(batch.jc_index - 1);
                if (batch.size > ctx.pending.size()) {
                    batch.size = ctx.pending.size();
                }

                batch.batch_position = 0;
                while (batch.size > 0) {
                    size_t boundary_index =
                        JacobsthalNumber(batch.jc_index + batch.processed) -
                        batch.batch_position;

                    if (boundary_index <= ctx.main.size()) {
                        ctx.main.begin() + boundary_index;
                    } else {
                        ctx.main.end();
                    }

                    Iterator end = ctx.pending.begin() + batch.size - 1;
                    binaryInsert(ctx.main, *end);
                    ctx.pending.erase(end);

                    batch.size--;
                    batch.batch_position++;
                    batch.processed++;
                }
                batch.jc_index++;
            }
        }

        if (ctx.is_odd)
            binaryInsert(ctx.main, ctx.odd);
        cont = buildSortedResult(ctx, cont, order);
        printContainer(cont);
    }

    static Container buildSortedResult(FordJohnsonContext& ctx, Container cont,
                                       int order) {
        Container copy;

        for (Iterator it = ctx.main.begin(); it != ctx.main.end(); it++) {
            Iterator pos = std::find(cont.begin(), cont.end(), *it);
            if (pos == cont.end()) {
                std::cerr << "buildSortedResult: Element not found!\n";
                continue;
            }

            Iterator start_it = (pos - cont.begin() >= order - 1)
                                    ? pos - (order - 1)
                                    : cont.begin();

            copy.insert(copy.end(), start_it, pos + 1);
        }
        copy.insert(copy.end(), ctx.left.begin(), ctx.left.end());
        return copy;
    }

    static void binaryInsert(Container& target, const int& value) {
        Iterator pos = std::upper_bound(target.begin(), target.end(), value);
        target.insert(pos, value);
    }

    static long long JacobsthalNumber(size_t number) {
        return round((pow(2, number + 1) + pow(-1, number)) / 3);
    }

    static bool hasDuplicates(const Container& cont) {
        if (cont.empty()) return false;
        
        Container temp(cont);
        std::sort(temp.begin(), temp.end());
        
        typename Container::iterator new_end = std::unique(temp.begin(), temp.end());
        
        return new_end != temp.end();
    }
    
    static void printContainer(const Container& container,
                               const char*      prefix = 0) {
        if (prefix) {
            std::cout << prefix;
        }
        for (ConstIterator it = container.begin(); it != container.end();
             ++it) {
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
            if (iss.fail() || !iss.eof() || value < 0) {
                throw std::invalid_argument("Invalid arguments");
            }
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

    PmergeMe() {};
    PmergeMe(const PmergeMe& other) {
        (void)other;
    };
    PmergeMe& operator=(const PmergeMe& other) {
        (void)other;
        return *this;
    };
    ~PmergeMe() {};
};

#endif
