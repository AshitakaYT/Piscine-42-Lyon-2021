/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 20:41:00 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/25 21:54:55 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_beautiful_header.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;
	printf("S1 = %s\n", s1);
	printf("S2 = %s\n", s2);
	printf("n = %d\n", n);

	i = 0;
	if (n == 0)
		return (0);
	while (s2[i] && s1[i] == s2[i] && i < n)
	{
		i++;
		printf("ca segfault?\n i = %d\n", i);
	}
	if (i == ft_strlen(s2) && i == n)
	{
		printf("ca return 0 \n");
		return (0);
	}
	else
	{
		printf("ca return 1 \n");
		return (1);
	}
}
