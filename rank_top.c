/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:18:26 by tas               #+#    #+#             */
/*   Updated: 2022/11/26 17:20:46 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go(t_list **list_a, int *middle, int *c)
{
	(*list_a) = (*list_a)->next;
	(*middle)--;
	(*c)++;
}

int	first_position(t_list **list_a, t_list **list_b, int middle, t_info info)
{
	int		c;
	t_list	*last;
	t_list	*midd;

	c = 0;
	last = last_elt(list_a, info.size_a);
	midd = last_elt(list_a, middle);
	if ((last->index == info.max_a) || (((*list_b)->index > last->index)
			&& ((*list_a)->index == info.max_a))
		|| (((*list_b)->index > last->index)
			&& ((*list_a)->index < info.max_a)))
		return (0);
	if (((*list_b)->index > midd->index))
	{
		while (((*list_b)->index < (*list_a)->index)
			&& (*list_a)->index > info.min_a)
			go(list_a, &middle, &c);
		if ((middle > 1) && ((*list_a)->index == info.max_a)
			&& ((*list_a)->next->index == info.min_a))
			return (c);
		while ((*list_b)->index > (*list_a)->index)
			go(list_a, &middle, &c);
		return (c);
	}
	return (-3);
}

int	middle_position(t_list **list_a, t_list **list_b, int middle, t_info info)
{
	int	c;

	c = 0;
	while ((*list_a)->index != info.max_a && middle > 0)
		go(list_a, &middle, &c);
	if ((middle == 0) && ((*list_b)->index > (*list_a)->index))
		return (-1);
	if ((*list_a)->index == info.max_a)
		go(list_a, &middle, &c);
	while ((*list_b)->index > (*list_a)->index)
		go(list_a, &middle, &c);
	if ((middle == 0) && ((*list_b)->index > (*list_a)->index))
		return (-1);
	return (c);
}

int	other_position(t_list **list_a, t_list **list_b, int middle, t_info info)
{
	int	c;

	c = 0;
	if ((*list_a)->index == info.max_a)
		return (1);
	while ((middle > 0) && (*list_a))
	{
		while (((*list_b)->index > (*list_a)->index) && ((middle > 0)))
		{
			if ((*list_a)->index == info.max_a)
				return (c + 1);
			(*list_a) = (*list_a)->next;
			c++;
			middle--;
		}
		if (middle == 0 && (*list_a)->index < info.min_a)
			return (-1);
		return (c);
	}
	return (-1);
}

int	find_rank_top(t_list **list_a, t_list **list_b, int middle)
{
	int		c;
	t_info	info;
	t_list	*last;

	c = 0;
	info.max_a = biggest(list_a);
	info.min_a = smallest(list_a);
	info.size_a = ft_lstsize(*list_a);
	last = last_elt(list_a, info.size_a);
	if (((*list_b)->index > info.max_a) && (last->index == info.max_a))
		return (0);
	if ((*list_b)->index < (*list_a)->index)
	{
		c = first_position(list_a, list_b, middle, info);
		if (c != -3)
			return (c);
		c = 0;
		if (((*list_b)->index < last->index))
			c = middle_position(list_a, list_b, middle, info);
		return (c);
	}
	if ((*list_b)->index > (*list_a)->index)
		c = other_position(list_a, list_b, middle, info);
	return (c);
}
