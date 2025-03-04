NAME = libftprintf.a

CC = cc
FLAG = -Wall -Werror -Wextra -fPIC

SRCS = ft_printf.c ft_print_char.c ft_print_hexa.c \
ft_print_int.c ft_print_lhexa.c ft_print_string.c \
ft_print_uhexa.c ft_print_uint.c ft_putchar_fd.c \
ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o:%.c
		$(CC) $(FLAG) -c $<

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re