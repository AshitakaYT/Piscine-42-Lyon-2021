/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:33:40 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/07 20:14:11 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int		i;
	int		carac;

	i = 0;
	carac = 1;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if ((str[i] > 'Z') || (str[i] < 'A'))
		{
			carac = 0;
		}
		i++;
	}
	return (carac);
}
