/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prepound.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tavelino <tavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:50:05 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/13 15:36:30 by tavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Prints the specified prepound string if needed.
*/

void	print_prepound(t_formatinfo *info, char *str, va_list ap, t_output *out)
{
	t_u64	num;
	va_list	ap2;

	if (!(info->flags & FLAG_PREPOUND))
		return ;
	va_copy(ap2, ap);
	num = read_argument_unsigned(info, ap2);
	if (num != 0)
		out_putchar_len(out, str, ft_strlen(str));
}
