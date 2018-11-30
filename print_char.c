/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:43:05 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/30 16:44:25 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_char(t_formatinfo *info, va_list ap)
{
	(void)info;
	int		c;

	c = va_arg(ap, int);
	ft_putchar((char)c);

	return (1);
}
