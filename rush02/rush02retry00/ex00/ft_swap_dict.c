/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 20:40:27 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/25 09:33:55 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_beautiful_header.h"

void	ft_swap_dict(struct t_dict *dict1, struct t_dict *dict2)
{
	struct t_dict	swap;

	swap = *dict1;
	*dict1 = *dict2;
	*dict2 = swap;
}
