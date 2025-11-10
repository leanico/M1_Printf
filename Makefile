CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = libftprintf.a
AR = ar
ARFLAGS = rcs

SRC = ft_printf.c\
		ft_utilities.c\
		ft_format.c\
		ft_helpers.c\
		ft_helpers2.c\

OBJ = $(SRC:.c=.o)



all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	@echo

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@$(RM) $(OBJ) 

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re