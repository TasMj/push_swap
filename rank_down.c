/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:04:40 by tas               #+#    #+#             */
/*   Updated: 2022/11/26 19:35:12 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first(t_list **list_a, t_list **list_b, t_full_list full_list, t_info info)
{
	if (((*list_b)->index > full_list.last_top->index))
		return (0);
	if ((*list_a)->index == info.min_a
		&& full_list.last_top->index == full_list.max_full_list)
		return (0);
	if (((*list_b)->index > full_list.last_elt->index)
		&& ((*list_a)->index < info.max_a))
		return (-1);
	if (((*list_b)->index > full_list.last_elt->index)
		&& ((*list_b)->index > full_list.tmp->index))
		return (-1);
	return (-3);
}

int	b_big(t_list **list_a, t_list **list_b, t_full_list full_list, t_info info)
{
	int	c;

	c = 0;
	if ((*list_a)->index == info.min_a
		&& (*list_b)->index > full_list.max_full_list)
		return (0);
	if ((full_list.middle > 0) && (*list_a))
	{
		while (((*list_b)->index > (*list_a)->index)
			&& ((*list_a)->index < info.max_a))
			go(list_a, &full_list.middle, &c);
		if ((full_list.middle == 1) && ((*list_b)->index > (*list_a)->index))
			return (-1);
		if ((((*list_a)->index == info.max_a)
				&& (*list_b)->index > (*list_a)->index)
			|| ((*list_a)->index == info.max_a
				&& (*list_b)->index > (*list_a)->index))
			return (c + 1);
		return (c);
	}
	return (c);
}

int	b_smal(t_list **list_a, t_list **list_b, t_full_list full_list, t_info info)
{
	int	c;

	c = 0;
	if ((full_list.middle > 1) && (*list_a)->index == info.max_a
		&& (*list_b)->index > (*list_a)->next->index)
		go(list_a, &full_list.middle, &c);
	if (first(list_a, list_b, full_list, info) != -3)
		return (first(list_a, list_b, full_list, info));
	if ((full_list.middle > 0) && (*list_a))
	{
		while (((*list_b)->index < (*list_a)->index)
			&& ((*list_a)->index < info.max_a))
			go(list_a, &full_list.middle, &c);
		if ((full_list.middle == 1) && ((*list_b)->index < (*list_a)->index))
			return (-1);
		go(list_a, &full_list.middle, &c);
		while ((*list_b)->index > (*list_a)->index)
			go(list_a, &full_list.middle, &c);
		if ((full_list.middle == 0) && ((*list_b)->index < (*list_a)->index))
			return (-1);
	}
	return (c);
}

int	find_rank_down(t_list **list_a, t_list **list_b, t_full_list full_list)
{
	t_info	info;

	info.max_a = biggest(list_a);
	info.min_a = smallest(list_a);
	info.size_a = ft_lstsize(*list_a);
	if (((*list_b)->index > full_list.max_full_list)
		&& (full_list.last_elt->index == full_list.max_full_list))
		return (-1);
	if ((*list_b)->index < (*list_a)->index)
		return (b_smal(list_a, list_b, full_list, info));
	if ((*list_b)->index > (*list_a)->index)
		return (b_big(list_a, list_b, full_list, info));
	return (0);
}
