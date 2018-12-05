/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:30:55 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/05 19:31:03 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define BASE		"01234567"
#define BASE_LEN	8

int			print_octal(t_formatinfo *info, va_list ap)
{
	int	output_len;

	output_len = print_signed_number(info, ap, BASE, BASE_LEN);
	return (output_len);
}
