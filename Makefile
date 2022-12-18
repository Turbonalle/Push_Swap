NAME = libpush_swap.a
MAIN = main.c
EXE = exe.out
SRC = push_swap.c
OBJECTS = *.o
HEADER = push_swap.h
FLAGS = -Wall -Wextra -Werror

.PHONY: all run clean fclean re

all: $(NAME)

$(NAME):
	@$(MAKE) -C ../libft
	@cp ../libft/libft.a libpush_swap.a
	@cc $(FLAGS) $(SRC) $(NAME)
	@./a.out
#	@ar rcs $(NAME) $(OBJECTS)
#	@echo "Push_swap compiled!"

run:
	@gcc $(MAIN) $(NAME) -o $(EXE)
	@./$(EXE)

clean: $(OBJECTS)
	@$(MAKE) clean -C ../libft
	@rm -f $(OBJECTS)
	@echo "Object files removed!"

fclean: clean
	@$(MAKE) fclean -C ../libft
	@rm -f $(NAME) $(EXE)
	@echo "Library removed!"

re: fclean all