/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 19:50:38 by llebugle          #+#    #+#             */
/*   Updated: 2025/06/07 19:55:24 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array {
   public:
    Array() : _size(1), _elements(new T[0]()) {};
    explicit Array(unsigned int n) : _size(n), _elements(new T[n]()) {};
    ~Array() {
        delete[] _elements;
    };

    Array(const Array& other)
        : _size(other._size), _elements(new T[other._size]()) {
        for (unsigned int i = 0; i < _size; i++) {
            this->_elements[i] = other._elements[i];
        }
    };

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] this->_elements;
            this->_size = other._size;
            this->_elements = new T[this->_size]();
            for (unsigned int i = 0; i < _size; i++) {
                this->_elements[i] = other._elements[i];
            }
        }
        return *this;
    }

    const T& operator[](size_t index) const {
        if (index >= _size) {
            throw std::out_of_range("index out of range");
        }
        return _elements[index];
    }

    T& operator[](size_t index) {
        if (index >= _size) {
            throw std::out_of_range("index out of range");
        }
        return _elements[index];
    }

    unsigned int size() const {
        return _size;
    }

   private:
    unsigned int _size;
    T*           _elements;
};

#endif
