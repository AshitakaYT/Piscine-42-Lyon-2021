/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:30:09 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/07 20:04:23 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int		i;
	int		carac;

	i = 0;
	carac = 1;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if ((str[i] > '9') || (str[i] < '0'))
		{
			carac = 0;
		}
		i++;
	}
	return (carac);
}
