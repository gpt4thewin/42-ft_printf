/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:52:03 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/12 15:57:56 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_flags(t_formatinfo *info,
						const char *restrict format,
						int *pos)
{
	while (format[*pos] != '\0')
	{
		if (format[*pos] == '#')
			info->flags |= FLAG_PREPOUND;
		else if (format[*pos] == '0')
			info->flags |= FLAG_ZERO;
		else if (format[*pos] == '+')
			info->flags |= FLAG_PLUS;
		else if (format[*pos] == '-')
			info->flags |= FLAG_MINUS;
		else if (format[*pos] == ' ')
			info->flags |= FLAG_SPACE;
		else
			return ;
		(*pos)++;
	}
}
