/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:39:23 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/18 20:21:54 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "beautiful_header.h"
#include <stdlib.h>

char	**ft_make_tab(int size)
{
	int		i;
	char	**tab;

	i = 0;
	tab = malloc(sizeof(char *) * (size + 2 + 1));
	if (!tab)
		return (NULL);
	while (i < size + 2)
	{
		tab[i] = malloc(sizeof(char) * (size + 2 + 1));
		if (!tab[i])
			return (NULL);
		i++;
	}
	return (tab);
}

char	*ft_fill_tab_line(char *str, int size)
{
	int	i;

	i = 1;
	while (i < size - 1)
	{
		str[i] = '0';
		i++;
	}
	return (str);
}

char	**ft_fill_tab_views(char **tab, char **views, int size)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	total_size;

	j = 1;
	i = 0;
	x = 1;
	y = 1;
	total_size = size + 2;
	tab[0][0] = '0';
	tab[total_size - 1][0] = '0';
	tab[0][total_size - 1] = '0';
	tab[total_size - 1][total_size - 1] = '0';
	while (x < total_size - 1)
	{
		tab[0][x] = views[i][0];
		x++;
		i++;
	}
	x = 1;
	while (x < total_size - 1)
	{
		tab[total_size - 1][x] = views[i][0];
		x++;
		i++;
	}
	while (y < total_size - 1)
	{
		tab[y][0] = views[i][0];
		y++;
		i++;
	}
	while (j < total_size - 1)
	{
		tab[j] = ft_fill_tab_line(tab[j], total_size);
		j++;
	}
	y = 1;
	while (y < total_size - 1)
	{
		tab[y][total_size - 1] = views[i][0];
		tab[y][total_size] = '\0';
		i++;
		y++;
	}
	tab[total_size] = 0;
	return (tab);
}

int	ft_check_params(int ac, char **av)
{
	int		i;
	int		j;
	char	**tab;
	int		size;

	j = 0;
	i = 0;
	if (ac != 2)
		return (0);
	tab = ft_split(av[1], " ");
	while (tab[i])
		i++;
	if (i % 4 != 0)
		return (0);
	while (tab[j])
	{
		if (tab[j][0] < '0' || tab[j][0] > (i / 4) + '0'
			|| ft_strlen(tab[j]) != 1)
			return (0);
		j++;
	}
	return (1);
}
