/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:49:44 by tas               #+#    #+#             */
/*   Updated: 2022/11/17 15:27:06 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* swap 2 elts d'une liste */
void	ft_swap(t_list *first, t_list *second)
{
	t_list	*tmp;

	tmp = first;
	first->content = second->content;
	first->index = second->index;
	second->content = tmp->content;
	second->index = tmp->index;
}

/* swap les 2 premiers elts du haut de la stack A */
void	*sa(t_list **list_stack_a)
{
	t_list	*tmp;

	if (!list_stack_a)
		return (NULL);
	if ((*list_stack_a)->next == NULL)
		return (NULL);
	tmp = (*list_stack_a)->next;
	ft_swap((*list_stack_a), tmp);
	write(1, "sa\n", 3);
	return (list_stack_a);
}

/* swap les 2 premiers elts du haut de la stack B */
void	*sb(t_list **list_stack_b)
{
	t_list	*tmp;

	if (!list_stack_b)
		return (NULL);
	if ((*list_stack_b)->next == NULL)
		return (NULL);
	tmp = (*list_stack_b)->next;
	ft_swap((*list_stack_b), tmp);
	write(1, "sb\n", 3);
	return (list_stack_b);
}

/* swap les 2 premiers elts de la stack A et ceux de la stack B */
void	ss(t_list **list_stack_a, t_list **list_stack_b)
{
	sa(list_stack_a);
	sb(list_stack_b);
	write(1, "ss\n", 3);
}
