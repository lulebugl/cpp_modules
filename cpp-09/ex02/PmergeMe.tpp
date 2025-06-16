#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include <sys/time.h>
#include <sstream>
#include <stdexcept>
#include "PmergeMe.hpp"

// === BENCHMARK IMPLEMENTATIONS ===
template <typename Container>
double PmergeMe::benchmark(const std::string& args, Container& result) {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    
    result = createContainer<Container>(args);
    FordJohnsonSort(result);
    
    gettimeofday(&end, NULL);
    return (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

template <typename Container>
double PmergeMe::benchmark(int argc, char** argv, Container& result) {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    
    result = createContainer<Container>(argc, argv);
    FordJohnsonSort(result);
    
    gettimeofday(&end, NULL);
    return (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

// === SORTING IMPLEMENTATIONS ===
template <typename Container>
void PmergeMe::FordJohnsonSort(Container& container) {
    if (container.size() <= 1) return;
    
    SortingBuffers<Container> buffers;
    // ... Ford-Johnson algorithm implementation
}

template <typename Iterator>
void PmergeMe::sortPairs(Iterator start, Iterator end, int order) {
    for (Iterator it = start; it < end; it += (order * 2)) {
        const int last_in_x = *(it + (order - 1));
        const int last_in_y = *(it + ((order * 2) - 1));
        if (last_in_x > last_in_y) {
            std::swap_ranges(it, it + order, it + order);
        }
    }
}

template <typename Container>
void PmergeMe::mergeInsert(SortingBuffers<Container>& buffers, 
                          bool has_odd_element, int order) {
    // ... implementation
}

#endif
