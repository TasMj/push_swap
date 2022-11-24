/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:34:16 by tmejri            #+#    #+#             */
/*   Updated: 2022/11/25 00:29:01 by tas              ###   ########.fr       */
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
	t_list *midd;
	t_list *tmp;

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

	print_list(list_a, list_b);
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
	order(list_a);
}