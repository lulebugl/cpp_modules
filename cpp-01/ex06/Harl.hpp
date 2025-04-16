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
  void _debug(void);
  void _info(void);
  void _warning(void);
  void _error(void);

  typedef void (Harl::*MemberFunctionPtr)(void);
  MemberFunctionPtr _complainFunctions[4];

 public:
  Harl();

  enum LevelsEnum { DEBUG, INFO, WARNING, ERROR, UNKNOW };

  LevelsEnum getLevel(const std::string& level);
  void       complain(std::string level);
};

#endif
