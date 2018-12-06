/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:27:18 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/06 18:37:01 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
**	Includes.
*/

// # include <stdlib.h>
// # include <stdio.h>
// # include <fcntl.h>
#include <stdarg.h>
# include "libft.h"

/*
**	Defines.
*/

/*
**	Types.
*/

/*

ARGUMENT FORMAT
%[flags][width][.precision][length]specifier

%%		: percent sign
.number	: precision
number	: width

FLAGS
#		prepounding, 0x
0		the zero flag (padding with zeros)
+		the plus flag (if possitive)
-		Finally, the minus sign will cause the output to be left-justified.
		This is important if you are using the width specifier and you want
		the padding to appear at the end of the output instead of the beginning:
<space> A blank should be left before a positive number produced by a signed conversion

SPECIFIER
d / i	int
o		octal
u		unsigned int
x		hexa
X		hexa upper case
l		long
lu		long unsigned
f		decimal float
F		decimal float (uppercase?)
s		string
c		char

LEN
hh h l ll

https://faq.cprogramming.com/cgi-bin/smartfaq.cgi?answer=1048379655&id=1043284385
*/

# define FLAG_PREPOUND		0x01
# define FLAG_ZERO			0x02
# define FLAG_PLUS			0x04
# define FLAG_MINUS			0x08
# define FLAG_SPACE			0x10
# define FLAG_HASPRECISION	0x20

typedef struct	s_formatinfo	t_formatinfo;
typedef enum	e_specifier		t_specifier;
typedef enum	e_length		t_length;

typedef	unsigned char			t_u8;
typedef	unsigned short			t_u16;
typedef	unsigned int			t_u32;
typedef	unsigned long long		t_u64;

typedef	char					t_8;
typedef	short					t_16;
typedef	int						t_32;
typedef	long long				t_64;

typedef char					t_s8;
typedef short					t_s16;
typedef int						t_s32;
typedef	long					t_s64;
typedef float					t_f32;
typedef double					t_f64;

// enum	e_flags
// {
// 	prepound = 0x01,
// 	zero = 0x02,
// 	plus = 0x04,
// 	minus = 0x08,
// 	space = 0x10
// };

#define	SPEC_COUNT 9

enum	e_specifier
{
	spec_none,
	spec_int,
	spec_uint,
	spec_octal,
	spec_hex,
	spec_hexup,
	spec_float,
	spec_str,
	spec_char,
};

enum	e_length
{
	none,
	len_char,
	len_short,
	len_long,
	len_llong
};

struct	s_formatinfo
{
	int			precision;
	int			width;
	t_length	length;
	t_specifier	specifier;
	char		flags;
};

/*
**	ft_printf functions.
*/

int			ft_printf(const char *format, ...);
void		append(char *str, size_t *pos, char c);

void		parse(const char *restrict format, int *format_pos, t_formatinfo *info);
void		parse_flags(t_formatinfo *info, const char *restrict format, int *format_pos);
void		parse_width(t_formatinfo *info, const char *restrict format, int *format_pos);
void		parse_precision(t_formatinfo *info, const char *restrict format, int *format_pos);
void		parse_length(t_formatinfo *info, const char *restrict format, int *format_pos);
void		parse_specifier(t_formatinfo *info, const char *restrict format, int *format_pos);
int			parse_number(const char *restrict format, int *format_pos);

int			print_padding(t_formatinfo *formatinfo, int len);

int			print_parameter(t_formatinfo *formatinfo, va_list ap);
int			ft_nbrlen(t_formatinfo *info, t_u64 num, int base_len);
int			ft_unbrlen(t_formatinfo *info, unsigned long long num, int base_len);
void		ft_putnbr_base(t_u64 nbr, char *base, t_bool unsignd);

int			print_number(t_formatinfo *info, va_list ap, char *base, int base_len);

int			print_int(t_formatinfo *info, va_list ap);
int			print_uint(t_formatinfo *info, va_list ap);
int			print_octal(t_formatinfo *info, va_list ap);
int			print_hex(t_formatinfo *info, va_list ap);
int			print_hexup(t_formatinfo *info, va_list ap);
int			print_float(t_formatinfo *info, va_list ap);
int			print_str(t_formatinfo *info, va_list ap);
int			print_char(t_formatinfo *info, va_list ap);

#endif
