/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 12:22:33 by aucousin          #+#    #+#             */
/*   Updated: 2021/07/29 10:23:17 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

t_list	*ft_create_elem(void *data)
{
	t_list *list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->next = NULL;
	list->data = data;
	return (list);
}

/*----------------------------------------------------------------------------*/
/*------------------------------- FT LIST SIZE -------------------------------*/
/*----------------------------------------------------------------------------*/

int	ft_list_size(t_list *begin_list)
{
	int size;

	size = 0;
		while (begin_list)
		{
			size++;
			begin_list = begin_list->next;
		}
	return (size);
}

/*----------------------------------------------------------------------------*/
/*----------------------------- FT PRINT LIST --------------------------------*/
/*----------------------------------------------------------------------------*/

void	ft_print_list(t_list *li)
{
	if (!li)
		{
			printf("La liste est vide, rien a afficher\n");
			return ;
		}
	while (li)
	{
		printf("%s\n", li->data);
		li = li->next;
	}
}

/*----------------------------------------------------------------------------*/
/*--------------------------- FT LIST PUSH BACK ------------------------------*/
/*----------------------------------------------------------------------------*/

void	ft_list_push_back(t_list **begin_list, void *data)
{
	if (!*begin_list)
		*begin_list = ft_create_elem(data);
	else if ((*begin_list)->next)
		ft_list_push_back(&(*begin_list)->next, data);
	else
		(*begin_list)->data = data;
}

/*----------------------------------------------------------------------------*/
/*-------------------------- FT LIST PUSH FRONT ------------------------------*/
/*----------------------------------------------------------------------------*/

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *elem;

	elem = ft_create_elem(data);
	if (!elem)
		return;
	if (*begin_list)
		elem->next = *begin_list;
	*begin_list = elem;
}

/*----------------------------------------------------------------------------*/
/*-------------------------- FT LIST POP BACK --------------------------------*/
/*----------------------------------------------------------------------------*/

void	ft_list_pop_back(t_list **begin_list)
{
	t_list *temp;
	t_list *before;

	if (!*begin_list)
		return ;
	if ((*begin_list)->next == NULL)
		return ;
	temp = *begin_list;
	before = *begin_list;
	while (temp->next != NULL)
	{
		before = temp;
		temp = temp->next;
	}
	before->next = NULL;
	temp = NULL;
}

/*----------------------------------------------------------------------------*/
/*-------------------------- FT LIST LAST ------------------------------------*/
/*----------------------------------------------------------------------------*/

t_list *ft_list_last(t_list *begin_list)
{
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}

/*----------------------------------------------------------------------------*/
/*-------------------------- FT LIST POP FRONT -------------------------------*/
/*----------------------------------------------------------------------------*/

void	ft_list_pop_front(t_list **begin_list)
{
	t_list *elem;

	if (!begin_list)
		return ;
	elem = ft_create_elem((*begin_list)->next->data);
	if (!elem)
		return;
	elem = (*begin_list)->next;
	*begin_list = NULL;
	begin_list = &elem;
	
}

/*----------------------------------------------------------------------------*/
/*-------------------------- FT LIST PUSH STRS -------------------------------*/
/*----------------------------------------------------------------------------*/

t_list	*ft_list_push_strs(int size, char **strs)
{
	int i;
	t_list *list;

	list = ft_create_elem(strs[0]);
	i = 1;
	while (i < size)
	{
		ft_list_push_front(&list, strs[i]);
		i++;
	}
	return (list);
}

/*----------------------------------------------------------------------------*/
/*-------------------------- FT LIST PUSH STRS -------------------------------*/
/*----------------------------------------------------------------------------*/

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	if(!begin_list)
		return;
	ft_list_clear(begin_list->next, (*free_fct));
	(free_fct)(begin_list->data);
	free(begin_list);
}

/*----------------------------------------------------------------------------*/
/*-------------------------- FT LIST AT --------------------------------------*/
/*----------------------------------------------------------------------------*/

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int i;
	
	i = 1;
	if (!begin_list)
		return (NULL);
	while (begin_list && i < nbr)
	{
		begin_list = begin_list->next;
		i++;
	}
	if (i == nbr)
		return (begin_list);
	return (NULL);
}

/*----------------------------------------------------------------------------*/
/*-------------------------- FT LIST REVERSE ---------------------------------*/
/*----------------------------------------------------------------------------*/

void	ft_list_reverse(t_list **begin_list)
{
	t_list *next;
	t_list *prev;

	prev = NULL;
	while (*begin_list)
	{
		next = (*begin_list)->next;
		(*begin_list)->next = prev;
		prev = *begin_list;
		*begin_list = next;
	}
	*begin_list = prev;
}


/*----------------------------------------------------------------------------*/
/*-------------------------- FT LIST FOREACH ---------------------------------*/
/*----------------------------------------------------------------------------*/

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	if(!begin_list)
		return;
	(*f)(begin_list->data);
	ft_list_foreach(begin_list->next, (*f));
}

/*----------------------------------------------------------------------------*/
/*-------------------------- FT LIST FOREACH IF ------------------------------*/
/*----------------------------------------------------------------------------*/

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)())
{
	if(!begin_list)
		return;
	if ((*cmp)(begin_list->data, data_ref) == 0)
		(*f)(begin_list->data);
	ft_list_foreach_if(begin_list->next, (*f), data_ref, (*cmp));
}

/*----------------------------------------------------------------------------*/
/*-------------------------- FT LIST FIND ------------------------------------*/
/*----------------------------------------------------------------------------*/

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	if (!begin_list)
		return (NULL);
	if ((*cmp)(begin_list->data, data_ref) == 0)
		return (begin_list);
	return (ft_list_find(begin_list, data_ref, (*cmp)));
}

/*----------------------------------------------------------------------------*/
/*-------------------------- FT LIST REMOVE IF -------------------------------*/
/*----------------------------------------------------------------------------*/

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2);

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list *prev;
	t_list *next;
	while (ft_list_find(*begin_list, data_ref, cmp))
	{
		next = ft_list_find(*begin_list, data_ref, cmp)->next;
		(*free_fct)(ft_list_find(*begin_list, data_ref, cmp)->data);
		free(ft_list_find(*begin_list, data_ref, cmp));
		ft_list_merge(&(*begin_list), next);
	}
}



/*----------------------------------------------------------------------------*/
/*-------------------------- FT LIST MERGE -----------------------------------*/
/*----------------------------------------------------------------------------*/

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	if (!*begin_list1)
		(*begin_list1)->next = begin_list2;
	else if ((*begin_list1)->next)
		ft_list_merge(&(*begin_list1)->next, begin_list2);
	else
		(*begin_list1)->next = begin_list2;
}

/*----------------------------------------------------------------------------*/
/*-------------------------- FT LIST SORT ------------------------------------*/
/*----------------------------------------------------------------------------*/

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int size;

	size = ft_list_size(*begin_list);
	if (size <= 2)
		return ;
	t_list *next;
	t_list *swap;
	t_list *curr;
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

/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
int	main(int ac, char **av)
{
	t_list *mylist;
	t_list *mylist2;
	int (*ptr)(char *, char *);

	ptr = &ft_strcmp;

	mylist = ft_create_elem("mdr");
	mylist2 = ft_create_elem("SALUT");
	if (!mylist)
		printf("La liste est vide frere.\n");
	else
		printf("La liste a des elements mon reuf.\n");
	ft_list_push_front(&mylist, "FRONT");
	ft_list_push_front(&mylist2, "JE SUIS LA DEUXIEME LISTE");
	ft_list_push_front(&mylist, "2");
	ft_list_push_front(&mylist, "3");
	ft_list_push_front(&mylist, "4");
	ft_list_push_front(&mylist, "5");
	ft_list_push_front(&mylist, "6");
	ft_list_push_front(&mylist, "7");
	ft_list_push_front(&mylist, "8");
	ft_list_push_back(&mylist, "BACK");
	ft_print_list(mylist);
	printf("SIZE : %d\n", ft_list_size(mylist));
	printf("LAST : %s\n", ft_list_last(mylist)->data);
	printf("\n\n\nTEST PUSH STRS.\n");
	ft_print_list(ft_list_push_strs(ac, av));
	printf("\n\n\n5eme element (lol) : %s\n", ft_list_at(mylist, 5)->data);
	printf("\n\n\nREVERSE.\n");
	ft_list_reverse(&mylist);
	ft_print_list(mylist);
	printf("\n\n\nTEST MERGE \n");
	ft_list_merge(&mylist, mylist2);
	ft_print_list(mylist);
	printf("\n\n\nSORT LIST : \n");
	ft_list_sort(&mylist, (ptr));

	return (0);
}
