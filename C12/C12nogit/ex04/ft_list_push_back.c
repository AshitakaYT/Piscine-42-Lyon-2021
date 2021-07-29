/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 06:50:37 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/20 07:22:30 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list last;

	last = ft_create_elem(data);
	last->next = NULL;
	if (!*begin_list)
		return (last);
	else
	{
		while (*begin_list->next != NULL)
		{
			*begin_list = *begin_list->next;
		}
		*begin_list->next = last;
		return (begin_list);
}
