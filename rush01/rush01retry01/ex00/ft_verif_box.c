/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alheriti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 10:50:21 by alheriti          #+#    #+#             */
/*   Updated: 2021/07/18 11:39:55 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_line_left_right(char *str, int size)
{
	int	i;
	int	vue_count;
	int max_value;

	i = 1;
	vue_count = 1;
	max_value = str[i];
	while (i < size - 1)
	{
		if (str[i] > max_value)
		{
			vue_count++;
			max_value = str[i];
		}
		i++;
	}
	if (vue_count != str[0])
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
	max_value = str[i];
	while (i > 0)
	{
		if (str[i] > max_value)
		{
			vue_count++;
			max_value = str[i];
		}
		i--;
	}
	if (vue_count != str[size-1])
		return (0);
	return (1);
}

int	ft_column_up_down(char **tab, int x, int size)
{
	int	i;
	int	vue_count;
	int max_value;

	i = 1;
	vue_count = 1;
	max_value = tab[i][x];
	while (i < size - 1)
	{
		if (tab[i][x] > max_value)
		{
			vue_count++;
			max_value = tab[i][x];
		}
		i++;
	}
	if (vue_count != tab[0][x])
		return (0);
	return (1);
}

int	ft_column_down_up(char **tab, int x, int size)
{
	int	i;
	int	vue_count;
	int max_value;

	i = size - 2;
	vue_count = 1;
	max_value = tab[i][x];
	while (i > 0)
	{
		if (tab[i][x] > max_value)
		{
			vue_count++;
			max_value = tab[i][x];
		}
		i--;
	}
	if (vue_count != tab[size - 1][x])
		return (0);
	return (1);
}

int	ft_is_valid_board(char **tab, int size)
{
	int i;
	int j;

	j = 1;
	i = 1;
	while (i < size - 1)
	{
		if (ft_line_left_right(tab[i], size) && ft_line_right_left(tab[i], size))
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

int	ft_line_left_right2(char *str, int size, int x)
{
	int	i;
	int	vue_count;
	int max_value;

	i = 1;
	if (str[i] == '0')
		vue_count = 0;
	else
		vue_count = 1;
	max_value = str[i];
	while (i < size - 1 && i <= x)
	{
		if (str[i] > max_value)
		{
			vue_count++;
			max_value = str[i];
		}
		i++;
	}
	printf("vue line left right : %d\n", vue_count);
	printf("str[0]  line left right : %d\n", str[0] - '0');
	if (vue_count <= str[0] - '0')
		return (1);
	return (0);
}

int	ft_line_right_left2(char *str, int size, int x)
{
	int	i;
	int	vue_count;
	int	max_value;

	i = size - 2;
	if (str[i] == '0')
		vue_count = 0;
	else
		vue_count = 1;
	max_value = str[i];
	while (i > 0 && i <= size - 1 - x)
	{
		if (str[i] > max_value)
		{
			vue_count++;
			max_value = str[i];
		}
		i--;
	}
	printf("vue line right left : %d\n", vue_count);
	printf("str[size - 1]  line right left : %d\n", str[size - 1] - '0');
	if (vue_count <= str[size - 1] - '0')
		return (1);
	return (0);
}

int	ft_column_up_down2(char **tab, int x, int size, int y)
{
	int	i;
	int	vue_count;
	int max_value;

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
	printf("vue column up down : %d\n", vue_count);
	printf("tab[0][x] column up down : %d\n", tab[0][x] - '0');
	if (vue_count <= tab[0][x] - '0')
		return (1);
	return (0);
}

int	ft_column_down_up2(char **tab, int x, int size, int y)
{
	int	i;
	int	vue_count;
	int max_value;

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
	printf("vue column down up : %d\n", vue_count);
	printf("tab[0][x] column down up : %d\n", tab[size - 1][x] - '0');
	if (vue_count <= tab[size - 1][x] - '0')
		return (1);
	return (0);
}
