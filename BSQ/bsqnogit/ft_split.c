/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kestucke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 09:32:53 by kestucke          #+#    #+#             */
/*   Updated: 2021/07/27 13:18:29 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include "header.h"

int	ft_is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	count;
	int	count_word;

	count_word = 0;
	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_is_in_charset(str[i], charset))
			count_word = 0;
		else if (count_word == 0)
		{
			count_word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_word(char *str, char *charset)
{
	int	j;

	j = 0;
	while (str[j] && (!(ft_is_in_charset(str[j], charset))))
	{		
		j++;
	}
	return (j);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int		i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**split;

	j = 0;
	i = 0;
	split = malloc(sizeof(char *) * ft_count_words(str, charset) + 1);
	while (j < ft_count_words(str, charset))
	{
		while (ft_is_in_charset(str[i], charset))
			++i;
		if (str[i])
		{
			split[j] = malloc(sizeof(char) * (ft_word(&str[i], charset) + 1));
			split[j] = ft_strncpy(split[j], &str[i], ft_word(&str[i], charset));
			i += ft_word(&str[i], charset) + 1;
		}
		j++;
	}
	split[j] = 0;
	return (split);
}
