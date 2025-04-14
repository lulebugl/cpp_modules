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

NAME = brain

FLAGS = -Wall -Wextra -Werror -MM -std=c++98 -pedantic
SRCS =  main.cpp

OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

# reformats the dependency file to make it work with Make's include directive
all: $(NAME)

%.o: %.cpp
	c++ $(FLAGS) -MMD -c $< -o $@

$(NAME):$(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)

-include $(DEPS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re