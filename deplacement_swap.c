/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:49:44 by tas               #+#    #+#             */
/*   Updated: 2022/08/06 19:31:03 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(t_list *first, t_list *second)
{
	t_list  *tmp;
	
	tmp = malloc(sizeof(t_list));

	tmp->content = first->content;
	first->content = second->content;
	second->content = tmp->content;
}

// swap les 2 premiers elts du haut de la stack A
void    *sa(t_list **list_stack_a)
{
	t_list	*tmp;

	if (!list_stack_a)
		return (NULL);
	if ((*list_stack_a)->next == NULL)
		return (NULL);
	tmp = malloc(sizeof(t_list));
	tmp = (*list_stack_a)->next;
	ft_swap((*list_stack_a), tmp);
	return (list_stack_a);
}

// swap les 2 premiers elts du haut de la stack B
void    *sb(t_list **list_stack_b)
{
	t_list	*tmp;

	if (!list_stack_b)
		return (NULL);
	if ((*list_stack_b)->next == NULL)
		return (NULL);
	tmp = malloc(sizeof(t_list));
	tmp = (*list_stack_b)->next;
	ft_swap((*list_stack_b), tmp);
	return (list_stack_b);
}

// swap les 2 premiers elts du haut des stacks A et B
void    ss(t_list **list_stack_a, t_list **list_stack_b)
{
	sa(list_stack_a);
	sb(list_stack_b);
}

