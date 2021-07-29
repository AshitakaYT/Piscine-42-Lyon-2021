/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:29:24 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/08 15:15:58 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	j;
	unsigned int	lend;
	unsigned int	lens;

	lend = ft_strlen(dest);
	lens = ft_strlen(src);
	j = 0;
	if (size == 0)
		return (lens);
	while (src[j] && lend + j < size - 1)
	{
		dest[lend + j] = src[j];
		j++;
	}
	if (j < size)
		dest[lend + j] = '\0';
	return (lend + lens);
}
