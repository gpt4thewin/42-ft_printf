# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/17 17:47:32 by juazouz           #+#    #+#              #
#    Updated: 2018/12/04 17:35:32 by juazouz          ###   ########.fr        #
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

_SRC =	ft_printf.c parse.c print_arg_type.c utils.c \
		print_str.c print_float.c print_char.c \
		print_padding.c

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
