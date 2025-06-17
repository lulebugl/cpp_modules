long long PmergeMe::JacobsthalNumber(size_t number) {
    return round((pow(2, number + 1) + pow(-1, number)) / 3);
}

void PmergeMe::mergeInsert(std::vector<int>& main, std::vector<int>& pend,
                           int odd, std::vector<int>& left,
                           std::vector<int>& vec, bool is_odd, int order) {
    VecIterator end;

    // If 'pend' has only one element, sort using normal binary search.
    if (pend.size() == 1) {
        end = std::upper_bound(main.begin(), main.end(), *pend.begin());
        main.insert(end, *pend.begin());
    } else if (pend.size() > 1) {
        // Process 'pend' using the Jacobsthal sequence to determine insertion
        // indices.
        size_t jc = 3;  // Start with the 3rd Jacobsthal number
        size_t count = 0;
        size_t idx;
        size_t decrease;

        // Sort 'pend' into 'main' using binary search 'upper_bound' with
        // Jacobsthal as optimization.
        while (!pend.empty()) {
            idx = JacobsthalNumber(jc) - JacobsthalNumber(jc - 1);
            if (idx > pend.size())
                idx = pend.size();

            decrease = 0;
            while (idx) {
                // Determine the insertion point based on the JacobsthalNumber
                // index and insert the element.
                end = main.begin();
                if (JacobsthalNumber(jc + count) - decrease <= main.size())
                    end =
                        main.begin() + JacobsthalNumber(jc + count) - decrease;
                else
                    end = main.end();
                // Binary sort
                end = std::upper_bound(main.begin(), end,
                                       *(pend.begin() + idx - 1));
                main.insert(end, *(pend.begin() + idx - 1));
                pend.erase(pend.begin() + idx - 1);

                idx--;
                decrease++;
                count++;
            }
            jc++;
        }
    }

    std::vector<int> yaslam;

    // If there is an odd element, sort it using normal binary search.
    if (is_odd) {
        end = std::upper_bound(main.begin(), main.end(), odd);
        main.insert(end, odd);
    }
    // Rebuild 'main' based on the sorted last elements.
    for (VecIterator i = main.begin(); i != main.end(); i++) {
        VecIterator it = std::find(vec.begin(), vec.end(), *i);
        yaslam.insert(yaslam.end(), it - (order - 1), it + 1);
    }
    yaslam.insert(yaslam.end(), left.begin(), left.end());
    vec = yaslam;
}

void PmergeMe::FordJohnsonSort(std::vector<int>& vec) {
    static int order = 1;
    int        total_units = vec.size() / order;

    if (total_units < 2)
        return;

    bool        is_odd = total_units % 2 == 1;
    VecIterator end = vec.begin() + ((order * total_units) - (is_odd * order));

    sortPairs(vec.begin(), end, order);

    order *= 2;
    FordJohnsonSort(vec);
    order /= 2;

    std::vector<int> main;
    std::vector<int> pend;
    std::vector<int> left;
    int              odd = 0;

    main.push_back(*(vec.begin() + order - 1));
    main.push_back(*(vec.begin() + order * 2 - 1));

    for (VecIterator it = vec.begin() + order * 2; it < end; it += order) {
        pend.push_back(*(it + order - 1));
        it += order;
        main.push_back(*(it + order - 1));
    }

    if (is_odd)
        odd = *(end + order - 1);  // Save the odd pair if any

    left.insert(left.end(), end + (order * is_odd),
                vec.end());  // Save the leftover elements that cannot form
                             // pairs on their own.

    // Perform insertion.
    if (is_odd || !pend.empty())
        mergeInsert(main, pend, odd, left, vec, is_odd, order);
    std::cout << std::endl;
    printContainer(vec);
}

// double PmergeMe::benchmark(const std::string& args, std::vector<int>& result) {
//     result = createContainer<std::vector<int> >(args);

//     std::cout << "Before:   ";
//     printContainer(result);
//     std::clock_t start = std::clock();

//     FordJohnsonSort(result);

//     std::clock_t end = std::clock();
//     std::cout << "After:    ";
//     printContainer(result);
//     return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
// }

// double PmergeMe::benchmark(int argc, char** argv, std::vector<int>& result) {
//     result = createContainer<std::vector<int> >(argc, argv);

//     std::cout << "Before:   ";
//     printContainer(result);
//     std::clock_t start = std::clock();

//     FordJohnsonSort(result);

//     std::clock_t end = std::clock();
//     std::cout << "After:    ";
//     printContainer(result);
//     return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
// }

// double PmergeMe::benchmark(const std::string& args, std::deque<int>& result) {
//     std::clock_t start = std::clock();

//     result = createContainer<std::deque<int> >(args);

//     std::clock_t end = std::clock();
//     return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
// }

// double PmergeMe::benchmark(int argc, char** argv, std::deque<int>& result) {
//     std::clock_t start = std::clock();

//     result = createContainer<std::deque<int> >(argc, argv);

//     std::clock_t end = std::clock();
//     return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
// }
