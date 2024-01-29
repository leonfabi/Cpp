# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 15:07:34 by fkrug             #+#    #+#              #
#    Updated: 2024/01/29 14:44:08 by fkrug            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animals

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror 
SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re