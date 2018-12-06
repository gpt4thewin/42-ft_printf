/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:02:25 by tavelino          #+#    #+#             */
/*   Updated: 2018/12/06 16:30:09 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbrlen(t_formatinfo *info, t_u64 num, int base_len)
{
	int total;

	total = 1;
	if ((t_64)num < 0)
	{
		num *= -1;
		total++;
	}
	else if (info->flags & FLAG_PLUS &&
			info->specifier == spec_int &&
			(t_64)num > 0)
	{
		total++;
	}
	while ((num /= base_len) > 0)
		total++;
	return (total);
}

int		ft_unbrlen(t_formatinfo *info, unsigned long long num, int base_len)
{
	int total;

	total = 1;
	if (info->flags & FLAG_PLUS)
	{
		total++;
	}
	while ((num /= base_len) > 0)
		total++;
	return (total);
}
