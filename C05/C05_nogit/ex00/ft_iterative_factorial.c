/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:30:49 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/09 14:45:26 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int firstnb;

	i = 1;
	firstnb = nb;
	if (nb == 0)
		return (1);
	else if (nb < 0)
		return(0);
	while (i < firstnb)
	{
		nb = nb * (firstnb - i);
		i++;
		printf("%d\n", nb);
	}
	return (nb);
}
