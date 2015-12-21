CC = gcc -Werror -Wextra -Wall

SRCPATH = ./srcs

INCPATH = ./includes

LIBFT = ./libft

HEADER = -I $(LIBFT)/includes -I $(INCPATH)

LIB = -L $(LIBFT) -lft

DEP = make -C $(LIBFT)/

SRC = 	$(SRCPATH)/ft_check.c\
		$(SRCPATH)/main.c\
		$(SRCPATH)/operation1.c\
		$(SRCPATH)/operation2.c\
		$(SRCPATH)/pile.c\

OBJ = $(SRC:.c=.o)

NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(HEADER) $(DEP) $(LIB) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(HEADER) -o $@ -c $<

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re