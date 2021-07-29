/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 08:45:31 by gchatain          #+#    #+#             */
/*   Updated: 2021/07/18 15:15:35 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "beautiful_header.h"
#include <stdlib.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb == 1)
		return (1);
	while (i <= 46341)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

int	ft_check_params(int ac, char **av)
{
	int	i;
	int j;
	char **tab;
	int size;


	j = 0;
	i = 0;
	if (ac != 2)
		return (0);
	tab = ft_split(av[1], " ");
	while (tab[i])
		i++;
	printf(" i : %d\n", i);
	if (i % 4 != 0)
		return (0);
	while (tab[j])
	{
		if (tab[j][0] < '0' || tab[j][0] > i / 4 + '0' || ft_strlen(tab[j]) != 1) // remplacer les 4 par une racine carree
			return (0);
		j++;
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

void	ft_print_full_tab(char **tab, int size)
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
	{
		i++;
	}
	if (i < size - 1)
		j = ft_find_empty(tab, size, i);
	else
		return (1);
	printf("j = %d\n", j);
	printf("i = %d\n", i);
	while (ft_find_empty(tab, size, i))
	{
		tab[i][j]++;
		if (j == size - 2)
		{
			if (ft_line_left_right(tab[i], size) && ft_line_right_left(tab[i], size) && ft_column_up_down2(tab, j, size, i) && ft_check_duplicate_line(tab[i], tab[i][j], size) && ft_check_duplicate_column(tab, j, tab[i][j], size))
			{
				if (ft_solve(tab, size))
				{
					return (1);
				}
				tab[i][j] = '0';
			}
		}
		else if (ft_line_left_right2(tab[i], size, j) && ft_column_up_down2(tab, j, size, i) && ft_check_duplicate_line(tab[i], tab[i][j], size) && ft_check_duplicate_column(tab, j, tab[i][j], size))
		{
			if (ft_solve(tab, size))
			{
				return (1);
			}
			tab[i][j] = '0';
		}
	}
	return (0);
}



void	ft_solve4x4(char **tab)
{
	int i;
	int j;

	i = 1;
	while (i < size - 1 && !ft_find_empty(tab, size, i))
	{
		i++;
	}
	if (i < size - 1)
		j = ft_find_empty(tab, size, i);
	else
		return (1);
	if (ft_is_empty_line(tab[i]))
	{
		
	}


}


int	main(int argc, char **argv)
{
	int		i;
	char	**tab;
	char	**views;
	int		size;

	i = 1;
	if (!ft_check_params(argc, argv))
	{
		ft_putstr("Error\n");
		return (0);
	}
	views = ft_split(argv[1], " ");
	while (views[i])
		i++;
	size = i / 4; // potentiellement mettre ft_sqrt() du nombre d'arguments, si pas de solution return error
	printf("On va apres le split \n");
	tab = ft_make_tab(size);
	printf("On va apres le make_tab \n");
	tab = ft_fill_tab_views(tab, views, size);
	printf("On va apres le fill tabs \n");
	ft_print_full_tab(tab, size);


	while (i < 5)
	{
		ft_fill_line_sure(tab[i]);
		i++;
	}
	i = 1;
	while (i < 5)
	{
		ft_fill_column_sure(tab, i);
		i++;
	}


	ft_print_full_tab(tab, size);
	printf("\n RESULT : \n\n");
	ft_affichage(tab, size + 2);



	ft_putstr("nice\n");
}
