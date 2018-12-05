/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_number.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:41:58 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/05 17:35:48 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static function to protect
static long long		ft_casting_num(t_formatinfo *info, va_list ap)
{
	long long	num;

	if (info->length == len_char)
		num = (signed char)(va_arg(ap, int));
	else if (info->length == len_short)
		num = (short)(va_arg(ap, int));
	else if (info->length == len_llong)
		num = (long long)(va_arg(ap, long long int));
	else if (info->length == len_long)
		num = (long)(va_arg(ap, long int));
	else
		num = (int)(va_arg(ap, int));
	return (num);
}

int			print_signed_number(t_formatinfo *info, va_list ap, char *base, int base_len)
{
	long long	num;
	int			nbrlen;

	num = ft_casting_num(info, ap);
	nbrlen = ft_nbrlen(info, num, base_len);
	if (!(info->flags & FLAG_MINUS))
	{
		print_padding(info, nbrlen);
	}
	ft_putnbr_base(num, base);
	if (info->flags & FLAG_MINUS)
	{
		if (info->flags & FLAG_ZERO)
			info->flags ^= FLAG_ZERO;
		print_padding(info, nbrlen);
	}
	return (0);
}
