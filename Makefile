CC = gcc -Werror -Wextra -Wall

SRCPATH = ./srcs

INCPATH = ./includes

LIBFT = ./libft

HEADER = -I $(LIBFT)/includes -I $(INCPATH)

LIB = -L$(LIBFT) -lft

DEP = make -C $(LIBFT)/

SRC = 	$(SRCPATH)/ft_check.c\
		$(SRCPATH)/main.c\
		$(SRCPATH)/operation1.c\
		$(SRCPATH)/operation2.c\

OBJ = $(SRC:.c=.o)

NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJ)
	@echo " PUSH SWAP"
	@cd $(LIBFT) && $(MAKE)
	@echo " LIBFT"
	@$(CC) $(HEADER)  $(LIB) -o $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(HEADER) -o $@ -c $<
	@echo "\033[32m█\033[0m\c"

clean : 
	@cd $(LIBFT) && $(MAKE) clean
	@rm -rf $(OBJ)

fclean : clean
	@cd $(LIBFT) && $(MAKE) fclean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
