/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kestucke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:13:14 by kestucke          #+#    #+#             */
/*   Updated: 2021/07/27 23:48:32 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_map_size(char *map)
{
	int		fd;
	char	buff;
	int		size;

	fd = open(map, O_RDONLY);
	size = 0;
	if (fd >= 0)
	{
		while (read(fd, &buff, 1))
			size++;
		close(fd);
		return (size);
	}
	else
		return (0);
}

char	*ft_fullfill_tab(int fd, char *res1, char buf)
{
	int	size;

	size = 0;
	while (read(fd, &buf, 1))
	{
		res1[size] = buf;
		size++;
	}
	return (res1);
}

char	*ft_get_file(char *dico)
{
	int		fd;
	char	*res1;
	int		size;
	char	buf;

	size = 0;
	fd = open(dico, O_RDWR);
	if (fd == -1)
		return (0);
	while (read(fd, &buf, 1))
		size++;
	res1 = malloc(sizeof(char) * size + 1);
	if (!res1)
		return (0);
	if (close(fd) == -1)
		return (0);
	fd = open(dico, O_RDWR);
	if (fd == -1)
		return (0);
	res1 = ft_fullfill_tab(fd, res1, buf);
	res1[size] = '\0';
	close(fd);
	return (res1);
}
