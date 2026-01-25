##
## EPITECH PROJECT, 2025
## Printf
## File description:
## Makefile
##

CC	=	epiclang

SRC	=	\
	lib/my/my_compute_power_rec.c	\
	lib/my/my_compute_square_root.c	\
	lib/my/my_find_prime_sup.c	\
	lib/my/my_getnbr.c	\
	lib/my/my_isneg.c	\
	lib/my/my_is_prime.c	\
	lib/my/my_putchar.c	\
	lib/my/my_put_nbr.c	\
	lib/my/my_putstr.c	\
	lib/my/my_revstr.c	\
	lib/my/my_showmem.c	\
	lib/my/my_showstr.c	\
	lib/my/my_sort_int_array.c	\
	lib/my/my_strcapitalize.c	\
	lib/my/my_strcat.c	\
	lib/my/my_strcmp.c	\
	lib/my/my_strcpy.c	\
	lib/my/my_str_isalpha.c	\
	lib/my/my_str_islower.c	\
	lib/my/my_str_isnum.c	\
	lib/my/my_str_isprintable.c	\
	lib/my/my_str_isupper.c	\
	lib/my/my_strlen.c	\
	lib/my/my_strlowcase.c	\
	lib/my/my_strncat.c	\
	lib/my/my_strncmp.c	\
	lib/my/my_strncpy.c	\
	lib/my/my_strstr.c	\
	lib/my/my_strupcase.c	\
	lib/my/my_swap.c	\
	lib/my/my_put_unsigned_nbr.c	\
	lib/my/my_put_float.c	\
	lib/my/my_put_octal.c	\
	lib/my/my_isneg_printf.c	\
	lib/my/my_printf.c	\
	lib/my/printf_char.c	\
	lib/my/printf_float.c \
	lib/my/printf_intoctal.c \
	lib/my/printf_modulo.c \
	lib/my/printf_string.c \
	lib/my/my_flag_x.c	\
	lib/my/my_flag_up_x.c	\
	lib/my/printf_decimal.c	\
	lib/my/printf_hex.c	\
	lib/my/printf_hex_up_x.c	\
	lib/my/my_flag_p.c	\
	lib/my/my_flag_e.c	\
	lib/my/printf_scientific.c	\
	lib/my/printf_pointer.c	\
	lib/my/printf_sign_plus.c	\
	src/map_build.c	\
	src/print_tab.c	\
	src/generator.c	\
	src/algorithm_x.c	\
	src/main.c	\
	src/read_board.c	\
	src/sub_fonctions.c	\
	lib/my/printf_unsdecimal.c	\

	

CINCLUDE	=	-I./include/
CFLAGS	=	-g3 -pedantic #-Wall -Wextra -Werror

OBJ	=	$(SRC:.c=.o)

NAME	=	setting_up	

all:	$(NAME)

%.o:	%.c
	@$(CC) $(CFLAGS) $(CINCLUDE) -o $@ -c $<

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ)
	@printf "[SUCCESS] Compiled %s\n" $(NAME)

clean:
	@rm -f $(OBJ)
	@printf "[CLEAN] Removed object directory\n"

fclean:	clean
	@rm -f $(NAME)
	@printf "[FCLEAN] Removed %s\n" $(NAME)

re:		fclean all

.PHONY: all clean fclean re
