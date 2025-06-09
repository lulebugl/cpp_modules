/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:46:19 by llebugle          #+#    #+#             */
/*   Updated: 2025/06/07 15:46:20 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename Function>
void iter(T array[], size_t n, Function iterator) {
    for (size_t i = 0; i < n; i++) {
        iterator(array[i]);
    }
}

template <typename T>
void iter(T array[], size_t n, void (*iterator)(T&)) {
    if (!iterator)
        return;
    for (size_t i = 0; i < n; i++) {
        iterator(array[i]);
    }
}

template <typename T>
void iter(T array[], size_t n, void (*iterator)(const T&)) {
    if (!iterator)
        return;
    for (size_t i = 0; i < n; i++) {
        iterator(array[i]);
    }
}

#endif
