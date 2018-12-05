# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/17 17:47:32 by juazouz           #+#    #+#              #
#    Updated: 2018/12/05 21:28:53 by juazouz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I $(IDIR) -I $(LIBFT) -g
# CFLAGS = -I $(IDIR) -I $(LIBFT) -g

IDIR = .
SDIR = .
ODIR = obj
LIBFT = libft

NAME = libftprintf.a

DEPS = $(IDIR)/ft_printf.h

OBJ = $(patsubst %.c,$(ODIR)/%.o,$(_SRC))

SRC = $(patsubst %,$(SDIR)/%,$(_SRC)))

_SRC =	ft_nbrlen.c \
		ft_printf.c \
		ft_putnbr_base.c \
		ft_strrev.c \
		parse.c \
		print_parameter.c \
		print_char.c \
		print_float.c \
		print_hex.c \
		print_hexup.c \
		print_int.c \
		print_uint.c \
		print_octal.c \
		print_padding.c \
		print_number.c \
		print_str.c \
		print_unsigned_number.c \
		utils.c

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
