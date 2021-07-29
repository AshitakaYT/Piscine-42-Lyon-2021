/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 15:17:22 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/13 15:37:04 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	ft_check_base(char *base);
int	ft_is_once_in_base(char *base, char c);
int	ft_strlen(char *str);
int	ft_position_base(char *base, char c);

int	ft_get_len(int nb, char *base_to)
{
	int	i;

	i = 0;
	if (nb <= 0)
	{
		i++;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb = nb / ft_strlen(base_to);
		i++;
	}
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	nb;
	int			len;
	char		*newnbr;
	int			j;

	j = 0;
	nb = ft_atoi_base(nbr, base_from);
	len = ft_get_len(ft_atoi_base(nbr, base_from), base_to);
	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (NULL);
	newnbr = malloc((len + 1) * sizeof(char));
	if (nb < 0)
	{
		nb *= -1;
		j = 1;
	}
	while (len--)
	{
		newnbr[len] = base_to[nb % ft_strlen(base_to)];
		nb = nb / ft_strlen(base_to);
	}
	if (j == 1)
		newnbr[0] = '-';
	newnbr[ft_get_len(ft_atoi_base(nbr, base_from), base_to)] = '\0';
	return (newnbr);
}
