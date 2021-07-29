/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alheriti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 10:50:21 by alheriti          #+#    #+#             */
/*   Updated: 2021/07/18 19:47:49 by alheriti         ###   ########lyon.fr   */
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

int	ft_line_left_right2(char *str, int size, int x)
{
	int	i;
	int	vue_count;
	int	max_value;

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
	if (vue_count <= str[size - 1] - '0')
		return (1);
	return (0);
}
