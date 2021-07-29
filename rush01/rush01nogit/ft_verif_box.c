/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alheriti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 10:50:21 by alheriti          #+#    #+#             */
/*   Updated: 2021/07/18 19:33:30 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_line_left_right(char *str, int size)
{
	int	i;
	int	vue_count;
	int	max_value;

	i = 1;
	vue_count = 1;
	max_value = str[i] - '0';
	while (i < size - 1)
	{
		if (str[i] - '0' > max_value)
		{
			vue_count++;
			max_value = str[i] - '0';
		}
		i++;
	}
	if (vue_count != str[0] - '0')
	{
		return (0);
	}
	return (1);
}

int	ft_line_right_left(char *str, int size)
{
	int	i;
	int	vue_count;
	int	max_value;

	i = size - 2;
	vue_count = 1;
	max_value = str[i] - '0';
	while (i > 0)
	{
		if (str[i] - '0' > max_value)
		{
			vue_count++;
			max_value = str[i] - '0';
		}
		i--;
	}
	if (vue_count != str[size - 1] - '0')
		return (0);
	return (1);
}

int	ft_column_up_down(char **tab, int x, int size)
{
	int	i;
	int	vue_count;
	int	max_value;

	i = 1;
	vue_count = 1;
	max_value = tab[i][x] - '0';
	while (i < size - 1)
	{
		if (tab[i][x] - '0' > max_value)
		{
			vue_count++;
			max_value = tab[i][x] - '0';
		}
		i++;
	}
	if (vue_count != tab[0][x] - '0')
		return (0);
	return (1);
}

int	ft_column_down_up(char **tab, int x, int size)
{
	int	i;
	int	vue_count;
	int	max_value;

	i = size - 2;
	vue_count = 1;
	max_value = tab[i][x] - '0';
	while (i > 0)
	{
		if (tab[i][x] - '0' > max_value)
		{
			vue_count++;
			max_value = tab[i][x] - '0';
		}
		i--;
	}
	if (vue_count != tab[size - 1][x] - '0')
		return (0);
	return (1);
}

int	ft_is_valid_board(char **tab, int size)
{
	int	i;
	int	j;

	j = 1;
	i = 1;
	while (i < size - 1)
	{
		if (ft_line_left_right(tab[i], size)
			&& ft_line_right_left(tab[i], size))
			i++;
		else
			return (0);
	}
	while (j < size - 1)
	{
		if (ft_column_up_down(tab, j, size) && ft_column_down_up(tab, j, size))
			j++;
		else
			return (0);
	}
	return (1);
}
