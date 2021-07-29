/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 12:01:20 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/24 20:34:02 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "ft_beautiful_header.h"
#define BUF_SIZE 4096


//void	fill_struct(char **split, )



char	**ft_get_lines(char *dic)
{
	int 	fd;
	int 	ret;
	char	buf[BUF_SIZE + 1];
	char	**split;
	int i;
	
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

int	ft_tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_is_double_point_ok(char **lines)
{
	int i;
	int j;
	int count;

	i = 0;
	while (lines[i])
	{
		j = 0;
		count = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == ':')
				count++;
			j++;
		}
		if (count != 1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_dic_ok(char **lines) // PAS TERMINEE
{
	int i;
	int j;

	i = 0;
	if (ft_is_double_point_ok(lines))
	{
		while (lines[i])
		{
			j = 0;
			while (lines[i][j] != ':')
				j++;
			j++;
			while (lines[i][j] == ' ')
				j++;
			if (lines[i][j] > 32 && lines[i][j] < 127)
				while (lines[i][j] > 32 && lines[i][j] < 127)
					j++;
			else
				return (0);
			if (j != ft_strlen(lines[i]))
				return (0);
			i++;
		}
	}
	return (1);
}

char	**ft_get_nums(char **lines)
{
	char **nums;
	int	i;
	int j;
	int count;

	nums = malloc(sizeof(char *) * (ft_tablen(lines) + 1));
	if (!nums)
		return (NULL);
	i = 0;
	while (lines[i])
	{
		j = 0;
		count = 0;
		while (lines[i][j] == '\f' || lines[i][j] == '\n' || lines[i][j] == '\r'\
			   || lines[i][j] == '\t' || lines[i][j] == '\v' || lines[i][j] == ' ')
			j++;
		if (lines[i][j] == '+')
			j++;
		else if (lines[i][j] == '-')
			return (NULL);
		if (!(lines[i][j] >= '0' && lines[i][j] <= '9'))
		{
			lines[i][j] = '0';
			count++;
		}
		else
			while (lines[i][j + count] >= '0' && lines[i][j + count] <= '9')
				count++;
		nums[i] = ft_strndup(&lines[i][j], count);
		if (!nums[i])
			return (NULL);
		i++;
	}
	nums[i] = malloc(sizeof(char));
	if (!nums[i])
		return (NULL);
	nums[i] = 0;
	return (nums);
}

int	ft_check_duplicate_nums(char **nums)
{
	int i;
	int j;

	i = 0;
	while (nums[i])
	{
		j = i + 1;
		while (nums[j])
		{
			if (ft_strcmp(nums[i], nums[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**ft_get_keys(char **lines)
{
	char	**keys;
	int 	i;
	int 	j;
	int 	count;

	keys = malloc(sizeof(char *) * (ft_tablen(lines) + 1));
	if (!keys)
		return (NULL);
	i = 0;
	while (lines[i])
	{
		j = 0;
		count = 0;
		while (lines[i][j] != ':')
			j++;
		j++;
		while (lines[i][j] == ' ')
			j++;
		while (lines[i][j + count] > 32 && lines[i][j + count] < 127)
			count++;
		keys[i] = ft_strndup(&lines[i][j], count);
		if (!keys[i])
			return (NULL);
		i++;
	}
	keys[i] = malloc(sizeof(char));
	if (!keys[i])
		return (NULL);
	keys[i] = 0;
	return(keys);
}

struct	dict	*ft_get_dict(char **nums, char **keys)
{
	dict	*dict;
	int i;

	i = 0;
	dict = malloc(sizeof(dict) * (ft_tablen(nums) + 1));
	if (!dict)
		return (NULL);
	while (i < ft_tablen(nums))
	{
		dict[i].key = keys[i];
		dict[i].number = nums[i];
		i++;
	}
	dict[i].number = 0;
	return (dict);
}

void	ft_swap_dict(struct dict *dict1, struct dict *dict2)
{
	struct	dict	swap;

	swap = *dict1;
	*dict1 = *dict2;
	*dict2 = swap;
}

void	ft_sort_dict(struct dict *dict)
{
	int				i;
	int				j;
	struct	dict	swap;

	i = 0;
	while (dict[i].number)
	{
		j = i + 1;
		while (dict[j].number)
		{
			if (ft_strlen(dict[i].number) > ft_strlen(dict[j].number))
			{
				swap = dict[j];
				dict[j] = dict[i];
				dict[i] = swap;
				j = i + 1;
			}
			else if (ft_strlen(dict[i].number) == ft_strlen(dict[j].number)
					&& ft_strcmp(dict[i].number, dict[j].number) > 0)
			{
				swap = dict[j];
				dict[j] = dict[i];
				dict[i] = swap;
				j = i + 1;
			}
			j++;
		}
		i++;
	}
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s2[i] && s1[i] == s2[i] && i < n)
	{
		i++;
	}
	if (i == ft_strlen(s2) && i == n)
		return (0);
	else
		return (1);
}

int	ft_nbrlen(char *nbr)
{
	int i;

	i = 0;
	while (nbr[i] && nbr[i] != ' ')
		i++;
	return (i);
}

void	ft_print_words(char *numbers, struct dict *dict)
{
	int i;
	int j;

	i = 0;
	while (numbers[i])
	{
		if (numbers[i] != ' ')
		{
			j = 0;
			while (dict[j].number)
			{
				if (ft_strncmp(&numbers[i], dict[j].number, ft_nbrlen(&numbers[i])) == 0)
				{
					ft_putstr(dict[j].key);
					ft_putchar(' ');
				}
				j++;
			}
			i += ft_nbrlen(&numbers[i]);
		}
		else
			i++;
	}
}

int main(int ac, char **av)
{
	dict	*dict;
	char	**lines;
	char	**nums;
	char	**keys;
	char	*words;
	int		i;

	if (ac == 2)
	{
		i = 0;
		lines = ft_get_lines("numbers.dict.txt");
		if (!lines)
			return (0);
		if (!ft_is_double_point_ok(lines) || !ft_is_dic_ok(lines))
			return (0);
		nums = ft_get_nums(lines);
		if (!nums)
			return (0);
		keys = ft_get_keys(lines);
		if (!keys)
			return (0);
		if (ft_check_duplicate_nums(nums))
		{
			dict = ft_get_dict(nums, keys);
			ft_sort_dict(dict);
			if (!dict)
				return (0);
			while (dict[i].number)
			{
				ft_putstr(dict[i].number);
				ft_putchar('\n');
				ft_putstr(dict[i].key);
				ft_putchar('\n');
				i++;
			}
			words = ft_parse_argv(av[1]);
			ft_putstr(words);
			ft_putchar('\n');

			ft_print_words(words, dict);
		}
	}
}
