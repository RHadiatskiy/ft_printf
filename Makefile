SRC = src/ft_atoi.c src/ft_atoi_base.c \
		src/ft_d_low.c src/ft_flags_reset.c \
		src/ft_i.c src/ft_isdigit.c \
		src/ft_itoa.c src/ft_itoa_base.c \
		src/ft_o_low.c src/ft_output_func.c \
		src/ft_percent.c src/ft_print_flags.c \
		src/ft_printing.c src/ft_putchar.c \
		src/ft_putnbr.c src/ft_putstrf.c \
		src/ft_s_low.c src/ft_strdup.c \
		src/ft_strjoin.c src/ft_strlen.c \
		src/ft_strlenchr.c src/ft_u_low.c \
		src/parsing.c ft_printf.c
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
HEAD = include/ft_printf.h

all: $(NAME)
$(NAME): $(OBJ)

	ar -cru $(NAME) $(OBJ)
	ranlib $(NAME)
%.o: %.c
	gcc $(FLAGS) -c -o $@ $< 
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all