/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 21:07:46 by llebugle          #+#    #+#             */
/*   Updated: 2025/06/05 21:07:47 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include <iostream>

#include "Serializer.hpp"

struct Data {
    std::string name;
    int         age;

    Data() : name("anonymous"), age(0) {};
    Data(std::string name, int age) : name(name), age(age) {};
};

int main() {
    Data* testData = new Data("john", 5);

    std::cout << "original Data ptr: " << testData << std::endl;
    std::cout << "name: " << testData->name << std::endl;
    std::cout << "age: " << testData->age << std::endl;

    std::cout << "Serializing..." << std::endl;
    uintptr_t test = Serializer::serialize(testData);
    std::cout << "uintptr_t: " << test << std::endl;

    std::cout << "deserializing..." << std::endl;
    Data* deserialized = Serializer::deserialize(test);

    std::cout << "new Data ptr: " << deserialized << std::endl;
    std::cout << "\nOriginal ptr: " << testData << std::endl;
    std::cout << "name: " << deserialized->name << std::endl;
    std::cout << "age: " << deserialized->age << std::endl;

    delete testData;
    return 0;
}
