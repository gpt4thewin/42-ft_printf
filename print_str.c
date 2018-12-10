/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:32:14 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/10 11:05:26 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len(t_formatinfo *info, char *str)
{
	int		len;

	len = ft_strlen(str);
	if (info->flags & FLAG_HASPRECISION && len > info->precision)
		len = info->precision;
	return (len);
}

int			print_str(t_formatinfo *info, va_list ap)
{
	char	*str;
	int		padding_size;
	int		len;

	str = va_arg(ap, char*);
	len = get_len(info, str);
	if (!(info->flags & FLAG_MINUS))
		padding_size = print_padding(info, len);
	if (info->flags & FLAG_HASPRECISION)
		ft_putnstr(str, info->precision);
	else
		ft_putstr(str);
	if (info->flags & FLAG_MINUS)
		padding_size = print_padding(info, len);
	return (len + padding_size);
}
