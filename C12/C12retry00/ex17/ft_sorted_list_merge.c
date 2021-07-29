/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:38:37 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/29 10:24:14 by aucousin         ###   ########lyon.fr   */
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

void	ft_list_sort_lol(t_list **begin_list, int (*cmp)())
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

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	if (!*begin_list1)
		(*begin_list1)->next = begin_list2;
	else if ((*begin_list1)->next)
		ft_list_merge(&(*begin_list1)->next, begin_list2);
	else
		(*begin_list1)->next = begin_list2;
}

void	ft_sorted_list_merge(t_list **begin_list1,
		t_list *begin_list2, int (*cmp)())
{
	ft_list_merge(begin_list1, begin_list2);
	ft_list_sort_lol(begin_list1, cmp);
}
