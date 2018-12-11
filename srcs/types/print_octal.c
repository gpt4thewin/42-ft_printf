/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:30:55 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/11 16:05:00 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define BASE		"01234567"
#define BASE_LEN	8
#define PREPOUND	"0"

void		print_octal(t_formatinfo *info, va_list ap, t_output *output)
{
	if (info->flags & FLAG_PREPOUND)
		out_putchar_len(output, PREPOUND, sizeof(PREPOUND) - 1);
	print_number_generic(info, ap, BASE, output);
}
