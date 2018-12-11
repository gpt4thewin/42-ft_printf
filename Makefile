# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/17 17:47:32 by juazouz           #+#    #+#              #
#    Updated: 2018/12/11 13:45:22 by juazouz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I $(IDIR) -I $(LIBFT) -g
# CFLAGS = -I $(IDIR) -I $(LIBFT) -g

IDIR = includes
SDIR = srcs
ODIR = obj
LIBFT = libft

NAME = libftprintf.a

DEPS = $(IDIR)/ft_printf.h

OBJ = $(patsubst %.c,$(ODIR)/%.o,$(_SRC))

SRC = $(patsubst %,$(SDIR)/%,$(_SRC)))

_SRC =	core/ft_printf.c \
		core/print_argument.c \
		parse/parse.c \
		parse/parse_flags.c \
		parse/parse_length.c \
		parse/parse_number.c \
		parse/parse_precision.c \
		parse/parse_specifier.c \
		parse/parse_width.c \
		types/print_char.c \
		types/print_float.c \
		types/print_hex.c \
		types/print_hexup.c \
		types/print_int.c \
		types/print_octal.c \
		types/print_str.c \
		types/print_uint.c \
		utils/ft_putnbr_base.c \
		utils/ft_putnstr.c \
		utils/out_init.c \
		utils/out_putchar.c \
		utils/out_write.c \
		utils/print_number_generic.c \
		utils/print_padding.c \
		$(_LIBFTSRC)

_LIBFTSRC = libft/ft_bzero.c \
			libft/ft_isdigit.c \
			libft/ft_putchar.c \
			libft/ft_putstr.c \
			libft/ft_putstr_fd.c \
			libft/ft_strncmp.c \
			libft/ft_strlen.c \
			libft/ft_memset.c \
			libft/ft_putchar_fd.c \
			libft/ft_putendl.c \
			libft/ft_putendl_fd.c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	@mkdir -p $(dir $@)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
