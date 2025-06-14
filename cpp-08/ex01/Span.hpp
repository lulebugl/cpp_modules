/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 02:02:01 by llebugle          #+#    #+#             */
/*   Updated: 2025/06/09 02:02:01 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <cstddef>
#include <stdexcept>
#include <vector>

class Span {
   public:
    explicit Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    bool isFull() const {
        return _numbers.size() >= _size;
    }

    void addNumber(int& number);
    void addNumber(const int& number);
    std::vector<int> getNumbers() const;

    std::size_t shortestSpan() const;
    std::size_t longestSpan() const;

   private:
    Span();
    unsigned int     _size;
    std::vector<int> _numbers;

    // template implementation below
   public:
    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end) {
        size_t count = std::distance(begin, end);
        if (_numbers.size() + count > _size) {
            throw std::out_of_range("Cannot add this many numbers to the Span");
        }
        _numbers.insert(_numbers.end(), begin, end);
    }

    template <typename Iterator>
    void addNumbers(Iterator start, Iterator begin, Iterator end) {
        size_t count = std::distance(begin, end);
        if (_numbers.size() + count > _size) {
            throw std::out_of_range("Cannot add this many numbers to the Span");
        }
        _numbers.insert(start, begin, end);
    }

    template <typename Generator>
    void fillNumbers(Generator generate) {
        if (isFull()) {
            throw std::out_of_range("Span is full");
        }

        size_t remaining = _size - _numbers.size();

        for (size_t i = 0; i < remaining; i++) {
            _numbers.push_back(generate(static_cast<int>(i)));
        }
    }
};

#endif
