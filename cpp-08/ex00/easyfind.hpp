/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 21:48:32 by llebugle          #+#    #+#             */
/*   Updated: 2025/06/08 21:48:33 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int to_find) {
    return std::find(container.begin(), container.end(), to_find);
}

template <typename T>
typename T::const_iterator easyfind(const T& container, int to_find) {
    return std::find(container.begin(), container.end(), to_find);
}

#endif
