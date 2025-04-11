/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <lucas.lebugle@student.s19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 02:38:53 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/08 22:43:28 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

#define RED "\033[0;31m"
#define RESET "\033[0m"

class Contact {
   private:
    std::string _firstname;
    std::string _lastname;
    std::string _nickname;
    std::string _number;
    std::string _secret;

    bool _isValidName(const std::string& name) const;
    bool _isValidPhoneNumber(const std::string& name) const;

   public:
    Contact();
    Contact(const std::string& firstname, const std::string& lastname,
            const std::string& nickname, const std::string& number,
            const std::string& secret);
    // Setter methods
    bool setFirstName(const std::string& firstname);
    bool setLastName(const std::string& fullname);
    bool setNickname(const std::string& nickname);
    bool setPhoneNumber(const std::string& number);
    bool setSecret(const std::string& secret);

    // Getter methods
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getSecret() const;
};

#endif
