##
## EPITECH PROJECT, 2023
## myls
## File description:
## Makefile
##

SRC =	src/shared/my_strlen.c \
		src/shared/my_putstr.c \
		src/shared/my_putfloat.c \
		src/shared/my_putnbr.c \
		src/shared/my_putchar.c \
		src/shared/my_atoi.c \
		src/shared/my_isdigit.c \
		src/shared/my_atof.c \
		src/shared/my_arrlen.c \
		src/shared/my_strcmp.c \
		src/shared/my_strdup.c \
		src/add.c \
		src/del.c \
		src/disp.c \
		src/sort.c \
		src/sort_name.c \
		src/sort_id.c \
		src/sort_type.c

LIB = libshell.a

MAIN = src/main.c

OBJ = $(SRC:.c=.o)

NAME = organized

FLAGS = -Wall -Wextra

FLAG_T = -Iinclude --coverage -lcriterion

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(MAIN) $(SRC) $(LIB) -Iinclude $(FLAGS) -g3

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

tests_run:
	gcc -o unit_tests tests/testing.c $(SRC) $(FLAG_T)
	make clean
	./unit_tests && gcovr -e tests/ && gcovr -e tests/ -b
