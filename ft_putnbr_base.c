/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tavelino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:06:45 by tavelino          #+#    #+#             */
/*   Updated: 2018/11/30 17:22:29 by tavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "stdio.h"

void	ft_strrev(char *str);

void	ft_convertnbr_base(int nbr, char* base, int base_len, char* str)
{
	
	if(nbr < 0)
		ft_putchar('-');
	else
		nbr = -nbr;
	if(nbr <= -base_len)
	{
		//recursive
		ft_convertnbr_base(-(nbr / base_len), base, base_len, str + 1);	
	}
	else
		str[1] = '\0';
	*str = base[-(nbr % base_len)];
}



int	ft_putnbr_base(size_t nbr, char *base)
{
	int len;
	char str[50];

	len = ft_strlen(base);
	ft_convertnbr_base(nbr, base, len, str);
	//ft_strrev(str); //need to make a function to reverse before print ft_strrev.c
	ft_putstr(str);
	return (ft_strlen(str)); // return size
}

int		main()
{
	printf("\nsize is: %d \n", ft_putnbr_base(6, "01"));
}
