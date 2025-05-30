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
# include <string>

class $capClass
{
    public:
        $capClass();
        $capClass(const $capClass& other);
        $capClass &operator=(const $capClass &other);
        ~$capClass();
        
    private:
};

#endif
EOL
) > $hpp

    # CPPz
    rm -f $cpp && touch $cpp
    (create_header "$capClass" "cpp"; cat << EOL
#include "$capClass.hpp"

#include "Logger.hpp"

$capClass::$capClass()
{
    LOG_DEBUG("Default $capClass constructor called");
}

$capClass::$capClass(const $capClass &other)
{
    LOG_DEBUG("$capClass Copy constructor called");
    (void) other;
}

$capClass &$capClass::operator=(const $capClass &other)
{
    LOG_DEBUG("$capClass Assignment operator called");
    if (this != &other)
    {
        // Copy member variables here
    }
    return *this;
}

$capClass::~$capClass()
{
    LOG_DEBUG("$capClass Destructor called");
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