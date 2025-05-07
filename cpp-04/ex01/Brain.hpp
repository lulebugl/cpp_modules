/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:28:24 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/07 17:28:24 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
   public:
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();

    static const int IDEAS_COUNT = 100;

    void        setIdea(const std::string& idea, int idx);
    std::string getIdea(int idx) const;

   private:
    std::string _ideas[IDEAS_COUNT];
};

#endif
