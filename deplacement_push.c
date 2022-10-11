/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:44:40 by tas               #+#    #+#             */
/*   Updated: 2022/10/11 19:01:09 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push le first elt de b dans la stack A
B ---> A*/
void	pa(t_list **list_stack_a, t_list **list_stack_b)
{
	(*list_stack_a) = (*list_stack_a)->premier;
	if (list_stack_b)
	{
		ft_lstadd_front(list_stack_a, ft_lstnew((*list_stack_b)->content));
		(*list_stack_a)->premier = (*list_stack_a);
		(*list_stack_a)->index = (*list_stack_b)->index;
		if ((*list_stack_b)->next != NULL)
		{
			(*list_stack_b) = (*list_stack_b)->next;
			(*list_stack_b)->premier = (*list_stack_b);
		}
		else
			(*list_stack_b) = NULL;
	}
	write(1, "pa\n", 3);
}

/* push le first elt de a dans la stack B
A ---> B */
void	pb(t_list **list_stack_b, t_list **list_stack_a)
{
	if (list_stack_a)
	{
		ft_lstadd_front(list_stack_b, ft_lstnew((*list_stack_a)->content));
		(*list_stack_b)->premier = (*list_stack_b);
		(*list_stack_b)->index = (*list_stack_a)->index;
		if ((*list_stack_a)->next != NULL)
		{
			(*list_stack_a) = (*list_stack_a)->next;
			(*list_stack_a)->premier = (*list_stack_a);
		}
		else
			(*list_stack_b) = NULL;
	}
	write(1, "pb\n", 3);
}
