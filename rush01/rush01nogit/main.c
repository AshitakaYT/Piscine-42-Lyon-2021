/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 08:45:31 by gchatain          #+#    #+#             */
/*   Updated: 2021/07/18 11:39:53 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "beautiful_header.h"
#include <stdlib.h>

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

int	ft_find_empty(char **tab, int size, int y)
{
	int i;
	int j;

	i = 1;
	while (i < size - 1)
	{
		if (tab[y][i] == '0')
		{
			return (i);
		}
		i++;
	}
	return (0);
}

int	ft_check_duplicate_line(char *str, char c, int size)
{
	int i;
	int count;

	i = 1;
	count = 0;
	while (i < size - 1)
	{
		if (str[i] == c)
		{
			count++;
		}
		i++;
	}
	if (count == 1)
		return (1);
	return (0);
}

int	ft_check_duplicate_column(char **tab, int x, char c, int size)
{
	int i;
	int count;

	i = 1;
	count = 0;
	while (i < size - 1)
	{
		if (tab[i][x] == c)
		{
			count++;
		}
		i++;
	}
	if (count == 1)
		return (1);
	return (0);
}

int	ft_solve(char **tab, int size)
{
	int i;
	int j;

	i = 1;
	while (i < size - 1 && !ft_find_empty(tab, size, i))
		i++;
	if (i < size - 1)
		j = ft_find_empty(tab, size, i);
	else
		return (1);	
	while (tab[i][j] < size - 2 + '0')
	{
		tab[i][j]++;
		if (j == size - 2 && i == size - 2)
		{
			if (ft_line_left_right(tab[i], size) && ft_line_right_left(tab[i], size) && ft_column_up_down(tab, j, size) && ft_column_down_up(tab, j, size) && ft_check_duplicate_line(tab[i], tab[i][j], size) && ft_check_duplicate_column(tab, j, tab[i][j], size))
			{
				if (ft_solve(tab, size))
					return (1);
				tab[size - 2][size - 2] = '0';
			}
		}
		else if (i == size - 2)
		{
			if (ft_line_left_right2(tab[i], size, j) && ft_column_up_down(tab, j, size) && ft_column_down_up(tab, j, size) && ft_check_duplicate_line(tab[i], tab[i][j], size) && ft_check_duplicate_column(tab, j, tab[i][j], size))
			{
				if (ft_solve(tab, size))
					return (1);
				tab[size - 2][j + 1] = '0';
			}
		}
		else if (j == size - 2)
		{
			if (ft_line_left_right(tab[i], size) && ft_line_right_left(tab[i], size) && ft_column_up_down2(tab, j, size, i) && ft_check_duplicate_line(tab[i], tab[i][j], size) && ft_check_duplicate_column(tab, j, tab[i][j], size))
			{
				if (ft_solve(tab, size))
					return (1);
				tab[i + 1][1] = '0';
			}
		}
		else
		{
			if (ft_line_left_right2(tab[i], size, j) && ft_column_up_down2(tab, j, size, i) && ft_check_duplicate_line(tab[i], tab[i][j], size) && ft_check_duplicate_column(tab, j, tab[i][j], size))
			{
				if (ft_solve(tab, size))
					return (1);
				tab[i][j + 1] = '0';
			}
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	char	**tab;
	char	**views;
	int		size;

	i = 0;
	if (!ft_check_params(argc, argv))
	{
		ft_putstr("Error\n");
		return (0);
	}
	views = ft_split(argv[1], " ");
	while (views[i])
		i++;
	size = i / 4;
	tab = ft_make_tab(size);
	tab = ft_fill_tab_views(tab, views, size);
	ft_print_full_tab(tab, size);
	ft_solve(tab, size + 2);
	ft_print_full_tab(tab, size);
	if (ft_is_valid_board(tab, size + 2))
		ft_affichage(tab, size + 2);
	else
		ft_putstr("Error\n");
		return (0);

	ft_putstr("nice\n");
}