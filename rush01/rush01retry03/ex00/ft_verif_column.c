/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_column.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alheriti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:15:42 by alheriti          #+#    #+#             */
/*   Updated: 2021/07/18 19:20:47 by alheriti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_column_up_down2(char **tab, int x, int size, int y)
{
	int	i;
	int	vue_count;
	int	max_value;

	i = 1;
	if (tab[i][x] == '0')
		vue_count = 0;
	else
		vue_count = 1;
	max_value = tab[i][x];
	while (i < size - 1 && i <= y)
	{
		if (tab[i][x] > max_value)
		{
			vue_count++;
			max_value = tab[i][x];
		}
		i++;
	}
	if (vue_count <= tab[0][x] - '0')
		return (1);
	return (0);
}

int	ft_column_down_up2(char **tab, int x, int size, int y)
{
	int	i;
	int	vue_count;
	int	max_value;

	i = size - 2;
	if (tab[i][x] == '0')
		vue_count = 0;
	else
		vue_count = 1;
	max_value = tab[i][x];
	while (i > 0 && i <= size - 1 - y)
	{
		if (tab[i][x] > max_value)
		{
			vue_count++;
			max_value = tab[i][x];
		}
		i--;
	}
	if (vue_count <= tab[size - 1][x] - '0')
		return (1);
	return (0);
}

int	ft_is_empty_column(char **tab, int column)
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if (tab[column][i] != '0')
			return (0);
		i++;
	}
	return (1);
}
