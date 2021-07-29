/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 08:13:01 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/20 16:39:13 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_convert_base(long int nbr, char *base)
{
	int	len;

	len = 0;
	while (base[len])
		len++;
	if (nbr >= len)
		ft_convert_base(nbr / len, base);
	ft_putchar(base[nbr % len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	nbr2;
	int			lenbase;

	lenbase = 0;
	while (base[lenbase])
		lenbase++;
	nbr2 = nbr;
	if (nbr2 < 0)
	{
		ft_putchar('-');
		nbr2 *= -1;
	}
	ft_convert_base(nbr2, base);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32)
		{
			if (str[i] < 16)
			{
				ft_putchar('\\');
				ft_putchar('0');
				ft_putnbr_base(str[i], "0123456789abcdef");
			}
			else
			{
				ft_putchar('\\');
				ft_putnbr_base(str[i], "0123456789abcdef");
			}
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
