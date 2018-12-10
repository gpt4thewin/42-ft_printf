/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unumber.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:26:31 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/10 19:07:56 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_unbrlen(t_formatinfo *info, t_u64 num, int base_len)
{
	int total;

	total = 1;
	if (info->flags & FLAG_PLUS)
	{
		total++;
	}
	while ((num /= base_len) > 0)
		total++;
	return (total);
}

static t_u64	read_argument(t_formatinfo *info, va_list ap)
{
	t_u64	num;

	if (info->length == len_char)
		num = (t_u8)(va_arg(ap, t_u32));
	else if (info->length == len_short)
		num = (t_u16)(va_arg(ap, t_u32));
	else if (info->length == len_long)
		num = (t_u32)(va_arg(ap, t_u32));
	else if (info->length == len_llong)
		num = (t_u64)(va_arg(ap, t_u64));
	else
		num = (t_u32)(va_arg(ap, t_u32));
	return (num);
}

/*
**	Generic argument number printing functions.
**	Works for any base (2, 10, 16..).
**	Handles the argument format informations.
**	Unsigned numbers variant.
*/

int				print_unumber(t_formatinfo *info, va_list ap, char *base, int base_len)
{
	t_u64	num;
	int		nbrlen;
	int		output_len;

	num = read_argument(info, ap);
	nbrlen = ft_unbrlen(info, num, base_len);
	output_len = nbrlen;
	if (!(info->flags & FLAG_MINUS))
	{
		output_len += print_padding(info, nbrlen);
	}
	ft_putnbr_base(num, base, true);
	if (info->flags & FLAG_MINUS)
	{
		output_len += print_padding(info, nbrlen);
	}
	return (output_len);
}
