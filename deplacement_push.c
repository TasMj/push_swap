/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:44:40 by tas               #+#    #+#             */
/*   Updated: 2022/11/15 18:52:26 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push le first elt de b dans la stack A
B ---> A */
void	pa(t_list **list_stack_a, t_list **list_stack_b)
{
	t_list	*tmp;

	if (*list_stack_b == NULL)
		return ;
	tmp = *list_stack_b;
	*list_stack_b = (*list_stack_b)->next;
	tmp->next = *list_stack_a;
	*list_stack_a = tmp;
	(write(1, "pa\n", 3));
}

/* push le first elt de a dans la stack B
A ---> B */
void	pb(t_list **list_stack_b, t_list **list_stack_a)
{
	t_list	*tmp;

	if (*list_stack_a == NULL)
		return ;
	tmp = *list_stack_a;
	*list_stack_a = (*list_stack_a)->next;
	tmp->next = *list_stack_b;
	*list_stack_b = tmp;
	(write(1, "pb\n", 3));
}
