NAME	= rush-02
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
SRC		= $(wildcard *.c)
OBJ		= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -o $@ $^

%.o:		%.c
			$(CC) $(FLAGS) -o $@ -c $<

clean:
			rm -rf $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re