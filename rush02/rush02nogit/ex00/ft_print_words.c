/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 20:41:33 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/25 21:49:12 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_beautiful_header.h"

void	ft_print_words(char *numbers, struct t_dict *dict)
{
	int	i;
	int	j;

	i = 0;
	while (numbers[i])
	{
		if (numbers[i] != ' ')
		{
			j = 0;
			while (dict[j].number)
			{
				if (ft_strncmp(&numbers[i], dict[j].number,
						ft_nbrlen(&numbers[i])) == 0)
				{
					ft_putstr(dict[j].key);
					ft_putchar(' ');
				}
				j++;

				printf("J : %d\n", j);
	//			printf("DICT J NBR : %s\n", dict[j].number);
	//			printf("DICT J KEY : %s\n", dict[j].key);
				printf("numbers = %s\n", &numbers[i]);
				printf("len nbr = %i\n", ft_nbrlen(&numbers[i]));
			}
			i += ft_nbrlen(&numbers[i]);
		}
		else
			i++;
	}
	ft_putstr("RAS\n");
}
