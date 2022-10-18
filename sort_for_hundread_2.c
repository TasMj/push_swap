/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_hundread_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:41:27 by tmejri            #+#    #+#             */
/*   Updated: 2022/10/18 15:44:02 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* trouve la mediane dans la stack actuelle et return l'index de la mediane */
int	find_mediane_index(t_list **list)
{
	int		size;
	int		pos_mediane;
	int		stock_index;
	t_list	*tmp;

	stock_index = 0;
	tmp = *(list);
	size = ft_lstsize(*list);
	pos_mediane = size / 2;
	(*list) = (*list)->premier;
	while (pos_mediane)
	{
		(*list) = (*list)->next;
		pos_mediane--;
	}
	stock_index = (*list)->index;
	(*list) = tmp;
	return (stock_index);
}

/* bool qui renvoie 1 si l'index de l'elt fait partie de la premiere 
partie de la stack A en fonction de la mediane, 2 sinon */
int	up_or_down(t_list **list_a, t_list **list_b)
{
	int	mediane;

	mediane = find_mediane_index(list_a);
	if ((*list_b)->index < mediane)
		return (1);
	else
		return (2);
}

/* trie dans le cas ou l'index de b est > l'index du premier elt de a */
void	from_top(t_list **list_a, t_list **list_b)
{
	int		t_index;
	int		stock_index;
	t_list	*tmp;

	tmp = *list_a;
	t_index = 0;
	stock_index = 0;
	while ((*list_b)->index > (*list_a)->index)
	{
		(*list_a) = (*list_a)->next;
		stock_index++;
	}
	*list_a = tmp;
	t_index = stock_index;
	while (stock_index > 0)
	{
		ra(list_a);
		stock_index--;
	}
	pa(list_a, list_b);
	while (t_index > 0)
	{
		rra(list_a);
		t_index--;
	}
}

/* trie dans le cas ou l'index de b est < l'index du dernier elt de a */
void	from_down(t_list **list_a, t_list **list_b)
{
	int		t_index;
	int		stock_index;
	t_list	*tmp;

	tmp = *list_a;
	t_index = 0;
	stock_index = 1;
	while ((*list_b)->index < (*list_a)->index)
	{
		rra(list_a);
		stock_index++;
	}
	ra(list_a);
	*list_a = tmp;
	t_index = stock_index;
	pa(list_a, list_b);
	while (t_index > 0)
	{
		ra(list_a);
		t_index--;
	}
}

/* verifie qu'une liste n'est pas vide */
int	empty_list(t_list **list)
{
	if ((*list) != NULL)
		return (1);
	else
		return (0);
}
