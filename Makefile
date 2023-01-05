SHELL = /bin/bash
NAME = libpush_swap.a
MAIN = main.c
EXE = a.out
SRC = push_swap.c commands.c initialize.c find_values.c rotate_stacks.c compare_numbers.c tests_and_extra_functions.c
OBJECTS = *.o
HEADER = push_swap.h
FLAGS = -Wall -Wextra -Werror -g
R = $$((RANDOM % 9 + 1))

.PHONY: all run clean fclean re

all: $(NAME)

$(NAME):
	@cc $(FLAGS) $(HEADER) -c $(SRC)
	@ar rcs $(NAME) $(OBJECTS)
	@echo "Push_swap compiled!"
	@gcc $(MAIN) $(NAME) -o $(EXE) -g

clean: $(OBJECTS)
	@rm -f $(OBJECTS)
	@echo "Object files removed!"

fclean: clean
	@rm -f $(NAME) $(EXE)
	@echo "Library removed!"

re: fclean all

a2:
	@./$(EXE) 1 2
a3:
	@./$(EXE) 1 2 3
a4:
	@./$(EXE) 1 2 3 4
a5:
	@./$(EXE) 1 2 3 4 5
a6:
	@./$(EXE) 1 2 3 4 5 6
a7:
	@./$(EXE) 1 2 3 4 5 6 7
a8:
	@./$(EXE) 1 2 3 4 5 6 7 8
a9:
	@./$(EXE) 1 2 3 4 5 6 7 8 9

d2:
	@./$(EXE) 2 1
d3:
	@./$(EXE) 3 2 1
d4:
	@./$(EXE) 4 3 2 1
d5:
	@./$(EXE) 5 4 3 2 1
d6:
	@./$(EXE) 6 5 4 3 2 1
d7:
	@./$(EXE) 7 6 5 4 3 2 1
d8:
	@./$(EXE) 8 7 6 5 4 3 2 1
d9:
	@./$(EXE) 9 8 7 6 5 4 3 2 1

m3:
	@./$(EXE) 3 1 2
m4:
	@./$(EXE) 2 3 1 4
m5:
	@./$(EXE) 4 1 5 2 3
m6:
	@./$(EXE) 3 6 4 1 2 5
m7:
	@./$(EXE) 6 3 5 2 7 4 1
m8:
	@./$(EXE) 8 1 4 2 6 3 7 5
m9:
	@./$(EXE) 5 8 4 1 7 9 2 6 3

r2:
	@./$(EXE) $(R) $(R)
r3:
	@./$(EXE) $(R) $(R) $(R)
r4:
	@./$(EXE) $(R) $(R) $(R) $(R)
r5:
	@./$(EXE) $(R) $(R) $(R) $(R) $(R)
r6:
	@./$(EXE) $(R) $(R) $(R) $(R) $(R) $(R)
r7:
	@./$(EXE) $(R) $(R) $(R) $(R) $(R) $(R) $(R)
r8:
	@./$(EXE) $(R) $(R) $(R) $(R) $(R) $(R) $(R) $(R)
r9:
	@./$(EXE) $(R) $(R) $(R) $(R) $(R) $(R) $(R) $(R) $(R)