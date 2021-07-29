/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 20:40:43 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/25 11:10:56 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_beautiful_header.h"

void	ft_sort_dict(struct t_dict *dict)
{
	int				i;
	int				j;

	i = 0;
	while (dict[i].number)
	{
		j = i + 1;
		while (dict[j].number)
		{
			if (ft_strlen(dict[i].number) > ft_strlen(dict[j].number))
			{
				ft_swap_dict(&dict[i], &dict[j]);
				j = i + 1;
			}
			else if (ft_strlen(dict[i].number) == ft_strlen(dict[j].number)
				&& ft_strcmp(dict[i].number, dict[j].number) > 0)
			{
				ft_swap_dict(&dict[i], &dict[j]);
				j = i + 1;
			}
			j++;
		}
		i++;
	}
}
