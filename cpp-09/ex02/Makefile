# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/15 18:47:02 by llebugle          #+#    #+#              #
#    Updated: 2025/06/15 18:47:02 by llebugle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = PmergeMe.cpp main.cpp 

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME):$(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

run: all
	./$(NAME) 11 2 17 9 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7
#./$(NAME) "25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0"
# ./$(NAME) "3 9 1 0 999 666"

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
