CC = gcc -Werror -Wextra -Wall -g -O0

SRCPATH = ./srcs

INCPATH = ./includes

LIBFT = ./libft

HEADER = -I $(LIBFT)/includes -I $(INCPATH)

LIB = -L$(LIBFT) -lft

DEP = make -C $(LIBFT)/

SRC = 	$(SRCPATH)/ft_check.c\
		$(SRCPATH)/main.c\
		$(SRCPATH)/ft_operation_a.c\
		$(SRCPATH)/ft_operation_b.c\
		$(SRCPATH)/ft_operation_ab.c\
		$(SRCPATH)/ft_algo.c\
		$(SRCPATH)/ft_best_algo.c\
		$(SRCPATH)/ft_debug.c\
		$(SRCPATH)/ft_prepare.c\
		$(SRCPATH)/dlist/dlist_create_node.c\
		$(SRCPATH)/dlist/dlist_new.c\
		$(SRCPATH)/dlist/dlist_push_back.c\
		$(SRCPATH)/dlist/dlist_push_front.c\
		$(SRCPATH)/dlist/dlist_remove_head.c\
		$(SRCPATH)/dlist/dlist_remove_tail.c\

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
