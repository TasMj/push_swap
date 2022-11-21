/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:34:16 by tmejri            #+#    #+#             */
/*   Updated: 2022/11/19 13:03:24 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_from_top(t_list **list_a, t_list **list_b, int c)
{
	int	keep_c;

	keep_c = c;
	while (c > 0)
	{
		ra(list_a);
		c--;
	}
	pa(list_a, list_b);
	while (keep_c > 0)
	{
		rra(list_a);
		keep_c--;
	}
}

void	move_from_down(t_list **list_a, t_list **list_b, int c)
{
	int	keep_c;

	keep_c = c;
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
		while (keep_c > 0)
		{
			ra(list_a);
			keep_c--;
		}
	}
}

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

int find_rank(t_list **list_a, t_list **list_b, int middle)
{
	int	c;

	c = 0;
	while (middle > 0)
	{
		if ((*list_b)->index > (*list_a)->index)
		{
			(*list_a) = (*list_a)->next;
			c++;
		}
		middle--;
	}
	return (c);
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
	c = find_rank(list_a, list_b, middle);
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
		if (c == keep_middle)
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
	t_list	*tmp;

	tmp = *list_a;
	size_a = ft_lstsize(*list_a);
	middle = middle_size(list_a);
	keep_middle = middle;
	while (middle > 0)
	{
		(*list_a) = (*list_a)->next;
		middle--;
	}
	if (size_a % 2 == 0)
		middle = keep_middle;
	else
		middle = keep_middle - 1;
	c = find_rank(list_a, list_b, middle);
	c = down_even_odd(keep_middle, size_a, c);
	*list_a = tmp;
	return (c);
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
}
