/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:34:16 by tmejri            #+#    #+#             */
/*   Updated: 2022/11/22 20:23:54 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_from_top(t_list **list_a, t_list **list_b, int c)
{
	// int	keep_c;

	// keep_c = c;
	while (c > 0)
	{
		ra(list_a);
		c--;
	}
	pa(list_a, list_b);
	// while (keep_c > 0)
	// {
		// rra(list_a);
		// keep_c--;
	// }
}

void	move_from_down(t_list **list_a, t_list **list_b, int c)
{
	// int	keep_c;

	// keep_c = c;
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
		// while (keep_c > 0)
		// {
			// ra(list_a);
			// keep_c--;
		// }
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

int find_rank_top(t_list **list_a, t_list **list_b, int middle)
{
	int	c;
	int	size_a;
	int max_a;
	t_list	*last;
	t_list	*midd;

	c = 0;
	max_a = biggest(list_a);
	size_a = ft_lstsize(*list_a);
	last = last_elt(list_a, size_a);
	midd = last_elt(list_a, middle);
	printf("middle: %d\n", middle);
	printf("B: %d\n", (*list_b)->index);
	printf("last index: %d\n", last->index);
	printf("A: %d\n", (*list_a)->index);
	printf("MAX: %d\n", max_a);
	printf("*******************************\n");
	if ((((*list_b)->index < (*list_a)->index) && ((*list_b)->index > last->index)) && (((*list_b)->index < (*list_a)->index) && ((*list_a)->index < max_a)))
	{
		printf("4444444444444444444\n");
		return (0);
	}
	else if (((*list_b)->index < (*list_a)->index) && ((*list_b)->index > midd->index))
	{
		printf("555555555555555555555\n");
		
		while ((*list_a) && middle > 0)
		{
			while ((*list_b)->index < (*list_a)->index)
			{
				(*list_a) = (*list_a)->next;
				c++;
				middle--;
			}
			while ((*list_b)->index > (*list_a)->index)
			{
				(*list_a) = (*list_a)->next;
				c++;
				middle--;
			}
			return (c);
		}
		return (c);
	}
	else if ((*list_b)->index > (*list_a)->index)
	{
		printf("66666666666666666666\n");
		while ((middle > 0) && (*list_a))
		{
			if (((*list_b)->index > (*list_a)->index))
			{
				(*list_a) = (*list_a)->next;
				c++;
			}
			middle--;
		}
		if (middle == 0)
			return (-1);
		return (c);
	}
	
	return (-1);
}




int find_rank_down(t_list **list_a, t_list **list_b, int middle, t_list	*last_top, t_list *tmp)
{
	int		c;
	int		max_a;
	int		size_a;
	t_list	*last;

	c = 0;
	size_a = ft_lstsize(*list_a);
	last = last_elt(list_a, size_a);
	max_a = biggest(list_a);
	printf("middle: %d\n", middle);
	printf("first index: %d\n", tmp->index);
	printf("B: %d\n", (*list_b)->index);
	printf("last index: %d\n", last->index);
	printf("A: %d\n", (*list_a)->index);
	printf("MAX: %d\n", max_a);
	if (((*list_b)->index > last->index))
	{
		printf("11111111111111111111\n");
		return (middle);
	}
	else if (((*list_b)->index < (*list_a)->index) && ((*list_b)->index > last_top->index))
	{
		printf("22222222222222222222\n");	
		return (0);
	}
	else if (((*list_b)->index < (*list_a)->index) ) // et inf au + grand
	{                                                // && (*list_b)->index < (*list_a)->index && (*list_a)->index < max
		
	printf("MAX: %d\n", max_a);
		while ((middle > 0) && (*list_a))
		{
			while (((*list_b)->index < (*list_a)->index) && ((*list_a)->index < max_a))
			{
		printf("333333333333333333\n");
				printf("index: %d\n", (*list_a)->index);
				(*list_a) = (*list_a)->next;
				c++;
				middle--;
			}
			if ((*list_a)->index == max_a)
				return (c + 1);
			while ((*list_b)->index > (*list_a)->index)
			{
				(*list_a) = (*list_a)->next;
				c++;
				middle--;
			}
			if (middle == 0)
				return (-1);
			return (c);
		}
		return (c);
	}
	else if ((*list_b)->index > (*list_a)->index)
	{
		while ((middle > 0) && (*list_a))
		{
		printf("4444444444444444444444\n");
			if (((*list_b)->index > (*list_a)->index))
			{
				(*list_a) = (*list_a)->next;
				c++;
			}
			middle--;
		}
		printf("MIDDLE: %d\n", middle);
		if (middle == 0)
			return (-1);
// 
		// if ((*list_b)->index > (*list_a)->index)
			// return (-1);
		return (c);
	}
	return (-1);
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
	printf("c: %d\n", c);
	if (c == keep_middle)
		r = -1;
	else
		r = c;
	printf("r: %d\n", r);
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
	t_list	*tmp;
	t_list	*last_top;

	r = 0;
	tmp = *list_a;
	last_top = *list_a;
	size_a = ft_lstsize(*list_a);
	middle = middle_size(list_a);
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
	c = find_rank_down(list_a, list_b, middle, last_top, tmp);
	printf("c: %d\n", c);
	if (c == -1)
		r = -1;
	else
		r = down_even_odd(keep_middle, size_a, c);
	printf("r: %d\n", r);
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
		// print_list(list_a, list_b);
		top = from_top(list_a, list_b);
		down = from_down(list_a, list_b);
		printf("TOP: %d   DOWN: %d\n", top, down);
		if (down == 0 || (down < top && down != -1) || top == -1)
			move_from_down(list_a, list_b, down);
		else
			move_from_top(list_a, list_b, top);
		print_list(list_a, list_b);
	}
}
