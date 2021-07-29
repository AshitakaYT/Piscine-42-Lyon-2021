/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:04:54 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/28 17:50:29 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	if (!*begin_list1)
		(*begin_list1)->next = begin_list2;
	else if ((*begin_list1)->next)
		ft_list_merge(&(*begin_list1)->next, begin_list2);
	else
		(*begin_list1)->next = begin_list2;
}
