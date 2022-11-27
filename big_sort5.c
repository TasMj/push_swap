/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:34:16 by tmejri            #+#    #+#             */
/*   Updated: 2022/11/27 14:28:05 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_from_top(t_list **list_a, t_list **list_b, int c)
{
	while (c > 0)
	{
		ra(list_a);
		c--;
	}
	pa(list_a, list_b);
}

void	move_from_down(t_list **list_a, t_list **list_b, int c)
{
	if (c == 0)
	{
		pa(list_a, list_b);
		ra(list_a);
	}
	else
	{
		while (c > 1)
		{
			rra(list_a);
			c--;
		}
		pa(list_a, list_b);
	}
}

int	from_top(t_list **list_a, t_list **list_b)
{
	int		middle;
	int		keep_middle;
	int		c;
	t_list	*tmp;
	int		r;

	r = 0;
	tmp = *list_a;
	middle = middle_size(list_a);
	keep_middle = middle;
	c = find_rank_top(list_a, list_b, middle);
	if (c == keep_middle)
		r = -1;
	else
		r = c;
	*list_a = tmp;
	return (r);
}

int	down_even_odd(int keep_middle, int size_a, int c)
{
	int	r;

	r = 0;
	if (size_a % 2 == 0)
	{
		if (c == keep_middle)
			r = 0;
		else
			r = ((keep_middle + 1) - c);
	}
	else
	{
		if (c == (keep_middle - 1))
			r = 0;
		else
			r = (keep_middle - c);
	}
	return (r);
}

int	from_down(t_list **list_a, t_list **list_b)
{
	int			c;
	int			r;
	int			size_a;
	int			keep_middle;
	t_full_list	full_list;

	r = 0;
	full_list.tmp = *list_a;
	size_a = ft_lstsize(*list_a);
	full_list.middle = middle_size(list_a);
	full_list.last_top = *list_a;
	full_list.max_full_list = biggest(list_a);
	full_list.last_elt = last_elt(list_a, size_a);
	keep_middle = full_list.middle;
	while (full_list.middle > 1)
	{
		(*list_a) = (*list_a)->next;
		full_list.last_top = (*list_a);
		full_list.middle--;
	}
	(*list_a) = (*list_a)->next;
	if (size_a % 2 == 0)
		full_list.middle = keep_middle;
	else
		full_list.middle = keep_middle - 1;
	c = find_down(list_a, list_b, full_list);
	if (c == -1)
		r = -1;
	else
		r = down_even_odd(keep_middle, size_a, c);
	*list_a = full_list.tmp;
	return (r);
}
