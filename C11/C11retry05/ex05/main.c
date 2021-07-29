/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 07:42:06 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/22 11:56:32 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_beautiful_header.h"

void	ft_operate(int a, int b, void (*f)(int, int))
{
	(*f)(a, b);
	ft_putchar('\n');
}

void	ft_do_op(char **av)
{
	if (av[2][0] == '+')
		ft_operate(ft_atoi(av[1]), ft_atoi(av[3]), ft_add);
	else if (av[2][0] == '-')
		ft_operate(ft_atoi(av[1]), ft_atoi(av[3]), ft_sub);
	else if (av[2][0] == '*')
		ft_operate(ft_atoi(av[1]), ft_atoi(av[3]), ft_mul);
	else if (av[2][0] == '/')
	{
		if (ft_atoi(av[3]) == 0)
			ft_putstr("Stop : division by zero\n");
		else
			ft_operate(ft_atoi(av[1]), ft_atoi(av[3]), ft_div);
	}
	else if (av[2][0] == '%')
	{
		if (ft_atoi(av[3]) == 0)
			ft_putstr("Stop : modulo by zero\n");
		else
			ft_operate(ft_atoi(av[1]), ft_atoi(av[3]), ft_mod);
	}
}

int	main(int ac, char **av)
{
	if (!ft_check_args(ac))
		return (0);
	if (ft_strlen(av[2]) != 1 || !(av[2][0] == '+'
		|| av[2][0] == '-' || av[2][0] == '/'
		|| av[2][0] == '%' || av[2][0] == '*'))
		ft_putstr("0\n");
	else
		ft_do_op(av);
	return (0);
}
