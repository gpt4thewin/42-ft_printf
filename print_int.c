/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:08:48 by tavelino          #+#    #+#             */
/*   Updated: 2018/12/10 17:59:50 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define BASE		"0123456789"
#define BASE_LEN	10

int			print_int(t_formatinfo *info, va_list ap)
{
	int	output_len;

	output_len = print_number(info, ap, BASE, BASE_LEN);
	return (output_len);
}
