/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:17:09 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/13 15:39:52 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_in_charset(char *charset, char c)
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

char	*ft_strndup(char *src, int n)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[j])
		j++;
	dest = malloc((j + 1) * sizeof(char));
	while (i < j && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!ft_is_in_charset(charset, str[i]) && i == 0)
			count++;
		if (ft_is_in_charset(charset, str[i]))
		{
			while (str[i] && ft_is_in_charset(charset, str[i]))
			{
				i++;
			}
			if (str[i])
			{
				count++;
				i--;
			}
		}
		i++;
	}
	return (count);
}

int	ft_len_word(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !ft_is_in_charset(charset, str[i]))
		i++;
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	j = 0;
	split = malloc(sizeof (char *) * (ft_count_words(str, charset) + 1));
	while (i < ft_count_words(str, charset))
	{
		while (str[j] && ft_is_in_charset(charset, str[j]))
		{
			j++;
		}
		if (str[j])
		{
			split[i] = ft_strndup(&str[j], ft_len_word(&str[j], charset));
			j += ft_len_word(&str[j], charset);
		}
		i++;
	}
	split[i] = malloc(1 * sizeof(char));
	return (split);
}