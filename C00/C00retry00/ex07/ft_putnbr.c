/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:41:10 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/09 09:35:51 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	int		i;
	long int nbr2;

	nbr2 = nbr;
	i = 0;
	if (nbr2 < 0)
	{
		ft_putchar('-');
		nbr2 *= -1;
	}
	if (nbr2 >= 10)
	{
		ft_putnbr(nbr2 / 10);
		ft_putnbr(nbr2 % 10);
	}
	else
		ft_putchar(nbr2 + '0');
}
