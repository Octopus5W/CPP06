# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/11 16:20:50 by hdelbecq          #+#    #+#              #
#    Updated: 2025/12/05 13:35:31 by hdelbecq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = converter
C++ = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp ScalarConverter.cpp 
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(C++) $(CFLAGS) $(OBJ) -o $(NAME)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OBJ)
	rm -f $(NAME)
	

re: fclean all

.PHONY: all clean fclean re