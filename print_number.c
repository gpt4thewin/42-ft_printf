/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:41:58 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/05 21:27:31 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static function to protect
static t_u64	ft_casting_num(t_formatinfo *info, va_list ap)
{
	long long	num;

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

int				print_number(t_formatinfo *info, va_list ap, char *base, int base_len)
{
	t_u64		num;
	int			nbrlen;
	t_bool		unsignd;
	int			output_len;

	unsignd = (info->specifier == spec_uint) ? true : false;
	num = ft_casting_num(info, ap);
	nbrlen = ft_nbrlen(info, num, base_len);
	output_len = nbrlen;
	if (!(info->flags & FLAG_MINUS))
	{
		output_len += print_padding(info, nbrlen);
	}
	if ((t_64)num > 0)
	{
		if (info->flags & FLAG_PLUS)
			ft_putchar('+');
		else if (info->flags & FLAG_SPACE)
			ft_putchar(' ');
	}
	ft_putnbr_base(num, base, unsignd);
	if (info->flags & FLAG_MINUS)
	{
		output_len += print_padding(info, nbrlen);
	}
	return (output_len);
}
