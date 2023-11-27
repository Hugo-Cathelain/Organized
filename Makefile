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
		src/shared/my_atof.c

MAIN = src/main.c

OBJ = $(SRC:.c=.o)

NAME = organized

FLAGS = -Wall -Wextra

FLAG_T = -Iinclude -lm --coverage -lcriterion

all: $(NAME)

$(NAME):
	gcc -lm -o $(NAME) $(MAIN) $(SRC) -Iinclude $(FLAGS) -g3

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

tests_run:
	gcc -o unit_tests tests/testing.c $(SRC) $(FLAG_T)
	make clean
	./unit_tests && gcovr -e tests/ && gcovr -e tests/ -b
