/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 20:39:43 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/25 11:05:56 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_beautiful_header.h"

char	**ft_get_keys(char **lines)
{
	char	**keys;
	int		i;
	int		count;

	keys = malloc(sizeof(char *) * (ft_tablen(lines) + 1));
	if (!keys)
		return (NULL);
	i = 0;
	while (lines[i])
	{
		ft_get_past_doublepoint(&lines[i]);
		ft_get_past_spaces(&lines[i]);
		keys[i] = ft_strndup(lines[i], ft_strlen(lines[i]));
		if (!keys[i])
			return (NULL);
		i++;
	}
	keys[i] = malloc(sizeof(char));
	if (!keys[i])
		return (NULL);
	keys[i] = 0;
	return (keys);
}
