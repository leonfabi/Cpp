# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pschwarz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 21:23:01 by pschwarz          #+#    #+#              #
#    Updated: 2023/05/17 14:58:56 by pschwarz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tests
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = tests.cpp Account.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $^ -o $(NAME) $(CXXFLAGS)

%.o: %.cpp
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
