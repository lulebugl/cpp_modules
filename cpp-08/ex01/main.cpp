/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 02:02:16 by llebugle          #+#    #+#             */
/*   Updated: 2025/06/09 02:02:18 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Span.hpp"

void subjectTest() {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

class MultiplyBy {
   public:
    explicit MultiplyBy(int factor) : _factor(factor) {}
    int operator()(int x) const {
        return x * _factor;
    }

   private:
    int _factor;
};

int fibonacciSequence(int n) {
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;

    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

void boundarySpans() {
    Span sp = Span(4);
    sp.addNumber(-2147483648);
    sp.addNumber(2147483647);
    sp.addNumber(0);
    sp.addNumber(0);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

void fillNumbers() {
    Span even = Span(100000);
    even.fillNumbers(MultiplyBy(3));
    std::cout << even.shortestSpan() << std::endl;
    std::cout << even.longestSpan() << std::endl;

    Span fibonacci = Span(30);
    fibonacci.fillNumbers(fibonacciSequence);
    std::cout << fibonacci.shortestSpan() << std::endl;
    std::cout << fibonacci.longestSpan() << std::endl;
}

void addMultipleNumbers() {
    Span sp = Span(10);

    std::vector<int> values;
    values.push_back(-12);
    values.push_back(1);
    values.push_back(3);
    values.push_back(5);
    values.push_back(7);

    sp.addNumbers(values.begin(), values.end());

    int arr[] = {2, 4, 6, 8};
    sp.addNumbers(arr, arr + 4);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

int main() {
    try {
        subjectTest();
        std::cout << "===Boundary checks===\n";
        boundarySpans();
        std::cout << "===Filling methods===\n";
        fillNumbers();
        std::cout << "===Adding multiple numbers===\n";
        addMultipleNumbers();
    } catch (std::exception& e) {
        std::cerr << "error: " << e.what() << std::endl;
    }

    return 0;
}
