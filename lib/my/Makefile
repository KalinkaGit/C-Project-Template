##
## EPITECH PROJECT, 2023
## Make lib
## File description:
## Make lib
##

SRC		= src/cat_str_int.c \
		  src/is_digit.c \
		  src/my_compute_power_rec.c \
		  src/my_get_nbr_len.c \
		  src/my_getnbr.c \
		  src/my_memcpy.c \
		  src/my_realloc.c \
		  src/my_strcmp.c \
		  src/my_strlen.c \
		  src/my_strncmp.c \
		  src/my_strstr.c \
		  src/my_strcat.c \
		  src/my_strcpy.c \
		  src/my_itoa.c \
		  src/my_array_len.c \
		  src/my_strdup.c \
		  src/my_alphanum.c

OBJ		= $(SRC:.c=.o)

NAME	= compile
CC		= gcc
CFLAGS	= -Wall -Wextra -I./include -g3

all: $(NAME)

$(NAME): $(OBJ)
		ar rc libmy.a $(OBJ)
		cp libmy.a ../
		cp include/my.h ../../include/
		make clean

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f libmy.a

re: fclean all

.PHONY: all clean fclean re
