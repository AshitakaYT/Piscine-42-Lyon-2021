/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrapverif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:05:49 by gchatain          #+#    #+#             */
/*   Updated: 2021/07/18 06:58:09 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_getline(char **tab, int nb, int size)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(size * sizeof(char));
	while (tab[i][nb])
	{
		str[i] = tab[i][nb];
		i++;
	}
	return (str);
}

char	*ft_getcolomn(char **tab, int nb, int size)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(size * sizeof(char));
	while (tab[nb][i])
	{
		str[i] = tab[nb][i];
		i++;
	}
	return (str);
}

int	ft_scrapverif(char *str, int size)
{
	int	i;
	int	max;
	int	view;

	max = 0;
	view = 0;
	i = 1;
	while (size - 1 > i)
	{
		if ((int)str[i] - 48 > max)
		{
			view++;
			max = str[i] - 48;
		}
		i++;
	}
	if (view == (int)str[0] - 48)
		return (1);
	return (0);
}
