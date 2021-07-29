/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:28:33 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/29 10:17:38 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

void	ft_list_sortlol(t_list **begin_list, int (*cmp)())
{
	int		size;
	t_list	*next;
	t_list	*swap;
	t_list	*curr;

	size = ft_list_size(*begin_list);
	if (size <= 2)
		return ;
	curr = *begin_list;
	while (curr->next)
	{
		next = (curr)->next;
		while (next->next)
		{
			if ((*cmp)(curr->data, next->data) < 0)
			{
				swap->data = next->data;
				next->data = curr->data;
				curr->data = swap->data;
				next = curr->next;
			}
			next = next->next;
		}
		curr = curr->next;
	}
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*elem;

	elem = ft_create_elem(data);
	if (!elem)
		return ;
	if (*begin_list)
		elem->next = *begin_list;
	*begin_list = elem;
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	ft_list_push_front(begin_list, data);
	ft_list_sortlol(begin_list, cmp);
}
