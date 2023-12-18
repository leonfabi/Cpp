CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

all:		megaphone

main.o:		megaphone.cpp
			$(CC) $(CFLAGS) -c megaphone.cpp

megaphone:	megaphone.o
			@echo "Turning on megaphone...$(RESET)"
			@$(CC) $(CFLAGS) megaphone.o -o megaphone
			@echo "Done! your megaphone is ready.$(RESET)"


clean:
			rm -f *.o

fclean:		clean
			rm -f megaphone *.o

re:			fclean megaphone

.PHONY:		all clean fclean re
