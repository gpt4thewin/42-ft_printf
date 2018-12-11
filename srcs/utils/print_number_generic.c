/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number_generic.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:26:31 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/11 18:22:02 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_64		read_argument_signed(t_formatinfo *info, va_list ap)
{
	t_64	num;

	if (info->length == len_char)
		num = (char)(va_arg(ap, int));
	else if (info->length == len_short)
		num = (short)(va_arg(ap, int));
	else if (info->length == len_long)
		num = (long)(va_arg(ap, long));
	else if (info->length == len_llong)
		num = (long long)(va_arg(ap, long long));
	else
		num = (int)(va_arg(ap, int));
	return (num);
}

static t_u64	read_argument_unsigned(t_formatinfo *info, va_list ap)
{
	t_u64	num;

	if (info->length == len_char)
		num = (unsigned char)(va_arg(ap, unsigned int));
	else if (info->length == len_short)
		num = (unsigned short)(va_arg(ap, unsigned int));
	else if (info->length == len_long)
		num = (unsigned long)(va_arg(ap, unsigned long));
	else if (info->length == len_llong)
		num = (unsigned long long)(va_arg(ap, unsigned long long));
	else
		num = (unsigned int)(va_arg(ap, unsigned int));
	return (num);
}

static void		print_sign(t_formatinfo *info, t_64 num, t_output *output)
{
	if (num < 0)
	{
		out_putchar(output, '-');
		num *= -1;
	}
	else
	{
		if (info->flags & FLAG_PLUS)
			out_putchar(output, '+');
		else if (info->flags & FLAG_SPACE)
			out_putchar(output, ' ');
	}
}

/*
**	Generic argument number printing functions.
**	Works for any base (2, 10, 16..).
**	Handles the argument format informations.
**	Signed numbers variant.
*/

void			print_number_generic(t_formatinfo *info, va_list ap, char *base, t_output *output)
{
	t_64		num;
	t_u64		unum;
	t_output	output2;

	if (info->specifier == spec_int)
	{
		num = read_argument_signed(info, ap);
		print_sign(info, num, output);
		unum = num;
		if (info->flags & FLAG_HASPRECISION && info->precision == 0  && unum == 0)
			return;
	}
	else
	{
		unum = read_argument_unsigned(info, ap);
	}
	out_init(&output2);
	ft_putnbr_base(unum, base, &output2);
	if (info->flags & FLAG_HASPRECISION)
		fill_nchar(output, info->precision - output2.size, '0');
	else if (!(info->flags & FLAG_MINUS) && info->flags & FLAG_ZERO)
		fill_nchar(output, info->width - output->size - output2.size, '0');
	ft_putnbr_base(unum, base, output);
}
