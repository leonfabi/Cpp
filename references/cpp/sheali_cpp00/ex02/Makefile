NAME		= account_log
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRCS		= tests.cpp Account.cpp
RM			= rm -rf
SRC_PATH	= src/
OBJ_PATH	= obj/
INC_DIR		= include/

SRC			= $(addprefix $(SRC_PATH), $(SRCS))
OBJ			= $(addprefix $(OBJ_PATH), $(OBJS))

OBJS		= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			@echo "Compiling $(NAME)...$(RESET)"
			@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
			@echo "Done! your executable is named $(NAME)$(RESET)"

$(OBJ_PATH)%.o:$(SRC_PATH)%.cpp
			@mkdir -p $(OBJ_PATH)
			@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<


clean:
			$(RM) $(OBJ_PATH)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
