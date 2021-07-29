/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:07:22 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/22 14:07:24 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i] + '0');
		i++;
	}
}

void	ft_solve(char *board, int x, int *count)
{
	int	i;
	int	j;

	if (x == 10)
	{
		x = -1;
		while (++x < 10)
			ft_putchar(board[x] + '0');
		ft_putchar('\n');
		(*count)++;
		return ;
	}
	i = -1;
	while (++i < 10)
	{
		j = 0;
		while (j < x && i != board[j] && ft_abs(board[j] - i) != x - j)
			j++;
		if (j == x)
		{
			board[x] = i;
			ft_solve(board, x + 1, count);
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	board[10];
	int		count;

	count = 0;
	ft_solve(board, 0, &count);
	return (count);
}
