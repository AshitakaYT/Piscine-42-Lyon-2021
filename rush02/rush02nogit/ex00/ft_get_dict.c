/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 20:40:01 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/25 19:20:15 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_beautiful_header.h"

struct	t_dict	*ft_get_dict(char **nums, char **keys)
{
	t_dict	*dict;
	int		i;

	i = 0;
	dict = malloc(sizeof(dict) * (ft_tablen(nums) + 1));
	if (!dict)
		return (NULL);
	while (i < ft_tablen(nums))
	{
		dict[i].key = keys[i];
		dict[i].number = nums[i];
		i++;
	}
	dict[i].number = 0;
	return (dict);
}
