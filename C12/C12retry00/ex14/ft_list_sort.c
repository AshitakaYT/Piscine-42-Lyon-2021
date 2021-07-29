/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:22:04 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/29 13:21:45 by aucousin         ###   ########lyon.fr   */
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

void	ft_list_sort(t_list **begin_list, int (*cmp)())
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
