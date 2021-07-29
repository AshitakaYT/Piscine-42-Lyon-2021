/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:44:26 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/06 15:25:56 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:43:12 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/06 13:44:25 by aucousin         ###   ########lyon.fr   */
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

	i = 0;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		nbr %= 10;
	}
	ft_putchar(nbr + '0');
}

void	ft_print_digits(int a, int b)
{
	if (a < 10)
	{
		ft_putchar('0');
		ft_putchar(a + '0');
	}
	else
		ft_putnbr(a);
	ft_putchar(' ');
	if (b < 10 )
	{
		ft_putchar('0');
		ft_putchar(b + '0');
	}
	else
		ft_putnbr(b);
	if (a != 98 || b != 99)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int		a;
	int		b;

	a = 0;
	while (a < 100)
	{
		b = a + 1;
		while(b < 100)
		{
			ft_print_digits(a, b);
			b++;
		}
		a++;
	}	
}

void	ft_print_combn(int n)
{
	int		a;

	a = ;
	while (a <= 9)
	{
		ft_putchar(a + '0');
		ft_print_combn(n - 1);
		a++;
	}
}

int		main()
{
	ft_print_combn(2);
	return(0);
}

