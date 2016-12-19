NAME = libftprintf.a

LIBDIR = ./libft/
ROOT = ./
CC = gcc

CFLAGS = -Wall -Wextra -Werror

CFILES = libft/ft_bzero.c libft/ft_strnew.c characters_etc.c signed_int.c unsigned_int.c octal.c hex_lower.c hex_upper.c pointer_fp.c ft_wides.c check_format.c global_definitions.c width_set.c singles.c ft_utoa_ptr.c format_management.c prepend.c create_specifier_substring.c create_specifier_substring2.c create_specifier_substring3.c create_specifier_substring4.c ft_printf.c libft/ft_itoa_base.c libft/ft_putstr.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strlen.c libft/ft_strndup.c libft/ft_utoa_base_lower.c libft/ft_utoa_base_upper.c libft/ft_putchar.c libft/ft_isdigit.c libft/ft_atoi.c
CHEADERS = ./ft_printf.h ./libft/libft.h

OBJS = characters_etc.o signed_int.o unsigned_int.o octal.o hex_lower.o hex_upper.o pointer_fp.o ft_wides.o check_format.o global_definitions.o width_set.o ft_utoa_ptr.o format_management.o singles.o prepend.o create_specifier_substring.o create_specifier_substring2.o create_specifier_substring3.o create_specifier_substring4.o ft_printf.o ft_itoa_base.o ft_putstr.o ft_strdup.o ft_strjoin.o ft_strlen.o ft_strndup.o ft_utoa_base_lower.o ft_utoa_base_upper.o ft_putchar.o ft_strnew.o ft_bzero.o ft_isdigit.o ft_atoi.o

FILES = $(addprefix $(ROOT), $(CFILES))

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	rm -f ./libft/libft.h.gch

$(OBJS): $(CFILES)
	$(CC) -c $(CFLAGS) $(CFILES) -I $(CHEADERS)

clean:
		rm -f $(OBJS)
		cd libft && make clean
fclean: clean
		rm -f $(NAME)
		cd libft && make fclean
re: fclean all

