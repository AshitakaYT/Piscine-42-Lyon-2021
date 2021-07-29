/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:32:39 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/07 20:12:37 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int		i;
	int		carac;

	i = 0;
	carac = 1;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if ((str[i] > 'z') || (str[i] < 'a'))
		{
			carac = 0;
		}
		i++;
	}
	return (carac);
}
