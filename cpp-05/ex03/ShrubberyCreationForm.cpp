/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:14:51 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/30 13:14:51 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "Logger.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyForm", 145, 137, target) {
    LOG_DEBUG("Form constructor called");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other) {
    LOG_DEBUG("ShrubberyCreationForm Copy constructor called");
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& other) {
    LOG_DEBUG("ShrubberyCreationForm Assignment operator called");
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    LOG_DEBUG("ShrubberyCreationForm Destructor called");
}

void ShrubberyCreationForm::beExecuted() const {
    std::ofstream out;
    
    out.open(this->getTarget() + "_shrubbery");
    if (!out.is_open()) {
        throw std::runtime_error("Failed to open shrubbery output file");
    }
    
    out << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⢀⡀⠀⠀⢀⣻⣿⣧⣴⡿⢿⣦⣀⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
             "⠀⠀⠀⠀⠀⠀⠀⣠⣦⣾⣿⣿⣷⣶⣶⡿⠿⣟⠛⠶⠾⢻⡾⢿⣶⢾⣿⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
             "⠀⠀⠀⠀⠀⢰⣾⣿⡿⠿⠉⠀⠉⠳⠉⠉⠀⠐⠂⢀⠐⠀⠀⠈⠁⠒⠋⡽⣿⡗⠀⠀⠀⠀⠰⠀⠀⠀\n"
             "⠀⠀⠀⠀⠀⠘⠿⣿⣁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⡀⠀⡀⠀⣀⠰⣎⣿⣿⣄⡀⠀⠀⠀⠀⠀\n"
             "⠀⡀⠀⠀⠀⢠⣾⡿⢤⡤⠀⠀⠐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠃⠠⢤⠀⠀⠼⠛⣿⣇⢀⡀⠀⠀⠀\n"
             "⠀⠇⢀⣀⣶⣾⣿⠅⠈⠉⠁⠤⠀⠠⠀⠀⠀⡀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣷⣦⠀⠀\n"
             "⠀⠀⠈⢿⣿⣿⡟⠀⠆⠈⠁⣀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⠀⠀⠀⠀⠂⠀⠀⠀⡀⠾⢹⡏⠁⠀⠀\n"
             "⠀⠀⠀⠀⢀⣿⣿⠇⠀⠐⠂⠐⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡄⣼⣿⡇⠀⠀⠀\n"
             "⠀⠀⠘⣿⣿⣿⣱⡾⠃⠀⢂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠤⠀⠀⠀⠀⠀⠃⡀⠁⣡⣾⣇⠀⠀⠀\n"
             "⠀⠀⢸⣿⣿⣿⣉⡡⠶⠁⠼⠁⠀⠠⠄⠀⠀⠀⠀⢀⠀⠀⠀⠀⠄⠁⠄⠁⠄⡀⠀⢨⣹⡿⠿⠀⠀⠀\n"
             "⠀⠀⠀⠙⠻⣿⣿⣧⣰⣷⣶⣄⠁⠴⠆⢀⡐⠒⠐⠀⠀⠀⠀⠀⠀⡀⠂⠀⠀⡀⠒⣾⡟⠓⠀⠀⠀⠀\n"
             "⠀⠀⠀⠀⠈⢻⡟⢻⣿⣿⣿⣿⡓⣤⣄⠈⠱⣆⠀⣀⣲⣤⣷⣤⣀⣽⣓⣤⣠⣯⣾⡿⠋⠀⠀⠀⠀⠀\n"
             "⠀⠀⠀⠀⠀⠀⠁⠀⢸⣿⣿⡿⢷⣶⣾⣿⣶⣿⣶⣿⣿⢾⣿⠿⠋⠉⠙⣿⠿⠃⠀⠀⠀⠀⠐⠀⠀⠀\n"
             "⠀⠀⠀⠀⠀⠀⢰⠀⠈⠻⠟⠀⠈⠙⠿⢿⣿⡏⠛⣿⣿⢺⣿⠀⠀⠀⠀⠀⠀⡄⠀⢠⠀⠀⢁⠀⠀⠀\n"
             "⠀⠀⠀⠈⡀⠀⡼⠀⠀⢀⠀⠀⠀⠀⠀⢸⣿⡿⠀⣿⠁⠀⣿⠀⠀⠀⠀⠀⢠⠇⠀⠸⠀⠀⠀⠀⠀⠀\n"
             "⠀⠀⠀⠀⠁⠀⠇⢀⠀⠘⠀⢀⠀⠀⣾⡗⣿⣿⣹⠀⣦⠰⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
             "⠀⠀⢀⣰⣆⣰⣷⣾⣷⣶⣆⡀⡇⠀⣿⣿⣼⣿⣿⡇⣽⠀⣿⢠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
             "⠀⠀⣾⣿⣿⠿⣛⣹⡿⣿⡿⠃⠁⠀⠉⢽⣿⣿⣭⣹⡇⢰⣿⠘⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
             "⠀⢀⣽⣿⠋⠁⠀⠀⢹⣿⢇⠀⠀⠀⠀⢼⣿⡷⠿⡏⣷⠘⣿⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
             "⠸⢿⢿⣿⠄⡀⠀⢠⣼⣯⣾⣷⣶⣄⠀⣸⡟⢻⠃⣿⠛⢀⣿⢸⠀⠀⠀⠀⠀⠇⡀⢠⠀⠀⢸⠀⠀⠀\n"
             "⠀⠀⠈⢉⣿⣿⣼⡿⠋⠉⢹⣿⣿⣟⣛⣿⠇⠈⣿⠻⡇⢸⣿⠈⠀⠀⠀⣠⣶⣾⣿⣶⣦⣰⣆⣀⠀⠀\n"
             "⠀⠀⠀⠀⠙⠿⠉⠀⠀⠀⠀⠈⠉⠹⣯⣿⣾⣇⣿⡇⣿⢸⣿⢀⠀⠀⠸⢿⣿⠿⠿⢏⣹⠿⢿⣿⣦⡀\n"
             "⠀⠀⠀⠀⠀⠀⢸⠀⠀⡆⠀⠀⠀⠀⠈⢹⣿⡿⣯⡴⠅⢸⣿⠘⠀⠀⠀⢸⣿⣤⡄⠀⣀⠐⢻⣿⣄⡅\n"
             "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⠀⠀⠀⠀⠀⢻⣿⣧⡋⣷⠂⣽⣿⣀⣀⣶⣴⢿⣿⣿⣆⠀⠈⢳⣾⣿⣿⡇\n"
             "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣟⠢⠷⢉⣿⣛⣻⣿⣾⠿⠉⠉⢿⣿⣶⣼⡟⠁⠀⠀\n"
             "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⡟⣿⣮⣿⣡⣿⣿⡟⠉⠉⠀⠀⠀⠈⠉⠹⠏⠁⠀⠀⠀\n"
             "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢽⣿⡿⣿⡂⠻⣿⣿⠉⠀⠀⠀⠀⢰⠀⠀⠀⠀⠀⢠⠀⠀⠀\n"
             "⠀⠀⠀⠀⠀⠀⠀⠀⠀⡄⠀⠀⠀⢀⣤⣾⣿⣇⠿⣏⡑⣿⣿⣦⠀⠀⠄⠀⠘⡦⠀⢰⠂⠀⠀⠀⠀⠀\n"
             "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠃⠀⠀⢦⣸⣿⡓⣿⡟⣷⡘⢷⣌⠘⢻⣶⠀⠀⠀⠀⠃⠀⠘⠀⠀⠀⠀⠀⠀\n"
             "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣈⣤⣄⣸⣿⣏⣿⣿⡿⣯⣷⡈⣎⠳⣶⡹⠾⢟⣤⣠⣄⠀⠀⠀⠀⠀⠀⠀⠀\n"
             "⠀⠀⠀⠀⠀⠀⠀⢠⣴⡿⠿⢿⣟⠻⣯⣿⣿⣿⣿⣷⣟⣩⣿⡿⢿⣟⣾⣿⣛⣽⡷⠀⠀⠀⠀⠀⠀⠀\n"
             "⠀⠀⠀⠀⠀⠀⠀⠀⠘⠃⠀⠙⡟⠀⠛⡁⠀⠛⡟⠁⠛⡋⠁⠀⠀⠛⣋⠈⢛⠋⠀⠀⠀⠀⠀⠀⠀⠀\n";
    
    std::cout << this->getTarget() + "_shrubbery" << " has been created.\n";    
    out.close();
}
