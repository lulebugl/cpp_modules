/* ***************************************************************************/
/*                                                                           */
/*                                                        :::      ::::::::  */
/*   megaphone.cpp                                      :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: llebugle <lucas.lebugle@student.s19.be>    +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2025/04/05 20:19:48 by llebugle          #+#    #+#            */
/*   Updated: 2025/04/05 21:36:42 by llebugle         ###   ########.fr      */
/*                                                                           */
/* ***************************************************************************/

#include <cctype>
#include <iostream>
#include <string>

int main(int argc, char **av) {
    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else {
        for (int i = 1; i < argc; i++) {
            std::string str(av[i]);
            for (size_t j = 0; j < str.length(); j++)
                str[j] = std::toupper(av[i][j]);
            std::cout << str;
        }
    }
    std::cout << "\n";
    return 0;
}
