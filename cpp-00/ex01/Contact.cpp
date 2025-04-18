/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <lucas.lebugle@student.s19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:56:24 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/08 22:52:24 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#include <iostream>

Contact::Contact() {
  _firstname = "";
  _lastname = "";
  _nickname = "";
  _number = "";
  _secret = "";
}

Contact::Contact(const std::string &firstname, const std::string &lastname,
                 const std::string &nickname, const std::string &phone_number,
                 const std::string &secret) {
  _firstname = firstname;
  _lastname = lastname;
  _nickname = nickname;
  _number = phone_number;
  _secret = secret;
}

bool Contact::_isValidName(const std::string &name) const {
  if (name.empty()) {
    std::cout << RED << "Error: Field cannot be empty.\n" << RESET;
    return (false);
  }
  for (size_t i = 0; i < name.length(); i++) {
    if (!isalpha(name[i]) && name[i] != ' ' && name[i] != '-') {
      std::cout << RED
                << "Error: Names can only contain letters, spaces and "
                   "hyphens.\n"
                << RESET;
      return (false);
    }
  }
  return true;
}

bool Contact::_isValidPhoneNumber(const std::string &number) const {
  if (number.empty()) {
    std::cout << RED << "Error: Field cannot be empty.\n" << RESET;
    return (false);
  }
  for (size_t i = 0; i < number.length(); i++) {
    if (!isdigit(number[i])) {
      std::cout << RED << "Error: Phone number can only contain digits.\n"
                << RESET;
      return (false);
    }
  }
  return true;
}

std::string trim_spaces(std::string str) {
  while (!str.empty() && isspace(str[0])) {
    str.erase(0, 1);
  }
  while (!str.empty() && isspace(str[str.length() - 1])) {
    str.erase(str.length() - 1, str.length());
  }
  size_t i = 0;
  while (i < str.length()) {
    if (isspace(str[i]) && i + 1 < str.length() && isspace(str[i + 1])) {
      str.erase(i, 1);
    } else {
      i++;
    }
  }
  return str;
}

bool Contact::setFirstName(const std::string &firstname) {
  std::string trimmed = trim_spaces(firstname);
  if (!_isValidName(trimmed)) return (false);
  _firstname = trimmed;
  return (true);
}

bool Contact::setLastName(const std::string &lastname) {
  std::string trimmed = trim_spaces(lastname);
  if (!_isValidName(trimmed)) return (false);
  _lastname = trimmed;
  return (true);
}

bool Contact::setNickname(const std::string &nickname) {
  std::string trimmed = trim_spaces(nickname);
  if (!_isValidName(trimmed)) return (false);
  _nickname = trimmed;
  return (true);
}

bool Contact::setPhoneNumber(const std::string &number) {
  std::string trimmed = trim_spaces(number);
  if (!_isValidPhoneNumber(trimmed)) return (false);
  _number = trimmed;
  return (true);
}

bool Contact::setSecret(const std::string &secret) {
  std::string trimmed = trim_spaces(secret);
  if (trimmed.empty()) {
    std::cout << RED << "Error: Field cannot be empty.\n" << RESET;
    return (false);
  }
  _secret = trimmed;
  return (true);
}

std::string Contact::getFirstName() const { return (_firstname); }

std::string Contact::getLastName() const { return (_lastname); }

std::string Contact::getNickname() const { return _nickname; }

std::string Contact::getPhoneNumber() const { return _number; }

std::string Contact::getSecret() const { return _secret; }
