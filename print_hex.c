/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:38:52 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/05 21:28:12 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define BASE		"0123456789abcdef"
#define BASE_LEN	16

int			print_hex(t_formatinfo *info, va_list ap)
{
	int	output_len;

	output_len = print_number(info, ap, BASE, BASE_LEN);
	return (output_len);
}
