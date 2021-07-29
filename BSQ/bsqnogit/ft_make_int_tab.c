/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:52:47 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/28 00:05:57 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_make_solution(struct s_map *str)
{
	int	x;
	int	y;

	y = 0;
	while (y < str->maxsize)
	{
		x = 0;
		while (x < str->maxsize)
		{
			str->mapchar[str->ymaxpos + y][str->xmaxpos + x] = 'x';
			x++;
		}
		y++;
	}
}

int	ft_is_parsing_ok(struct s_map *str)
{
	if (!ft_is_first_line_ok(str, str->fullmapchar[0])
		|| !ft_is_number_of_lines_ok(str->mapchar, str->nbroflines)
		|| !ft_is_line_lenghts_ok(str->mapchar, str->linelength)
		|| !ft_is_valid_charset(str->obstacle, str->space, str->mapchar))
	{
		return (0);
	}
	else
		return (1);
}

int	ft_bsq(char *av)
{
	struct s_map	str;

	if (!ft_get_file(av))
		return (0);
	str.file = ft_get_file(av);
	if (str.file[ft_strlen(str.file) - 1] != '\n')
		return (0);
	if (!str.file)
		return (0);
	str.fullmapchar = ft_split(str.file, "\n");
	if (!str.fullmapchar)
		return (0);
	str.mapchar = &str.fullmapchar[1];
	if (!str.mapchar)
		return (0);
	if (!ft_is_parsing_ok(&str))
		return (0);
	str.xsize = ft_strlen(str.mapchar[0]);
	str.ysize = ft_tablen(str.mapchar);
	str.mapint = ft_create_int_tab(str.xsize, str.ysize);
	ft_make_int_tab(str.mapint, str.mapchar, 'o');
	ft_get_solution(&str, 0, 0, 1);
	ft_make_solution(&str);
	ft_print_char_tab(str.mapchar);
	return (1);
}

int	ft_bsq2(char *av)
{
	struct s_map	str;

	str.file = av;
	if (av[ft_strlen(av) - 1] != '\n')
		return (0);
	str.fullmapchar = ft_split(str.file, "\n");
	if (!str.fullmapchar)
		return (0);
	str.mapchar = &str.fullmapchar[1];
	if (!str.mapchar)
		return (0);
	if (!ft_is_parsing_ok(&str))
		return (0);
	str.xsize = ft_strlen(str.mapchar[0]);
	str.ysize = ft_tablen(str.mapchar);
	str.mapint = ft_create_int_tab(str.xsize, str.ysize);
	ft_make_int_tab(str.mapint, str.mapchar, 'o');
	ft_get_solution(&str, 0, 0, 1);
	ft_make_solution(&str);
	ft_print_char_tab(str.mapchar);
	return (1);
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
	{
		if (!ft_bsq2(ft_scooter()))
			write(2, "map error\n", 10);
	}
	else
	{
		while (i < ac)
		{
			if (!ft_bsq(av[i]))
				write(2, "map error\n", 10);
			if (i + 1 != ac)
				write(1, "\n", 1);
			i++;
		}
		return (0);
	}
}
