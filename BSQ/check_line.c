/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kestucke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 10:43:11 by kestucke          #+#    #+#             */
/*   Updated: 2021/07/27 16:07:34 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_check_first_line(char **map) // Verification que la premiere ligne est bonne
{
	char *tab;
	int i;
	int a;
	int length;

	i = 0;
	a = 0;
	tab = map[0];
	
	length = ft_strlen(map[0]);
	while (tab[i] != 0)
	{
		i++;
	}
	if (length > 3 && tab[i - 1] >= ' ' && tab[i - 2] >= ' ' && tab[i - 3] >= ' ' && tab[i - 1] != tab[i -2] && tab[i - 2] != tab[i - 3])
	{
		printf("on rentre !!\n");
		while (a < tab[i - 3])
		{
			printf("on rentre aussi!!\n");
			if (map[0][a] < '0'  && map[0][a] > '9')
				return (0);
			a++;
		}
	}
	
	return (1);
}

int		ft_check_seconde_line(char **map) // Verification que les caracteres de la premiere ligne soit bien dans la 2eme
{
	char *tab;
	int i;
	int length;

	i = 0;
	length = 0;
	tab = map[0];
	length = ft_strlen(map[0]);
	while (tab[i] != 0)
	{
		i++;
	}
	if (length > 3 && tab[i - 1] >= 32 && tab[i - 2] >= 32 && tab[i - 3] >= 32 && tab[i - 1] != tab[i -2] && tab[i - 2] != tab[i - 3])
	{
		if((!map[1] || map[1][0] != tab[i - 2] )&& map[1][0] != tab[i - 3])
			return (0);
	}
	return (1);
}
/*
int		ft_check_nbr_lines(char **map)
{
	char *lines;
	int i;

	lines = malloc(sizeof(char) * ft_strlen(map[0] - 3));
		
}
*/


int	ft_check_same_length(char **map) // Verification de la taille de toutes les lignes.
{
	int i;
	int length_first;

	i = 0;
	length_first = ft_strlen(map[1]);
	while(map[i + 2])
	{
		if(ft_strlen(map[i]) != ft_strlen(map[1]))
				return (0);
		i++;
	}
	if (map[i - 1][length_first] != 0)
		return (0);
	return (1);
}

int	ft_check_charset(char **map) // Verification que les separateurs soit les bons
{
	char *tab;
	char empty;
	char full;
	int i;
	int a;
	int b;
	
	a = 0;
	b = 0;
	i = 0;
	tab = map[0];
	while (tab[i] != 0)
		i++;
	empty = tab[i - 3];
	full = tab[i - 2];
	while (map[a])
	{
		b = 0;
		while (map[a][b] != 0)
		{
			if (map[a][b] != empty || map[a][b] != full)
				return (0);
			b++;
		}
		a++;
	}
	return (1);
}
