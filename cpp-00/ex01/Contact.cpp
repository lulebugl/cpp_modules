/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <lucas.lebugle@student.s19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:56:24 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/08 22:16:52 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
    _firstname = "";
    _lastname = "";
    _nickname = "";
    _number = "";
    _secret = "";
}

Contact::Contact(const std::string& firstname, const std::string& lastname,
                 const std::string& nickname, const std::string& phone_number,
                 const std::string& secret) {
    _firstname = firstname;
    _lastname = lastname;
    _nickname = nickname;
    _number = phone_number;
    _secret = secret;
}
