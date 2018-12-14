/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prepound_notnull.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:00:02 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/14 14:02:36 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Prints the specified prepound string if the value is not null.
*/

void	print_prepound_notnull(t_formatinfo *info, char *str,
								va_list ap, t_output *out)
{
	t_u64	num;
	va_list	ap2;

	va_copy(ap2, ap);
	num = read_argument_unsigned(info, ap2);
	if (num != 0)
		out_putchar_len(out, str, ft_strlen(str));
}
