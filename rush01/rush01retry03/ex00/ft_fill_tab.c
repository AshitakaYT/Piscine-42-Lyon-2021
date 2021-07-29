/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alheriti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:23:03 by alheriti          #+#    #+#             */
/*   Updated: 2021/07/18 19:49:51 by alheriti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "beautiful_header.h"

int	ft_is_valid_board(char **tab, int size)
{
	int	i;
	int	j;

	j = 1;
	i = 1;
	while (i < size - 2)
	{
		if (ft_line_left_right(tab[i], size)
			&& ft_line_right_left(tab[i], size))
			i++;
		else
			return (0);
	}
	while (j < size - 1)
	{
		if (ft_column_up_down(tab, j, size) && ft_column_down_up(tab, j, size))
			j++;
		else
			return (0);
	}
	return (1);
}

char	**ft_make_tab(size)
{
	int i;
	char **tab;

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
	int i;

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
	int i;
	int j;
	int x;
	int y;
	int total_size;

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

void	ft_print_full_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}