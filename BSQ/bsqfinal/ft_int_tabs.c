/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_tabs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 13:46:56 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/27 22:41:15 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	**ft_create_int_tab(int xsize, int ysize)
{
	int	**inttab;
	int	x;
	int	y;

	x = 0;
	y = 0;
	inttab = malloc(sizeof(int *) * ysize);
	while (y < ysize)
	{
		inttab[y] = malloc(sizeof(int) * xsize);
		while (x < xsize)
		{
			inttab[y][x] = 0;
			x++;
		}
		x = 0;
		y++;
	}
	return (inttab);
}

int	**ft_make_int_tab(int **inttab, char **tab, char obstacle)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (tab[y])
	{
		while (tab[y][x])
		{
			if (tab[y][x] == obstacle)
			{
				ft_obstacle_incrementation(inttab, tab, &y, &x);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (inttab);
}

void	ft_obstacle_incrementation(int **inttab, char **tab, int *y, int *x)
{
	int	i;
	int	j;

	i = *x;
	j = *y;
	while (tab[j])
	{
		while (tab[j][i])
		{
			inttab[j][i]++;
			i++;
		}
		i = *x;
		j++;
	}
}

int	ft_is_potentially_square(int **tab, int x, int y, int size)
{
	if (tab[y][x] + tab[y + size][x + size]
			- tab[y][x + size] - tab[y + size][x] <= 0)
		return (1);
	return (0);
}

int	ft_is_square(struct s_map str, int x, int y)
{
	int	i;
	int	j;

	i = x;
	j = y;
	while (j < y + str.maxsize + 1)
	{
		while (i < x + str.maxsize + 1)
		{
			if (str.mapchar[j][i] == str.obstacle)
				return (0);
			i++;
		}
		i = x;
		j++;
	}
	return (1);
}
