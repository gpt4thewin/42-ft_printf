/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:05:30 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/06 17:54:47 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**
*/

static int	print_arg(const char *restrict format, int *format_pos, va_list ap)
{
	t_formatinfo	formatinfo;

	if (format[(*format_pos)] == '%')
	{
		ft_putchar('%');
		(*format_pos)++;
		return (1);
	}
	ft_bzero(&formatinfo, sizeof(formatinfo));
	parse(format, format_pos, &formatinfo);
	return (print_parameter(&formatinfo, ap));
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		output_size;
	int		format_pos;

	va_start(ap, format);
	format_pos = 0;
	output_size = 0;
	while (format[format_pos] != '\0')
	{
		if (format[format_pos] == '%')
		{
			format_pos++;
			output_size += print_arg(format, &format_pos, ap);
		}
		else
		{
			ft_putchar(format[format_pos]);
			format_pos++;
			output_size++;
		}
	}
	va_end(ap);
	return (output_size);
}
