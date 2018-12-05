/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:43:05 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/04 17:34:04 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(t_formatinfo *info, va_list ap)
{
	(void)info;
	int		c;
	int		padding_size;

	c = va_arg(ap, int);
	padding_size = print_padding(info, 1);
	ft_putchar(c);
	return (padding_size + 1);
}