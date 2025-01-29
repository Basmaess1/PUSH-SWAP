#variables

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ft_printf.c operations.c validate.c sortalgo.c \
		  push_op.c reverse_op.c rotate_op.c swap_op.c \
		  push_swap.c ft_split.c ft_split_utils.c ft_error.c \
		  lst_utils.c sort_util1.c

OBJECTS = $(SOURCES:.c=.o)

#rules
all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(NAME)
# $(NAME): $(OBJECTS)
# 	ar rcs $(NAME) $(OBJECTS)

#clean

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re