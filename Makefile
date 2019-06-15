##
## EPITECH PROJECT, 2018
## make
## File description:
## ..
##

CC = gcc

FILES = src/cd.c \
        src/clear_str.c \
        src/env_functions.c \
		src/exec.c \
		src/linked_list.c \
		src/main.c \
		src/my_getline.c \
		src/my_putchar.c \
		src/my_putnbr.c \
		src/my_putstr.c \
		src/my_strcat.c \
		src/my_strcmp.c \
		src/my_strdup.c \
		src/my_strlen.c \
		src/my_str_to_word_array.c \
		src/initialisation.c \
		src/sig.c \
		src/tab.c \
		src/built_in.c \
		src/env_manage.c \
		src/my_strncpy.c \
		src/inib.c \
		src/aliasfnc.c \
		src/alias.c \
	    src/tree/tree.c					\
		src/tree/tree_elem.c			\
		src/tree/tree_print.c			\
		src/tree/tree_sep.c				\
		src/tree/tree_fill.c			\
		src/tree/tree_cpy.c				\

SRC =  $(FILES)

OBJ = $(SRC:.c=.o)

NAME = 42sh

RM = rm -rf

CFLAGS = -I./include -g3

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re : fclean all

test: my_ls.c $(FILES)
	$(CC) $^ -o $@ -W -Wall -Wextra -Werror -I./include -lcriterion
	./$@

.PHONY: all clean fclean re test
