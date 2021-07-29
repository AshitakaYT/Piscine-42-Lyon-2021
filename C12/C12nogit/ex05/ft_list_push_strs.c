/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 07:20:56 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/20 08:25:18 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list *mylist;

	mylist = malloc(sizeof(t_list));
	if (!mylist)
		return (NULL);
	mylist->next = NULL;
	mylist->data = data;
	return (mylist);
}


t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*list;
	int i;

	i = 0;
	while (i < size)
	{
		if (!list)
		{
			list = ft_create_elem(strs[i]);
		}
		else
		{
			while (list)
			{
				list = list->next;
			}
			list = ft_create_elem(strs[i]);
		}
	}
	return(list);
}

void afficherListe(t_list liste)
{
    t_list *tmp = &liste;
    /* Tant que l'on n'est pas au bout de la liste */
    while(tmp != NULL)
    {
        /* On affiche */
        printf("%d ", tmp->data);
        /* On avance d'une case */
        tmp = tmp->next;
    }
}

int main(int ac, char **av)
{
	t_list	*list;
	int i;

	list = ft_list_push_strs(ac, av);
	afficherListe(*list);
}
