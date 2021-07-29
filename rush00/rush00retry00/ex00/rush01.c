/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 15:35:36 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/10 15:58:41 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_line(char a, char b, char c, int x)
{
	int	line;

	line = 1;
	while (line <= x)
	{
		if (line == 1)
			ft_putchar(a);
		else if (line > 1 && line < x)
			ft_putchar(b);
		else if (line == x)
			ft_putchar(c);
		line++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	column;

	column = 1;
	while (column <= y)
	{	
		if (column == 1)
			print_line('/', '*', 92, x);
		else if (column > 1 && column < y)
			print_line('*', ' ', '*', x);
		else if (column == y)
			print_line(92, '*', '/', x);
		column++;
	}
}
