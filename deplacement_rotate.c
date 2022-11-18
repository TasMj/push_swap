/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:16:22 by tas               #+#    #+#             */
/*   Updated: 2022/11/18 19:33:21 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* décale de 1 toute la stack a
le premier elt devient le dernier */
void	ra(t_list **list_stack_a)
{
	t_list	*front;
	t_list	*last;

	if ((*list_stack_a)->next != NULL)
	{
		front = *list_stack_a;
		last = *list_stack_a;
		while (last->next != NULL)
			last = last->next;
		*list_stack_a = front->next;
		last->next = front;
		front->next = NULL;
	}	
	// write(1, "ra\n", 3);
}

/* décale de 1 toute la stack b
le premier elt devient le dernier */
void	rb(t_list **list_stack_b)
{
	t_list	*front;
	t_list	*last;

	if ((*list_stack_b)->next != NULL)
	{
		front = *list_stack_b;
		last = *list_stack_b;
		while (last->next != NULL)
			last = last->next;
		*list_stack_b = front->next;
		last->next = front;
		front->next = NULL;
	}	
	// write(1, "rb\n", 3);
}

/* décale de 1 les elts des stacks a et stack b 
les premiers deviennent les derniers */
void	rr(t_list **list_stack_a, t_list **list_stack_b)
{
	ra(list_stack_a);
	rb(list_stack_b);
	// write(1, "rr\n", 3);
}
