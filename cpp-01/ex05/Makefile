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

NAME = Harl

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
DEPFLAGS = -MMD
SRCS =  main.cpp Harl.cpp

OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

all: $(NAME)

%.o: %.cpp
	c++ $(FLAGS) $(DEPFLAGS) -c $< -o $@

$(NAME):$(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)

-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re