/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouriol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 13:39:57 by mcouriol          #+#    #+#             */
/*   Updated: 2021/07/25 08:34:38 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_calc_sum(int size)
{
	int	i;
	int res;

	i = size;
	res = 0;
	while (i > 0)
	{
		res += i;
		i--;
	}
	return(res);
}

char	*ft_strcatchar(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
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
		i++;
	while(src[j])
	{
		str[i] = src[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char *ft_do_groups(char *result, int number, int place)
{
	char *to_cat;
	int	i;

	i = 1;
	result = ft_strcatchar(result, ' ');
	result = ft_strcatchar(result, (char) number + 48);
	to_cat = malloc((place + 2) * sizeof(char));
	if (!to_cat)
		return (0);
	if (place == 2)
	{
		result = ft_strcatchar(result, ' ');
		to_cat[0] = '1';
	}
	while (i <= place)
	{
		to_cat = ft_strcat(to_cat, "0");
		i++;
	}
	result = ft_strcat(result, to_cat);
	return (result);
}

char *ft_divide_by_three(char *result, int number, int place)
{
	int	i;
	char *to_cat;
	
	result = ft_do_groups(result, number, (place % 3));
	if (place % 3 == 0)
	{
		to_cat = malloc((place + 2) * sizeof(char));
		if (!to_cat)
			return(0);
		to_cat[0] = ' ';
		to_cat[1] = '1';
		i = 2;
		while (i <= place + 1)
		{
			to_cat[i] = '0';
			i++;
		}
		result = ft_strcat(result, to_cat);
	}
	return (result);
}

char *ft_parse_argv(char *str)
{
	int	i;
	int	j;
	int	size;
	char *result;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	i--;
	j = i;
	size = ft_calc_sum(i);
	result = malloc(size + 100 * sizeof(char));
	if (!result)
		return (0);
	i = 0;
	while (i <= j)
	{
		ft_divide_by_three(result, (int) (str[i] - 48), j - i);
		i++;
	}
	return (result);
}
