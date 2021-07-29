/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:03:53 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/19 10:06:04 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int lenght, int(*f)(char*))
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < lenght)
	{
		if ((f)(tab[i]) != 0)
			count++;
		i++;
	}
	return (count);
}
