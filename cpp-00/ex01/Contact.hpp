/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <lucas.lebugle@student.s19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 02:38:53 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/08 22:17:04 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
   private:
    std::string _firstname;
    std::string _lastname;
    std::string _nickname;
    std::string _number;
    std::string _secret;

   public:
    Contact();
    Contact(const std::string& firstname, const std::string& lastname,
            const std::string& nickname, const std::string& number,
            const std::string& secret);
    // Setter methods
    void setFirstName(const std::string& firstname);
    void setLastName(const std::string& fullname);
    void setNickname(const std::string& nickname);
    void setPhoneNumber(const std::string& number);
    void setSecret(const std::string& secret);

    // Getter methods
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getSecret() const;
};

#endif
