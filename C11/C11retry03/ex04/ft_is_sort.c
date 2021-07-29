/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:07:19 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/19 20:17:41 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int lenght, int(*f)(int, int))
{
	int	i;

	i = 0;
	if (lenght <= 2)
		return (1);
	while (i < lenght - 2 && (f)(tab[i], tab[i + 1]) == 0)
		i++;
	if (i == lenght - 2)
		return (1);
	else if ((f)(tab[i], tab[i + 1]) > 0)
	{
		while (i < lenght - 2 && (f)(tab[i], tab[i + 1]) >= 0)
			i++;
		if (i == lenght - 2 && (f)(tab[i], tab[i + 1]) >= 0)
			return (1);
	}
	else if ((f)(tab[i], tab[i + 1]) < 0)
	{
		while (i < lenght - 2 && (f)(tab[i], tab[i + 1]) <= 0)
			i++;
		if (i == lenght - 2 && (f)(tab[i], tab[i + 1]) <= 0)
			return (1);
	}
	return (0);
}
