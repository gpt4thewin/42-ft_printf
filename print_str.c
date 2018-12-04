/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:32:14 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/04 17:33:37 by juazouz          ###   ########.fr       */
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
	padding_size = print_padding(info, len);
	ft_putstr(str);
	return (len + padding_size);
}
