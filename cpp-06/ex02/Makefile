# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/06 23:37:48 by llebugle          #+#    #+#              #
#    Updated: 2025/06/06 23:37:48 by llebugle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = identify

FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = A.cpp B.cpp Base.cpp C.cpp main.cpp 

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME):$(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

run: all
	./$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
