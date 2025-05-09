# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 20:47:52 by llebugle          #+#    #+#              #
#    Updated: 2025/05/07 20:47:52 by llebugle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animals

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
SRCS = Animal.cpp Brain.cpp Cat.cpp Dog.cpp main.cpp WrongAnimal.cpp WrongCat.cpp \
		Logger.cpp

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
