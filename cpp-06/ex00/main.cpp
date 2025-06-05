/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:12:50 by llebugle          #+#    #+#             */
/*   Updated: 2025/06/02 18:12:51 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main(int ac, char **av) {

    if (ac < 2) {
        return 0;
    } else if (ac > 2) {
        std::cout << "Usage: ./convert arg" << std::endl;
        return 0;
    }
    try {
        ScalarConverter::convert(av[1]);
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
