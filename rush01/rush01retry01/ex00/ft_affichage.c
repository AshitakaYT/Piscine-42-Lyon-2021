/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 11:18:59 by gchatain          #+#    #+#             */
/*   Updated: 2021/07/18 10:39:47 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_affichage(char **str, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size - 1)
	{
		j = 1;
		while (j < size - 1)
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
