SRC = libprintf/ft_atoi.c libprintf/ft_atoi_base.c \
		libprintf/ft_d_low.c libprintf/ft_flags_reset.c \
		libprintf/ft_i.c libprintf/ft_isdigit.c \
		libprintf/ft_itoa.c libprintf/ft_itoa_base.c \
		libprintf/ft_o_low.c libprintf/ft_output_func.c \
		libprintf/ft_percent.c libprintf/ft_print_flags.c \
		libprintf/ft_printing.c libprintf/ft_putchar.c \
		libprintf/ft_putnbr.c libprintf/ft_putstrf.c \
		libprintf/ft_s_low.c libprintf/ft_strdup.c \
		libprintf/ft_strjoin.c libprintf/ft_strlen.c \
		libprintf/ft_strlenchr.c libprintf/ft_u_low.c \
		libprintf/parsing.c ft_printf.c
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
HEAD = include/ft_printf.h

all: $(NAME)
$(NAME): $(OBJ)

	ar -cru $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo libftprintf.a has been made
%.o: %.c
	gcc $(FLAGS) -c -o $@ $< 
clean:
	rm -f $(OBJ)
	@echo *.o have been cleaned.
fclean: clean
	rm -f $(NAME)
	@echo *.a and *.o have been cleaned.
re: fclean all