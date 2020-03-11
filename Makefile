.PHONY: all clean fclean re

SRCS = srcs/lemin.c srcs/parse.c
CC = gcc
NAME = lem-in
HEADER = includes/lem_in.h
FLAGS = -Wall -Wextra -Werror -I$(HEADER)
OBJ = $(SRCS:.c=.o)
LIB =  ./libft/

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB)
	@gcc -o $(NAME) $(FLAGS) $(OBJ) libft/libft.a
	@echo "$(NAME) IS READY FOR NAGIB"

clean:
	make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	@rm -f $(NAME)

re: fclean all
