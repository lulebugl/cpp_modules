/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:08:45 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/16 12:08:47 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Harl.hpp"

int main(int ac, char **av) {
  Harl harl;
  bool interactive = (ac == 2) && ((std::string)av[1] == "-i");
  if (ac == 2 && interactive) {
    std::string cmdInput;
    while (true) {
      std::cin.clear();
      std::cout << "LEVEL: ";
      if (!(std::getline(std::cin, cmdInput))) {
        if (std::cin.eof()) return 0;
        continue;
      }
      if (cmdInput.empty()) continue;
      if (cmdInput == "EXIT" || cmdInput == "exit") return 0;
      harl.complain(cmdInput);
    };
    return 0;
  } else if (ac == 2) {
    std::string level = av[1];
    harl.complain(level);
  } else {
    std::cout << "Usage: ./Harl" << std::endl;
    std::cout << "       ./Harl -i (for interactive mode)" << std::endl;
  }
  return 0;
}
