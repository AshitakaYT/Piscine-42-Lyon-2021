/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_duplicate_nums.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 20:39:23 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/24 21:17:29 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_beautiful_header.h"

int	ft_check_duplicate_nums(char **nums)
{
	int	i;
	int	j;

	i = 0;
	while (nums[i])
	{
		j = i + 1;
		while (nums[j])
		{
			if (ft_strcmp(nums[i], nums[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
