/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:02:43 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/29 15:19:22 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*toremove;

	if (begin_list == 0 || (*begin_list)->next == 0)
		return ;
	if ((*cmp)((*begin_list)->next->data, data_ref == 0))
	{
		toremove = (*begin_list)->next;
		(*begin_list)->next = toremove->next;
		if (free_fct)
			(*free_fct)(toremove->data);
		free(toremove);
	}
	ft_list_remove_if(&(*begin_list)->next, data_ref, cmp, free_fct);
}
