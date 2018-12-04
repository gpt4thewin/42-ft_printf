/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tavelino <tavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:08:48 by tavelino          #+#    #+#             */
/*   Updated: 2018/12/04 20:09:20 by tavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* static function to protect
static intmax_t		ft_casting_num(t_formatinfo **info,  va_list *ap)
{
	intmax_t num;

	if (*info->length == len_char)
		num = (signed char)(va_arg(ap, int));
	else if (*info->length == len_short)
		num = (short)(va_arg(ap, int));
	else if (*info->length == len_llong)
		num = (long long)(va_arg(ap, long long int));
	else if (*info->length == len_long)
		num = (long)(va_arg(ap, long int));
	else
		num = (int)(va_arg(ap, int));
	num = (intmax_t)num;
	return (num);
}

// Count number of digits useful on "width" at the print function
static int	count_digits(intmax_t num)
{
	int total ;

	total = 0;
	if (num < 0)
		num *= -1;
	total++;
	while ((num /= 10) > 0)
		total++;
	return (total);
}

number of characters to be printed
// print pading numbers with 0 or spaces if need

*/
int			print_int(t_formatinfo *info, va_list ap)
{
	long long  num;

	if (info->width)
		ft_putchar('w');
	num = va_arg(ap, long long);

	ft_putnbr(num);
	return (0);
}
