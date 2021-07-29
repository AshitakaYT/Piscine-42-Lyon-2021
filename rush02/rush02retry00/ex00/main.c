/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 12:01:20 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/25 21:52:12 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_beautiful_header.h"

int	ft_calc_sum(int size)
{
	int	i;
	int	j;
	int	res;
	i = size;
	j = 0;
	res = 0;
	while (i >= 0)
	{
		if (i % 3 == 0)
		{
			res += i + 1;
			j++;
		}
		i--;
	}
	res += 11 * j;
	return (res);
}
char	*ft_strcatchar(char *str, char c)
{
	int	i;
	int	j;
	i = 0;
	j = 0;
	while (str[i])
	{
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	return (str);
}
char	*ft_strcat(char *str, char *src)
{
	int	i;
	int	j;
	i = 0;
	j = 0;
	while (str[i])
	{
		i++;
	}
	while (src[j])
	{
		str[i] = src[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
char	*ft_do_groups(char *result, int number, int place)
{
	int	i;
	i = 1;
	if (!(number == 0 && result[ft_strlen(result) - 1] != '1'))
	{
		if (!(place == 0 && result[ft_strlen(result) - 1] == '1'))
			result = ft_strcat(result, " \0");
		result = ft_strcatchar(result, (char) number + 48);
		if (place == 2)
		{
			result = ft_strcat(result, " 1\0");
		}
		if (!(place == 1 && number == 1))
		{
			while (i <= place)
			{
				result = ft_strcat(result, "0\0");
				i++;
			}
		}
	}
	return (result);
}
char	*ft_divide_by_three(char *result, int number, int place)
{
	int	i;
	result = ft_do_groups(result, number, (place % 3));
	if (place % 3 == 0 && (number != 0 || result[ft_strlen(result) - 2] != '0'
			|| result[ft_strlen(result) - 5] != '0'))
	{
		result = ft_strcat(result, " 1\0");
		i = 2;
		while (i <= place + 1)
		{
			result = ft_strcat(result, "0\0");
			i++;
		}
	}
	return (result);
}

char	*ft_entourloupe(char *str)
{
	int		len;
	char	*true_result;
	int		i;
	i = 0;
	len = ft_strlen(str);
	true_result = malloc((len + 1) * sizeof(char));
	if (!true_result)
		return (0);
	while (str[i])
	{
		true_result[i] = str[i];
		i++;
	}
	true_result[i] = '\0';
	free(str);
	return (true_result);
}

char	*ft_parse_argv(char *str)
{
	int		i;
	int		j;
	int		size;
	char	*result;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	i--;
	j = i;
	size = ft_calc_sum(i);
	result = malloc(size * sizeof(char));
	if (!result)
		return (0);
	result[0] = '\0';
	i = 0;
	while (i < j)
	{
		result = ft_divide_by_three(result, (int)(str[i] - 48), j - i);
		i++;
	}
	return (ft_entourloupe(result));
}

int	ft_check_necessary_numbers(struct t_dict *dictref, struct t_dict *dict)
{
	int	i;
	int j;

	i = 0;
	while (dictref[i].number)
	{
		j = 0;
		while (dict[j].number && dict[j].number != dictref[i].number)
			j++;
		if (!dict[j].number)
			return (0);
		i++;
	}
	return (1);
}

struct t_dict	*ft_make_dict(char *dictstr)
{
	struct t_dict	*dict;
	char			**lines;
	char			**nums;
	char			**keys;
	int i;

	lines = ft_get_lines(dictstr);
	if (!lines)
		return (NULL);
	if (!ft_is_double_point_ok(lines) || !ft_is_dic_ok(lines))
		return (NULL);
	nums = ft_get_nums(lines);
	if (!nums)
		return (NULL);
	keys = ft_get_keys(lines);
	if (!keys)
		return (NULL);
	if (!ft_check_duplicate_nums(nums))
		return (NULL);
	dict = ft_get_dict(nums, keys);
	ft_sort_dict(dict);
	if (!dict)
		return (NULL);
	while (dict[i].number)
	{
		ft_putstr(dict[i].number);
		i++;
	}
	return (dict);
}

char	*ft_atoa(char *av)
{
	char	*number;

	ft_get_past_whitespaces(&av);
	if (*av == '+')
		*av += 1;
	else if (*av == '-')
		return (NULL);
	if (!(*av >= '0' && *av <= '9'))
		number = ft_strndup("0", 1);
	else
		number = ft_strndup(av, ft_get_number_len(av));
	if (!number)
		return (NULL);
	return (number);
}


int ft_one_param(char *av)
{
	struct t_dict	*dict;
	char			*words;
	char			*number;
	int i;

	i = 0;

	dict = ft_make_dict("numbers.dict.txt");
	printf("\n%s\n", dict[21].number);
	while (dict[i].number)
	{
		printf("%s\n", dict[i].key);
		i++;
	}
	number = ft_atoa(av);
	if (!number)
		return (0);
	words = ft_parse_argv(number);
	if (!words)
		return (0);
	ft_putstr(words);
	ft_putchar('\n');
	ft_putstr("ca va ici\n");
	ft_print_words(words, dict);
	return (1);
}

int	ft_two_params(char *av1, char *av2)
{
	struct t_dict	*dict;
	struct t_dict	*dictref;
	char			*words;
	char			*number;

	dictref = ft_make_dict("numbers.dict.txt");
	dict = ft_make_dict(av1);
	number = ft_atoa(av2);
	if (!number)
		return (0);
	words = ft_parse_argv(number);
	if (!words || !dict || !dictref || !ft_check_necessary_numbers(dictref, dict))
		return (0);
	ft_print_words(words, dict);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_one_param(av[1]);
	}
	else if (ac == 3)
	{
		ft_two_params(av[1], av[2]);
	}
	else
	{
		ft_putstr("Error\n");
	}
}
