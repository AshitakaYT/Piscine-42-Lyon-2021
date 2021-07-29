/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_dic_ok.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 20:38:33 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/25 19:14:58 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_beautiful_header.h"

int	ft_is_dic_ok(char **lines) // PAS TERMINEE
{
	int	i;
	int	j;

	i = 0;
	if (ft_is_double_point_ok(lines))
	{
		while (lines[i])
		{
			j = 0;
			while (lines[i][j] != ':')
				j++;
			j++;
			while (lines[i][j] == ' ')
				j++;
			if (lines[i][j] > 32 && lines[i][j] < 127)
				while (lines[i][j] > 32 && lines[i][j] < 127)
					j++;
			else
				return (0);
			if (j != ft_strlen(lines[i]))
				return (0);
			i++;
		}
	}
	return (1);
}
