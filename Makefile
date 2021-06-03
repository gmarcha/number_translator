NAME	= number-translator
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
SRC		= add_value.c dict_utils.c dictionary.c digit_to_letter.c free.c linked_list.c main.c malloc_utils.c parse_input.c put_utils.c string_utils.c utils.c
OBJ		= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -fsanitize=address -o $@ $^

%.o:		%.c
			$(CC) $(FLAGS) -o $@ -c $<

clean:
			rm -rf $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
