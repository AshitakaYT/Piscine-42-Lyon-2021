/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:07:47 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/28 11:55:05 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_is_first_line_ok(struct s_map *strc, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4)
		return (0);
	else if (ft_atoi_remastered(str, len) == 0)
		return (0);
	else if (str[len - 1] == str[len - 2] || str[len - 1] == str[len - 3]
		|| str[len - 2] == str[len - 3])
		return (0);
	else
	{
		strc->nbroflines = ft_atoi_remastered(str, len);
		if (!strc->mapchar[0])
			return (0);
		strc->linelength = ft_strlen(strc->mapchar[0]);
		strc->space = str[len - 3];
		strc->obstacle = str[len - 2];
		strc->fullfill = str[len - 1];
		return (1);
	}
}

int	ft_is_number_of_lines_ok(char **charmap, int nbroflines)
{
	if (ft_tablen(charmap) == nbroflines)
		return (1);
	else
		return (0);
}

int	ft_is_line_lenghts_ok(char **charmap, int linelength)
{
	int	i;

	i = 0;
	while (charmap[i])
	{
		if (ft_strlen(charmap[i]) != linelength)
			return (0);
		i++;
	}
	return (1);
}

int	ft_size_first_line(char *map)
{
	int		fd;
	char	buff;
	int		size;

	fd = open(map, O_RDONLY);
	size = 0;
	if (fd >= 0)
	{
		while (read(fd, &buff, 1) && buff != '\n')
			size++;
		close(fd);
		return (size);
	}
	else
		return (0);
}

int	ft_is_valid_charset(char obstacle, char space, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != obstacle && map[i][j] != space)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
