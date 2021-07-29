/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nums.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 20:39:03 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/25 19:24:56 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_beautiful_header.h"

void	ft_get_past_whitespaces(char **str)
{
	int	i;

	i = 0;
	while (*str[i] == ' ' || (*str[i] >= 9 && *str[i] <= 13))
		*str[i]++;
}

int	ft_get_number_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

char	*ft_malloc_final_str(void)
{
	char	*dup;

	dup = malloc(sizeof(char));
	if (!dup)
		return (NULL);
	dup = 0;
	return (dup);
}

char	**ft_get_nums(char **lines)
{
	char	**nums;
	int		i;

	nums = malloc(sizeof(char *) * (ft_tablen(lines) + 1));
	if (!nums)
		return (NULL);
	i = -1;
	while (lines[++i])
	{
		ft_get_past_whitespaces(&lines[i]);
		if (*lines[i] == '+')
			*lines[i]++;
		else if (*lines[i] == '-')
			return (NULL);
		if (!(*lines[i] >= '0' && *lines[i] <= '9'))
			nums[i] = ft_strndup("0", 1);
		else
			nums[i] = ft_strndup(lines[i], ft_get_number_len(lines[i]));
		if (!nums[i])
			return (NULL);
	}
	nums[i] = ft_malloc_final_str();
	return (nums);
}
