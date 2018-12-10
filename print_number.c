/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:26:31 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/10 18:26:31 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_64	read_argument(t_formatinfo *info, va_list ap)
{
	t_64	num;

	if (info->length == len_char)
		num = (t_8)(va_arg(ap, t_32));
	else if (info->length == len_short)
		num = (t_16)(va_arg(ap, t_32));
	else if (info->length == len_long)
		num = (t_32)(va_arg(ap, t_32));
	else if (info->length == len_llong)
		num = (t_64)(va_arg(ap, t_64));
	else
		num = (t_32)(va_arg(ap, t_32));
	return (num);
}

/*
**	Generic argument number printing functions.
**	Works for any base (2, 10, 16..).
**	Handles the argument format informations.
**	Signed numbers variant.
*/

int				print_number(t_formatinfo *info, va_list ap, char *base, int base_len)
{
	t_64	num;
	int		nbrlen;
	int		output_len;

	num = read_argument(info, ap);
	nbrlen = ft_nbrlen(info, num, base_len);
	output_len = nbrlen;
	if (!(info->flags & FLAG_MINUS))
	{
		output_len += print_padding(info, nbrlen);
	}
	if ((t_64)num >= 0)
	{
		if (info->flags & FLAG_PLUS)
			ft_putchar('+');
		else if (info->flags & FLAG_SPACE)
			ft_putchar(' ');
	}
	ft_putnbr_base(num, base, info->unsignd);
	if (info->flags & FLAG_MINUS)
	{
		output_len += print_padding(info, nbrlen);
	}
	return (output_len);
}
