/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:52:05 by tas               #+#    #+#             */
/*   Updated: 2022/11/26 15:08:26 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	middle_size(t_list **list_a)
{
	int	size_a;
	int	middle;

	size_a = ft_lstsize(*list_a);
	if (size_a % 2 == 0)
		middle = (size_a / 2);
	else
		middle = (size_a / 2) + 1;
	return (middle);
}

/* return l'indice de l'elm a l'indice position */
t_list	*last_elt(t_list **list, int size_list)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *list;
	last = *list;
	while (size_list > 1)
	{
		(*list) = (*list)->next;
		size_list--;
	}
	last = (*list);
	*list = tmp;
	return (last);
}

t_list	*index_middle(t_list **list_a, int middle)
{
	t_list	*midd;
	t_list	*tmp;

	tmp = *list_a;
	midd = *list_a;
	while (middle > 1)
	{
		(*list_a) = (*list_a)->next;
		middle--;
	}
	midd = *list_a;
	*list_a = tmp;
	return (midd);
}

int	biggest(t_list	**list_a)
{
	int		max;
	t_list	*tmp;

	tmp = *list_a;
	max = (*list_a)->index;
	(*list_a) = (*list_a)->next;
	while ((*list_a))
	{
		if ((*list_a)->index > max)
			max = (*list_a)->index;
		(*list_a) = (*list_a)->next;
	}
	*list_a = tmp;
	return (max);
}

int	smallest(t_list	**list_a)
{
	int		min;
	t_list	*tmp;

	tmp = *list_a;
	min = (*list_a)->index;
	(*list_a) = (*list_a)->next;
	while ((*list_a))
	{
		if ((*list_a)->index < min)
			min = (*list_a)->index;
		(*list_a) = (*list_a)->next;
	}
	*list_a = tmp;
	return (min);
}
