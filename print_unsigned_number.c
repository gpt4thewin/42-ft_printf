/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_number.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:41:58 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/05 17:40:45 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static function to protect
static unsigned long long		ft_casting_num(t_formatinfo *info,  va_list ap)
{
	unsigned long long	num;

	if (info->length == len_char)
		num = (unsigned char)(va_arg(ap, unsigned  int));
	else if (info->length == len_short)
		num = (unsigned short)(va_arg(ap, unsigned int));
	else if (info->length == len_llong)
		num = (unsigned long long)(va_arg(ap, unsigned long long int));
	else if (info->length == len_long)
		num = (unsigned long)(va_arg(ap, unsigned long int));
	else
		num = (unsigned int)(va_arg(ap, unsigned int));
	return (num);
}

int			print_unsigned_number(t_formatinfo *info, va_list ap, char *base, int base_len)
{
	unsigned long long	num;
	int					nbrlen;

	num = ft_casting_num(info, ap);
	nbrlen = ft_unbrlen(info, num, base_len);
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
