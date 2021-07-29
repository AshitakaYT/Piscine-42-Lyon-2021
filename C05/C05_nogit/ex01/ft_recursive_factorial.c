/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:47:13 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/09 14:55:10 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return(0);
	else if (nb > 1)
		nb *= ft_recursive_factorial(nb -1);
	else
		return (1);
	return (nb);
}

int	main()
{
	printf("%d", ft_recursive_factorial(0));
}
