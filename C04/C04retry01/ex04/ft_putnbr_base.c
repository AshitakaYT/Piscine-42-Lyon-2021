/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 10:40:51 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/12 19:47:07 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_once_in_base(char *base, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (base[i])
	{
		if (base[i] == c && count == 1)
			return (0);
		else if (base[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	ft_check_base(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (!ft_is_once_in_base(base, base[i]) \
			|| base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	else
		return (1);
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
	if (ft_check_base(base))
	{
		if (nbr2 < 0)
		{
			ft_putchar('-');
			nbr2 *= -1;
		}
		ft_convert_base(nbr2, base);
	}
}
