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

void Harl::debug(void) {
  std::cout
      << "I love having extra bacon for my "
         "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
}

void Harl::info(void) {
  std::cout
      << "I cannot believe adding extra bacon costs more money. You didn’t put"
         "enough bacon in my burger! If you did, I wouldn’t be asking for "
         "more!";
}

void Harl::warning(void) {
  std::cout << "I think I deserve to have some extra bacon for free. I’ve been "
               "coming for"
               "years, whereas you started working here just last month.";
}

void Harl::error(void) {
  std::cerr << "This is unacceptable! I want to speak to the manager now.";
}

void Harl::complain(std::string level) {
    
}