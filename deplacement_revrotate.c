/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement_revrotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:20:54 by tas               #+#    #+#             */
/*   Updated: 2022/10/11 19:08:03 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* décale de 1 toute la stack a
le dernier elt devient le premier */
t_list	**rra(t_list **list_stack_a)
{
	t_list	*last;
	t_list	*first;
	t_list	*tmp;

	(*list_stack_a) = (*list_stack_a)->premier;
	first = malloc(sizeof(t_list));
	first = (*list_stack_a);
	last = malloc(sizeof(t_list));
	last = ft_lstlast(*list_stack_a);
	tmp = last;
	last->premier = tmp;
	first->premier = tmp;
	last->next = first;
	while ((*list_stack_a)->next != last)
	{
		(*list_stack_a)->premier = tmp;
		(*list_stack_a) = (*list_stack_a)->next;
	}
	(*list_stack_a)->next = NULL;
	(*list_stack_a) = last;
	write(1, "rra\n", 4);
	return (list_stack_a);
}

/* décale de 1 toute la stack b
le dernier elt devient le premier */
t_list	**rrb(t_list **list_stack_b)
{
	t_list	*last;
	t_list	*first;
	t_list	*tmp;

	(*list_stack_b) = (*list_stack_b)->premier;
	first = malloc(sizeof(t_list));
	first = (*list_stack_b);
	last = malloc(sizeof(t_list));
	last = ft_lstlast(*list_stack_b);
	tmp = last;
	last->premier = tmp;
	first->premier = tmp;
	last->next = first;
	while ((*list_stack_b)->next != last)
	{
		(*list_stack_b)->premier = tmp;
		(*list_stack_b) = (*list_stack_b)->next;
	}
	(*list_stack_b)->next = NULL;
	(*list_stack_b) = last;
	write(1, "rrb\n", 4);
	return (list_stack_b);
}

/*décale de 1 les stack a & b
les derniers elts deviennent les premiers */
void	rrr(t_list **list_stack_a, t_list **list_stack_b)
{
	rra(list_stack_a);
	rrb(list_stack_b);
	write(1, "rrr\n", 4);
}
