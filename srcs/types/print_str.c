/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tavelino <tavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:32:14 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/12 17:36:06 by tavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define	STRNULL "(null)"

static int	get_len(t_formatinfo *info, char *str)
{
	int		len;

	len = ft_strlen(str);
	if (info->flags & FLAG_HASPRECISION && len > info->precision)
		len = info->precision;
	return (len);
}

void		print_str(t_formatinfo *info, va_list ap, t_output *output)
{
	char	*str;
	int		len;

	str = va_arg(ap, char*);
	if (!(str))
		str = STRNULL;
	len = get_len(info, str);
	out_putchar_len(output, str, len);
}
