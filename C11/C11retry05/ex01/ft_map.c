/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 18:17:11 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/19 11:55:48 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int lenght, int(*f)(int))
{
	int	*result;
	int	i;

	i = 0;
	result = malloc(sizeof(int) * lenght);
	if (!result)
		return (0);
	while (i < lenght)
	{
		result[i] = (f)(tab[i]);
		i++;
	}
	return (result);
}
