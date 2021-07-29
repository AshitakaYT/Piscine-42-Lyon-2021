/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:35:05 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/07 20:26:11 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int		i;
	int		carac;

	i = 0;
	carac = 1;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if ((str[i] < 32) || (str[i] == 127))
		{
			carac = 0;
		}
		i++;
	}
	return (carac);
}
