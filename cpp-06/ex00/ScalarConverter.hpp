/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:57:29 by llebugle          #+#    #+#             */
/*   Updated: 2025/06/02 17:57:29 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter
{
    public:
        static void convert(const std::string& literal);
        
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();
};

#endif
