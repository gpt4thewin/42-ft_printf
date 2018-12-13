# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tavelino <tavelino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/17 17:47:32 by juazouz           #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2018/12/13 14:27:13 by juazouz          ###   ########.fr        #
=======
#    Updated: 2018/12/13 15:52:52 by tavelino         ###   ########.fr        #
>>>>>>> origin/master
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I $(IDIR) -I $(LIBFT) -g

IDIR = includes
SDIR = srcs
ODIR = obj
LIBFT = libft

NAME = libftprintf.a

DEPS = $(IDIR)/ft_printf.h \
		$(IDIR)/ft_printf_types.h
LIBFTDEPS = $(LIBFT)/libft.h

OBJ = $(patsubst %.c,$(ODIR)/%.o,$(_SRC))

SRC = $(patsubst %,$(SDIR)/%,$(_SRC)) \
		$(patsubst %,$(LIBFT)/%,$(_LIBFTSRC))

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
		types/print_percent.c \
		utils/ft_putnbr_base.c \
		utils/ft_putnstr.c \
		utils/out_init.c \
		utils/out_putchar_len.c \
		utils/out_putchar.c \
		utils/out_fill.c \
		utils/print_number_generic.c \
		utils/print_padding.c \
		utils/print_prepound.c \
		args/read_argument.c \
		$(_LIBFTSRC)

_LIBFTSRC = ft_bzero.c \
			ft_isdigit.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_strncmp.c \
			ft_strlen.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_max.c \
			ft_powf.c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	@mkdir -p $(dir $@)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/%.o: $(LIBFT)/%.c $(LIBFTDEPS)
	@mkdir -p $(dir $@)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
