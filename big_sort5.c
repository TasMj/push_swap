/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:34:16 by tmejri            #+#    #+#             */
/*   Updated: 2022/11/25 14:54:11 by tas              ###   ########.fr       */
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

int down_even_odd(int keep_middle, int size_a, int c)
{
	int r;

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
	int		size_a;
	int		middle;
	int		keep_middle;
	int		c;
	int		r;
	int		max;
	t_list	*tmp;
	t_list	*last_top;

	r = 0;
	tmp = *list_a;
	last_top = *list_a;
	size_a = ft_lstsize(*list_a);
	middle = middle_size(list_a);
	max = biggest(list_a);
	keep_middle = middle;
	while (middle > 1)
	{
		(*list_a) = (*list_a)->next;
		last_top = (*list_a);
		middle--;
	}
	(*list_a) = (*list_a)->next;
	if (size_a % 2 == 0)
		middle = keep_middle;
	else
		middle = keep_middle - 1;
	c = find_rank_down(list_a, list_b, middle, last_top, tmp, max);
	if (c == -1)
		r = -1;
	else
		r = down_even_odd(keep_middle, size_a, c);
	*list_a = tmp;
	return (r);
}

void	sort_in_stack_a(t_list **list_a, t_list **list_b)
{
	int	top;
	int	down;
	int	final_size;

	final_size = ft_lstsize(*list_a) + ft_lstsize(*list_b);
	while (ft_lstsize(*list_a) != final_size)
	{
		top = from_top(list_a, list_b);
		down = from_down(list_a, list_b);
		if (down == 0 || (down < top && down != -1) || top == -1)
			move_from_down(list_a, list_b, down);
		else
			move_from_top(list_a, list_b, top);
	}
	if ((*list_a)->index != 0)
		order(list_a);
}