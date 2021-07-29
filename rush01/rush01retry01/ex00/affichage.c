/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 11:18:59 by gchatain          #+#    #+#             */
/*   Updated: 2021/07/18 09:26:26 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "beautiful_header.h"
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	affichage(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 1;
		while (str[i][j + 1])
		{
			ft_putchar(str[i][j]);
			j++;
			if (str[i][j + 1])
			{
				ft_putchar(' ');
			}
			else
			{
				ft_putchar('\n');
			}
		}
		i++;
	}
}
