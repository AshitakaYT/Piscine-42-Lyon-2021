/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kestucke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:16:53 by kestucke          #+#    #+#             */
/*   Updated: 2021/07/28 13:21:39 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_scooter(void)
{
	int		count;
	char	mini_buff;
	char	*buff;
	char	*str;

	buff = malloc(100000 * sizeof(char));
	count = 0;
	while (read(0, &mini_buff, 1))
		buff[count++] = mini_buff;
	buff[count] = 0;
	str = malloc((count) * sizeof(char));
	count = -1;
	while (buff[++count])
		str[count] = buff[count];
	free(buff);
	str[count] = 0;
	return (str);
}
