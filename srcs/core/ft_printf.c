/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:05:30 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/12 16:00:15 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Parse the current argument starting with "%" and prints it.
*/

static int	parse_and_print_argument(const char *restrict format,
									int *pos,
									va_list ap)
{
	t_formatinfo	formatinfo;

	ft_bzero(&formatinfo, sizeof(formatinfo));
	parse(format, pos, &formatinfo);
	return (print_argument(&formatinfo, ap));
}

int			ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		output_size;
	int		pos;

	va_start(ap, format);
	pos = 0;
	output_size = 0;
	while (format[pos] != '\0')
	{
		if (format[pos] == '%')
		{
			pos++;
			output_size += parse_and_print_argument(format, &pos, ap);
		}
		else
		{
			ft_putchar(format[pos]);
			pos++;
			output_size++;
		}
	}
	va_end(ap);
	return (output_size);
}
