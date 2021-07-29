/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 20:37:09 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/25 19:24:11 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_beautiful_header.h"

char	**ft_get_lines(char *dic)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	**split;
	int		i;

	i = 0;
	fd = open(dic, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() failed\n");
		return (0);
	}
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	split = ft_split(buf, "\n");
	if (!split)
	{
		ft_putstr("Probleme d'allocation memoire.\n");
		return (0);
	}
	if (close(fd) == -1)
	{
		ft_putstr("close() failed\n");
		return (0);
	}
	return (split);
}
