#!/bin/bash

create_makefile_header() {
    local username="${USER:-$(whoami)}"
    local email="${MAIL:-${username}@student.42.fr}"
    local date_created=$(date +%Y/%m/%d\ %H:%M:%S)
    
    # Ensure proper alignment for the header
    cat << EOL
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile$(printf '%*s' $((50 - 7)) ""):+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ${username} <${email}>$(printf '%*s' $((40-${#username}-${#email})) "")+#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: ${date_created} by ${username}$(printf '%*s' $((18-${#username})) "")#+#    #+#              #
#    Updated: ${date_created} by ${username}$(printf '%*s' $((17-${#username})) "")###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EOL
}

if [ $# -lt 1 ]; then
    echo "Usage: $0 <project_name>"
    exit 1
fi

PROJECT_NAME=$1
OUTPUT_FILE="Makefile"

# Find all .cpp files in the current directory
CPP_FILES=$(find . -maxdepth 1 -name "*.cpp" | sort | sed 's/^\.\///' | tr '\n' ' ')

# Create the Makefile
(create_makefile_header; cat << EOL
NAME = ${PROJECT_NAME}

FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = ${CPP_FILES}

OBJS = \$(SRCS:.cpp=.o)

all: \$(NAME)

\$(NAME):\$(OBJS)
	c++ \$(FLAGS) \$(OBJS) -o \$(NAME)

%.o: %.cpp
	c++ \$(FLAGS) -c \$< -o \$@

run: all
	./\$(NAME)

clean:
	rm -f \$(OBJS)

fclean: clean
	rm -f \$(NAME)

re: fclean all

.PHONY: all clean fclean re
EOL
) > $OUTPUT_FILE

echo "Created Makefile for project: $PROJECT_NAME with sources: ${CPP_FILES}"