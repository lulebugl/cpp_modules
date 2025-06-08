/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:16:19 by llebugle          #+#    #+#             */
/*   Updated: 2025/06/07 15:16:21 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& x, T& y) {
    T tmp;

    tmp = x;
    x = y;
    y = tmp;
}

template <typename T>
const T& min(const T& x, const T& y) {
    return (x < y) ? x : y;
}

template <typename T>
const T& max(T& x, T& y) {
    return (x > y) ? x : y;
}

#endif