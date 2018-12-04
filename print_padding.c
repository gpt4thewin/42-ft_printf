/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:22:53 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/04 17:36:00 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Prints the padding characters if len < width
**	Returns the total number of printed characters
*/

int		print_padding(t_formatinfo *formatinfo, int len)
{
	int		i;
	char	padchar;

	if (len >= formatinfo->width)
		return (0);
	if (formatinfo->flags & FLAG_ZERO)
		padchar = '0';
	else
		padchar = ' ';
	i = 0;
	while (i < (formatinfo->width - len))
	{
		ft_putchar(padchar);
		i++;
	}
	return (i);
}
