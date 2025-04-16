/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:09:03 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/16 12:09:04 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>

const char* RESET = "\033[0m";
const char* GREEN = "\033[32m";   // Debug color
const char* BLUE = "\033[34m";    // Info color
const char* YELLOW = "\033[33m";  // Warning color
const char* RED = "\033[31m";     // Error color
const char* PURPLE = "\033[36m";  // Special color

const char* Harl::_levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl() {
  _complainFunctions[0] = &Harl::_debug;
  _complainFunctions[1] = &Harl::_info;
  _complainFunctions[2] = &Harl::_warning;
  _complainFunctions[3] = &Harl::_error;
}

void Harl::_debug(void) {
  std::cout << GREEN << "[DEBUG] " << RESET;
  std::cout << "I love having extra bacon for my "
               "7XL-double-cheese-triple-pickle-specialketchup burger. I "
               "really do!\n";
}

void Harl::_info(void) {
  std::cout << BLUE << "[INFO] " << RESET;
  std::cout << "I cannot believe adding extra bacon costs more money. "
               "Unbelievable!\n";
}

void Harl::_warning(void) {
  std::cout << YELLOW << "[WARNING] " << RESET;
  std::cout
      << "This is a warning! I think I deserve some extra bacon for free.\n";
}

void Harl::_error(void) {
  std::cout << RED << "[ERROR] " << RESET;
  std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level) {
  for (int i = 0; i < 4; i++) {
    if (level == _levels[i]) {
      (this->*_complainFunctions[i])();
      return;
    }
  }
  std::cout << PURPLE << "[UNKNOWN LEVEL] " << RESET;
  std::cout << "What are you saying! There's no \"" << level << "\" level!\n";
}
