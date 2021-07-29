/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norminette.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 23:51:33 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/28 11:56:29 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_atoi_remastered(char *str, int length)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9' && i < length - 3)
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (i == length - 3)
		return (result);
	else
		return (0);
}

void	ft_get_solution(struct s_map *str, int x, int y, int mybool)
{
	str->maxsize = 0;
	while (y + str->maxsize < str->ysize)
	{
		x = 0;
		while (x + str->maxsize < str->xsize)
		{
			mybool = 1;
			while (x + str->maxsize < str->xsize
				&& y + str->maxsize < str->ysize && mybool == 1
				&& ft_is_potentially_square(str->mapint, x, y, str->maxsize))
			{
				if (ft_is_square(*str, x, y))
				{
					str->ymaxpos = y;
					str->xmaxpos = x;
					str->maxsize++;
				}
				else
					mybool = 0;
			}
			x++;
		}
		y++;
	}
}

void	ft_print_int_tab(int **tab, int xsize, int ysize)
{
	int	x;
	int	y;

	y = 0;
	while (y < ysize)
	{
		x = 0;
		while (x < xsize)
		{
			ft_putnbr(tab[y][x]);
			ft_putstr("   ");
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

void	ft_print_char_tab(char **tab)
{
	int	y;

	y = 0;
	while (tab[y])
	{
		ft_putstr(tab[y]);
		ft_putchar('\n');
		y++;
	}
}
