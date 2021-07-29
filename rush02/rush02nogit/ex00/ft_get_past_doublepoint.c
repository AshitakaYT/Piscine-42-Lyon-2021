/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_past_doublepoint.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 11:03:15 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/25 11:07:22 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_beautiful_header.h"

void	ft_get_past_doublepoint(char **str)
{
	int	i;

	i = 0;
	while (*str[i] != ':')
		*str[i]++;
	*str[i]++;
}
