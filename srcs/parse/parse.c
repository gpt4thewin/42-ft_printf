/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:15:24 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/12 18:41:55 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Parses the argument at the current position and strips the irrelevant flags.
**	Returns 0 if the parameter format is invalid.
*/

void		parse(const char *restrict format,
					int *pos,
					t_formatinfo *info)
{
	while (format[*pos])
	{
		if (parse_specifier(info, format, pos))
			break ;
		if (!parse_flags(info, format, pos) &&
			!parse_width(info, format, pos) &&
			!parse_precision(info, format, pos) &&
			!parse_length(info, format, pos))
		{
			(*pos)++;
		}
	}
	if (info->specifier != spec_int)
	{
		info->flags &= 0xff ^ FLAG_PLUS;
		info->flags &= 0xff ^ FLAG_SPACE;
	}
	if (info->flags & FLAG_HASPRECISION || info->flags & FLAG_MINUS)
	{
		info->flags &= 0xff ^ FLAG_ZERO;
	}
}
