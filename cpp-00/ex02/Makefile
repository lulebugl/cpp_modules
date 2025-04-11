# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llebugle <lucas.lebugle@student.s19.be>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/05 20:20:32 by llebugle          #+#    #+#              #
#    Updated: 2025/04/08 02:18:44 by llebugle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
SRCS = 	main.cpp Account.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

SRCS_TEST = 	tests.cpp Account.cpp
OBJS_TEST = $(SRCS_TEST:.cpp=.o)

test:$(OBJS_TEST)
	c++ $(FLAGS) $(OBJS_TEST) -o test
	
$(NAME):$(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re