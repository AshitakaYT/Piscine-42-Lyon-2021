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

<<<<<<< HEAD
#include <stdlib.h>
#include "beautiful_header.h"

=======
#include "beautiful_header.h"

void	ft_fill_line(char *str, int a, int b)
{
	str[1] = a / 10;
	str[2] = a % 10;
	str[3] = b / 10;
	str[4] = b % 10;
}

void	ft_fill_col(char **str, int a, int b)
{
	*str[1] = a / 10;
	*str[2] = a % 10;
	*str[3] = b / 10;
	*str[4] = b % 10;
}

void	ft_fill_column_sure(char **tab, int column)
{
	if (tab[column][0] == '1' && tab[column][5] == '4')
		ft_fill_col(tab, 43, 21);
	else if (tab[column][0] == '4' && tab[column][5] == '1')
		ft_fill_col(tab, 12, 34);
	else if (tab[column][0] == '1' && tab[column][5] == '2')
		ft_fill_col(tab, 41, 23);
	else if (tab[column][0] == '2' && tab[column][5] == '1')
		ft_fill_col(tab, 32, 14);
	else if (tab[column][0] == '3' && tab[column][5] == '2')
		ft_fill_col(tab, 23, 41);
	else if (tab[column][0] == '2' && tab[column][5] == '3')
		ft_fill_col(tab, 14, 32);
}

void	ft_fill_line_sure(char *str)
{
	if (str[0] == '1' && str[5] == '4')
		ft_fill_line(str, 43, 21);
	else if (str[0] == '4' && str[5] == '1')
		ft_fill_line(str, 12, 34);
	else if (str[0] == '1' && str[5] == '2')
		ft_fill_line(str, 41, 23);
	else if (str[0] == '2' && str[5] == '1')
		ft_fill_line(str, 32, 14);
	else if (str[0] == '3' && str[5] == '2')
		ft_fill_line(str, 23, 41);
	else if (str[0] == '2' && str[5] == '3')
		ft_fill_line(str, 14, 32);
}

>>>>>>> 6c36d90c1add892b4b4139c211a9cace224ca1d3
int	ft_is_valid_board(char **tab, int size)
{
	int	i;
	int	j;

	j = 1;
	i = 1;
<<<<<<< HEAD
	while (i < size - 2)
=======
	while (i < size - 1)
>>>>>>> 6c36d90c1add892b4b4139c211a9cace224ca1d3
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
<<<<<<< HEAD

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
=======
>>>>>>> 6c36d90c1add892b4b4139c211a9cace224ca1d3
