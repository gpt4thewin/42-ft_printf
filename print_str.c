/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:32:14 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/07 10:37:57 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_str(t_formatinfo *info, va_list ap)
{
	char	*str;
	int		len;
	int		padding_size;

	str = va_arg(ap, char*);
	len = ft_strlen(str);
	if (!(info->flags & FLAG_MINUS))
		padding_size = print_padding(info, len);
	ft_putstr(str);
	if (info->flags & FLAG_MINUS)
		padding_size = print_padding(info, len);
	return (len + padding_size);
}
