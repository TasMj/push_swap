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
	// else if (c == 1)
	// {
	// 	rra(list_a);
	// 	pa(list_a, list_b);
	// 	ra(list_a);
	// 	ra(list_a);
	// }
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

int	size_list(t_list **list_a)
{
	int size_a;
	int middle;
	
	size_a = ft_lstsize(*list_a);
	if (size_a % 2 == 0)
		middle = (size_a / 2);
	else
		middle = (size_a / 2) + 1;
	return (middle);
}


int	from_top(t_list **list_a, t_list **list_b)
{
	int		middle;
	int		keep_middle;
	int		c;
	t_list	*tmp;
	int		r;

	c = 0;
	r = 0;
	tmp = *list_a;
	middle = size_list(list_a);
	keep_middle = middle;
	while (middle > 0)
	{
		if ((*list_b)->index > (*list_a)->index)
		{
			(*list_a) = (*list_a)->next;
			c++;
		}
		middle--;
	}
	if (c == keep_middle && ((*list_b)->index > (*list_a)->index))
		r = -1;
	else
		r = c;
	*list_a = tmp;
	return (r);
}

int	down_even(t_list **list_a, t_list **list_b, int middle) //paire
{
	int	res;
	int keep_middle;
	t_list	*tmp;

	res = 0;
	keep_middle = middle;
	tmp = *list_a;
	while (middle > 0)
	{
		if ((*list_a)->next)
			(*list_a) = (*list_a)->next;
		middle--;
	}
	middle = keep_middle;
	while ((*list_a) && middle > 0)
	{
		if ((*list_b)->index > (*list_a)->index)
		{
			if ((*list_a)->next)
			{
				(*list_a) = (*list_a)->next;
				c++;
			}
		}
		middle--;
	}
	*list_a = tmp;
	return (res);


}


// int	down_odd() // impaire
// {
	
// }




int	from_down(t_list **list_a, t_list **list_b)
{
	int		middle;
	int		keep_middle;
	int		c;
	t_list	*tmp;
	int		r;

	c = 0;
	r = 0;
	tmp = *list_a;
	middle = size_list(list_a);
	keep_middle = middle;
	while (middle > 0)
	{
		if ((*list_a)->next)
			(*list_a) = (*list_a)->next;
		middle--;
	}
	if (keep_middle % 2 == 0)
		middle = keep_middle;
	else
		middle = keep_middle - 1;
	while ((*list_a) && middle > 0)
	{
		if ((*list_b)->index > (*list_a)->index)
		{
			if ((*list_a)->next)
			{
				(*list_a) = (*list_a)->next;
				c++;
			}
		}
		middle--;
	}
	if (c == (keep_middle - 1) && ((*list_b)->index > (*list_a)->index))
		r = 0;
	// else if (keep_middle % 2 == 0)
		// r = (keep_middle - 1) - c;
	else
		r = keep_middle - c;
	*list_a = tmp;
	return (r);
}

void	sort_in_stack_a(t_list **list_a, t_list **list_b)
{
	int	final_size;
	int	top;
	int	down;

	final_size = ft_lstsize(*list_a) + ft_lstsize(*list_b);
	while (ft_lstsize(*list_a) != final_size)
	{
		top = from_top(list_a, list_b);
		down = from_down(list_a, list_b);
		printf("top == %i\n", top);
		printf("down == %i\n", down);
		print_list(list_a, list_b);
		if (down == 0 || (down < top && down != -1) || top == -1)
			move_from_down(list_a, list_b, down);
		else
			move_from_top(list_a, list_b, top);
		print_list(list_a, list_b);
	}
}
