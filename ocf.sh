#!/bin/bash

hppPath="./"
cppPath="./"

mkdir -p $hppPath $cppPath

create_header() {
    local filename=$1
    local extension=$2
    local username="${USER:-$(whoami)}"
    local email="${MAIL:-${username}@student.42.fr}"
    local date_created=$(date +%Y/%m/%d\ %H:%M:%S)
    
    # Ensure proper alignment for the header
    cat << EOL
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ${filename}.${extension}$(printf '%*s' $((50-${#filename}-${#extension})) ""):+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ${username} <${email}>$(printf '%*s' $((40-${#username}-${#email})) "")+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: ${date_created} by ${username}$(printf '%*s' $((18-${#username})) "")#+#    #+#             */
/*   Updated: ${date_created} by ${username}$(printf '%*s' $((17-${#username})) "")###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

EOL
}

for class in "$@"
do
    capClass="$(tr '[:lower:]' '[:upper:]' <<< ${class:0:1})${class:1}"
    fcapClass="$(tr '[:lower:]' '[:upper:]' <<< ${class})"
    hpp="$hppPath$capClass".hpp
    cpp="$cppPath$capClass".cpp
    
    # HPP
    rm -f $hpp && touch $hpp
    (create_header "$capClass" "hpp"; cat << EOL
#ifndef ${fcapClass}_HPP
# define ${fcapClass}_HPP
# include <iostream>

class $capClass
{
    public:
        $capClass(void);
        $capClass(const $capClass& other);
        $capClass &operator=(const $capClass &other);
        ~$capClass();
};

#endif
EOL
) > $hpp

    # CPPz
    rm -f $cpp && touch $cpp
    (create_header "$capClass" "cpp"; cat << EOL
#include "$capClass.hpp"

// Default constructor
$capClass::$capClass(void)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Copy constructor
$capClass::$capClass(const $capClass &other)
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
$capClass &$capClass::operator=(const $capClass &other)
{
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other)
    {
        // Copy member variables here
    }
    return (*this);
}

// Destructor
$capClass::~$capClass(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}
EOL
) > $cpp
done

printf "\n$# classes created:\n\n"
for class in "$@"
do
    capClass="$(tr '[:lower:]' '[:upper:]' <<< ${class:0:1})${class:1}"
    echo "$capClass.hpp/.cpp"
done