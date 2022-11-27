/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_from_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:25:13 by tas               #+#    #+#             */
/*   Updated: 2022/11/27 02:54:02 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_start_top(t_list **list)
{
	int		c;
	int		size;
	t_list	*tmp;

	c = 0;
	tmp = *list;
	size = ft_lstsize(*list) / 2;
	while (size)
	{
		if ((*list)->index == 0)
		{
			*list = tmp;
			return (c);
		}
		else
		{
			(*list) = (*list)->next;
			c++;
			size--;
		}
	}
	*list = tmp;
	return (-1);
}

int	find_start_down(t_list **list)
{
	int			c;
	t_info		info;
	t_full_list	full_list;

	c = 0;
	full_list.tmp = *list;
	info.size_a = ft_lstsize(*list) / 2;
	full_list.middle = middle_size(list);
	full_list.max_full_list = middle_size(list);
	while (info.size_a)
	{
		(*list) = (*list)->next;
		info.size_a--;
	}
	while (full_list.middle)
	{
		if ((*list)->index == 0)
		{
			*list = full_list.tmp;
			return (full_list.max_full_list - c);
		}
		go(list, &full_list.middle, &c);
	}
	return (-1);
}

void	order(t_list **list)
{
	int	top;
	int	down;

	top = find_start_top(list);
	down = find_start_down(list);
	if ((top < down && top != -1) || down == -1)
	{
		while (top > 0)
		{
			ra(list);
			top--;
		}
	}
	else
	{
		while (down > 0)
		{
			rra(list);
			down--;
		}
	}
}
