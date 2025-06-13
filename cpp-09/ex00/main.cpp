/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:36:50 by llebugle          #+#    #+#             */
/*   Updated: 2025/06/10 18:36:51 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: ./btc input-data\n";
        return 0;
    }

    BitcoinExchange btc;

    if (!btc.loadDatabase("data.csv")) {
        return 1;
    }

    if (!btc.loadWallet(argv[1])) {
        return 1;
    }

    return 0;
}
