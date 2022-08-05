/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:49:44 by tas               #+#    #+#             */
/*   Updated: 2022/08/05 16:12:25 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_list **list)
{
	t_list  *tmp;
	t_list  *tmp2;

	tmp = ft_lstnew((*list)->content);
	(*list) = (*list)->next;
	tmp2 = ft_lstnew((*list)->content);
	(*list)->content = tmp->content;
	(*list) = (*list)->premier;
	(*list)->content = tmp2->content;
}

// swap les 2 premiers elts du haut de la stack A
void    *sa(t_list **list_stack_a)
{
	if (!list_stack_a)
		return (NULL);
	if ((*list_stack_a)->next == NULL)
		return (NULL);
	swap(list_stack_a);
	return (list_stack_a);
}

// swap les 2 premiers elts du haut de la stack B
void    *sb(t_list **list_stack_b)
{
	if (!list_stack_b)
		return (NULL);
	if ((*list_stack_b)->next == NULL)
		return (NULL);
	swap(list_stack_b);
	return (list_stack_b);
}

// // swap les 2 premiers elts du haut des stacks A et B
void    ss(t_list **list_stack_a, t_list **list_stack_b)
{
	// if (!list_stack_a || !list_stack_b)
	    // return (NULL);
	// if ((*list_stack_a)->next == NULL || (*list_stack_b)->next == NULL)
	    // return (NULL);
	sa(list_stack_a);
	sb(list_stack_b);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	t_list  **ma_list;

	ma_list = attribution_arg(argc, argv);
	printf("\n***********main**************\n");

	sa(ma_list);
	for (int i = 0; i < 3; i++)
	{
		printf("content: %d\n", (*ma_list)->content);
		// printf("ADD: %p\n",(*ma_list));
		// printf("addr_prem: %p\n",(*ma_list)->premier);
		// printf("addr_next: %p\n\n", (*ma_list)->next);
		(*ma_list) = (*ma_list)->next;
	}
	return (0);
}
