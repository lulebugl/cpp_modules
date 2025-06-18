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

FLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
SRCS = main.cpp 

OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	c++ $(FLAGS) -MMD -MP -c $< -o $@

# Include dependency files if they exist
-include $(DEPS)

run: all
	./$(NAME) 11 2 17 9 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

