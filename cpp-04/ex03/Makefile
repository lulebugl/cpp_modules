# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/12 09:01:49 by llebugle          #+#    #+#              #
#    Updated: 2025/05/12 09:01:49 by llebugle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = materia

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
SRCS = AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp Logger.cpp main.cpp 

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
