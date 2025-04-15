/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:22:41 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/15 19:22:42 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <fstream>
#include <string>

class Sed {
   private:
    std::string   _find;
    std::string   _replace;
    // std::stringstream _buffer;

   public:
    Sed(const std::string& find, const std::string& replace);
    ~Sed();
};

#endif
