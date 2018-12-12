/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:52:40 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/12 15:57:35 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_precision(t_formatinfo *info,
							const char *restrict format,
							int *pos)
{
	if (format[*pos] == '.')
	{
		(*pos)++;
		info->precision = parse_number(format, pos);
		info->flags |= FLAG_HASPRECISION;
	}
}
