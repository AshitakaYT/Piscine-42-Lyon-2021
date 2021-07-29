/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 11:15:50 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/21 11:06:25 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(long int nbr)
{
	int			i;
	long int	nbr2;

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
