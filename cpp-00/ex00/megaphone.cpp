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

#include <iostream>

int main() {
    int x, y;

    std::cin >> x >> y;
    std::cout << x << y;
    if (x < 0) {
        return (1);
    }
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    return 0;
}
