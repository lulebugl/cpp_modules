/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 02:02:01 by llebugle          #+#    #+#             */
/*   Updated: 2025/06/09 02:02:01 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <limits>
#include <stdexcept>
#include <vector>

Span::Span() : _size(1) {}

Span::Span(unsigned int n) : _size(n > 0 ? n : 1) {
    _numbers.reserve(_size);
}

Span::Span(const Span& other) : _size(other._size), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        this->_size = other._size;
        this->_numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int& number) {
    if (Span::isFull()) {
        throw std::out_of_range("Span is full");
    }
    _numbers.push_back(number);
}

void Span::addNumber(const int& number) {
    if (Span::isFull()) {
        throw std::out_of_range("Span is full");
    }
    _numbers.push_back(number);
}

std::size_t Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw std::logic_error("Cannot find span with fewer than 2 numbers");
    }

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    size_t span = std::numeric_limits<std::size_t>::max();

    for (size_t i = 0; i < sorted.size() - 1; ++i) {
        std::size_t curr = (static_cast<std::size_t>(sorted[i + 1]) -
                            static_cast<std::size_t>(sorted[i]));
        span = std::min(span, curr);
    }

    return span;
}

std::size_t Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw std::logic_error("Cannot find span with fewer than 2 numbers");
    }

    std::vector<int>::const_iterator min_it =
        std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator max_it =
        std::max_element(_numbers.begin(), _numbers.end());

    return (static_cast<std::size_t>(*max_it) -
            static_cast<std::size_t>(*min_it));
}
