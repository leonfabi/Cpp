NAME = exe.out

FLAGS = -Werror -Wall -Wextra -std=c++98

CC = c++

all:
	$(CC) $(FLAGS) *.cpp  -o $(NAME)

clean:
	rm -f $(NAME)

run: all
	./$(NAME)

re:clean all	