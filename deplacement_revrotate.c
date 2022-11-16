/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement_revrotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:20:54 by tas               #+#    #+#             */
/*   Updated: 2022/11/15 16:12:15 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* décale de 1 toute la stack a
le dernier elt devient le premier */
void	rra(t_list **list_stack_a)
{
	t_list	*front;
	t_list	*last;

	if ((*list_stack_a)->next != NULL)
	{
		front = NULL;
		last = (*list_stack_a);
		while (last->next != NULL)
		{
			front = last;
			last = last->next;
		}
		front->next = NULL;
		last->next = (*list_stack_a);
		(*list_stack_a) = last;
	}
	write(1, "rra\n", 4);
}

/* décale de 1 toute la stack b
le dernier elt devient le premier */
void	rrb(t_list **list_stack_b)
{
	t_list	*front;
	t_list	*last;

	if ((*list_stack_b)->next != NULL)
	{
		front = NULL;
		last = (*list_stack_b);
		while (last->next != NULL)
		{
			front = last;
			last = last->next;
		}
		front->next = NULL;
		last->next = (*list_stack_b);
		(*list_stack_b) = last;
	}
	write(1, "rrb\n", 4);
}

/* décale de 1 les stack a & b
les derniers elts deviennent les premiers */
void	rrr(t_list **list_stack_a, t_list **list_stack_b)
{
	rra(list_stack_a);
	rrb(list_stack_b);
	write(1, "rrr\n", 4);
}
