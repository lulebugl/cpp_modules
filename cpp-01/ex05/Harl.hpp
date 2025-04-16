/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:09:16 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/16 12:09:18 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
 private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);

 public:
  void complain(std::string level);
};

#endif
