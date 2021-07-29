/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 06:47:26 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/20 06:50:11 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

t_list *ft_list_last(t_list *begin_list)
{
	while (begin_list)
		begin_list = begin_list->next;
	return (begin_list);
}

