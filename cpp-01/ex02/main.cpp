/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 02:44:21 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/14 02:44:23 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {
	std::string str = "HI THIS IS BRAIN";
	std::string* ptr = &str;
	std::string& ref = str;
	
	std::cout << "Address of str: " << &str << "\n";
	std::cout << "Address of ptr to str: " << ptr << "\n";
	std::cout << "Address of ref to str: " << &ref << "\n";
	
	std::cout << "Value of str: " << str << "\n";
	std::cout << "Value of ptr to str: " << *ptr << "\n";
	std::cout << "Value of ref to str: " << ref << "\n";
	return 0;
}
