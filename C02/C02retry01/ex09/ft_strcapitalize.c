/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 06:45:54 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/08 11:16:27 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char str)
{
	int		carac;

	carac = 1;
	if ((str > 'Z' || str < 'A') \
			&& (str > 'z' || str < 'a') \
		   	 && (str < '0' || str > '9'))
		carac = 0;
	return (carac);
}

int	ft_str_is_numeric(char str)
{
	int		carac;

	carac = 1;
	if ((str > '9') || (str < '0'))
		carac = 0;
	return (carac);
}

int	ft_str_is_lowercase(char str)
{
	int		carac;

	carac = 1;
	if ((str > 'z') || (str < 'a'))
		carac = 0;
	return (carac);
}

int	ft_str_is_uppercase(char str)
{
	int		carac;

	carac = 1;
	if ((str > 'Z') || (str < 'A'))
		carac = 0;
	return (carac);
}

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_str_is_lowercase(str[i]) \
				&& (ft_str_is_alpha(str[i + 1])) \
				&& (i == 0 || !ft_str_is_alpha(str[i - 1])))
			str[i] -= 32;
		else if (ft_str_is_uppercase(str[i]) \
				&& ft_str_is_alpha(str[i - 1]))
			str[i] += 32;
		i++;
	}
	return (str);
}
