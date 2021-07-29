/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_double_point_ok.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 20:38:10 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/25 08:35:49 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_beautiful_header.h"

int	ft_is_double_point_ok(char **lines)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (lines[i])
	{
		j = 0;
		count = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == ':')
				count++;
			j++;
		}
		if (count != 1)
			return (0);
		i++;
	}
	return (1);
}
