/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:06:45 by tavelino          #+#    #+#             */
/*   Updated: 2018/12/05 21:25:50 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_convertnbr_base(t_64 nbr, char *base, int base_len)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > base_len)
	{
		ft_convertnbr_base((nbr / base_len), base, base_len);
	}
	ft_putchar(base[(nbr % base_len)]);
}

static void		ft_convertunbr_base(t_u64 nbr, char *base, int base_len)
{
	if (nbr > (t_u64)base_len)
	{
		ft_convertunbr_base((nbr / base_len), base, base_len);
	}
	ft_putchar(base[(nbr % base_len)]);
}

void			ft_putnbr_base(t_u64 nbr, char *base, t_bool unsignd)
{
	int		base_len;

	base_len = ft_strlen(base);
	if (unsignd)
		ft_convertunbr_base(nbr, base, base_len);
	else
		ft_convertnbr_base((t_64)nbr, base, base_len);
}
