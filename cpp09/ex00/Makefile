# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 15:07:34 by fkrug             #+#    #+#              #
#    Updated: 2024/05/06 20:09:51 by fkrug            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -g -Werror
SRC = main.cpp BitcoinExchange.cpp
OBJ = $(SRC:.cpp=.o)
DEPS = BitcoinExchange.hpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re