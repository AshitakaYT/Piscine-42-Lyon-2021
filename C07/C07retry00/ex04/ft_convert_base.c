/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 15:16:33 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/12 19:30:05 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_position_base(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_is_once_in_base(char *base, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (base[i])
	{
		if (base[i] == c && count == 1)
			return (0);
		else if (base[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	ft_check_base(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (!ft_is_once_in_base(base, base[i]) || \
			base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	else
		return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int			sign;
	long int	result;
	int			len;

	len = ft_strlen(base);
	sign = 1;
	result = 0;
	if (!ft_check_base(base))
		return (0);
	while (*str == '\f' || *str == '\n' || *str == '\r' \
			|| *str == '\t' || *str == '\v' || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && ft_is_once_in_base(base, *str))
	{
		result = result * len + ft_position_base(base, *str);
		str++;
	}
	return (result * sign);
}
