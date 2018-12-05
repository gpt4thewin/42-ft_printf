/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:31:31 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/05 19:35:24 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Selects the right function to print the argument.
**	Returns the number of printed characters.
*/

int		print_arg_type(t_formatinfo *formatinfo, va_list ap)
{
	int			(*func[SPEC_COUNT])(t_formatinfo*, va_list);
	int			(*print_func)(t_formatinfo*, va_list);
	int			len;

	func[spec_int] = print_int;
	func[spec_uint] = print_uint;
	func[spec_octal] = print_octal;
	func[spec_hex] = print_hex;
	func[spec_hexup] = print_hexup;
	func[spec_float] = print_float;
	func[spec_str] = print_str;
	func[spec_char] = print_char;
	print_func = func[formatinfo->specifier];
	len = print_func(formatinfo, ap);
	return (len);
}
