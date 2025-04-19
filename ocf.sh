#!/bin/bash

hppPath="./"
cppPath="./"

mkdir -p $hppPath $cppPath

create_header() {
    local filename=$1
    local extension=$2
    local pad_filename=$(printf "%-*s" 44 "${filename}.${extension}")
    
    cat << EOL
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ${pad_filename}:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: $(whoami) <$(whoami)@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: $(date +%Y/%m/%d) $(date +%H:%M:%S) by $(whoami)    #+#    #+#             */
/*   Updated: $(date +%Y/%m/%d) $(date +%H:%M:%S) by $(whoami)   ###   ########.fr       */
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

    # CPP
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
    (void) other;
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
