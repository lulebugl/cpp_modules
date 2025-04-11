/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <lucas.lebugle@student.s19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:38:01 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/08 22:07:33 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {
   private:
    Contact _contact[8];

   public:
    PhoneBook();
    void    addContact(int index);
    Contact getContact(int index) const;
    void    displayContactList() const;
    void    displayContactInfo(const Contact &contact) const;
};

#endif
