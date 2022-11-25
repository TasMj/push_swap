/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aaaaaa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:00:25 by tas               #+#    #+#             */
/*   Updated: 2022/11/25 14:00:27 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


int find_rank_top(t_list **list_a, t_list **list_b, int middle)
{
	int	c;
	int	size_a;
	int max_a;
	int min_a;
	t_list	*last;
	t_list	*midd;

	c = 0;
	max_a = biggest(list_a);
	min_a = smallest(list_a);
	size_a = ft_lstsize(*list_a);
	last = last_elt(list_a, size_a);
	midd = last_elt(list_a, middle);
	if (((*list_b)->index > max_a) && (last->index == max_a))
		return (0);
	else if ((*list_b)->index < (*list_a)->index)
	{
		if (last->index == max_a)
			return (0);
		else if (((*list_b)->index < (*list_a)->index) && ((*list_b)->index > last->index) && ((*list_a)->index == max_a))
			return (0);
		else if ((((*list_b)->index < (*list_a)->index) && ((*list_b)->index > last->index)) && ((*list_a)->index < max_a))
			return (0);
		else if (((*list_b)->index > midd->index))
		{
			while ((*list_a) && middle > 0)
			{
				while (((*list_b)->index < (*list_a)->index) && (*list_a)->index > min_a)
				{
					(*list_a) = (*list_a)->next;
					c++;
					middle--;
				}
				if ((middle > 1) && ((*list_a)->index == max_a) && ((*list_a)->next->index == min_a))
					return (c);
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
		else if (((*list_b)->index < last->index))
		{
			while ((*list_a) && middle > 0)
			{
				while ((*list_a)->index != max_a && middle > 0)
				{
					(*list_a) = (*list_a)->next;
					c++;
					middle--;
				}
				if ((middle == 0) && ((*list_b)->index > (*list_a)->index))
					return (-1);
				else
				{
					if ((*list_a)->index == max_a)
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
					if ((middle == 0) && ((*list_b)->index > (*list_a)->index))
						return (-1);
				}
				return (c);
			}
		}
		return (-1);
	}
	else if ((*list_b)->index > (*list_a)->index)
	{
		if ((*list_a)->index == max_a)
			return (1);
		else
		{
			while ((middle > 0) && (*list_a))
			{
				while (((*list_b)->index > (*list_a)->index) && ((middle > 0)))
				{
					if ((*list_a)->index == max_a)
						return (c + 1);
					(*list_a) = (*list_a)->next;
					c++;
					middle--;
				}
				if (middle == 0 && (*list_a)->index < min_a)
					return (-1);
				return (c);
			}
		}
		
	}
	return (-1);
}

int find_rank_down(t_list **list_a, t_list **list_b, int middle, t_list	*last_top, t_list *tmp, int max_full_list)
{
	int		c;
	int		max_a;
	int		min_a;
	int		size_a;
	t_list	*last;

	c = 0;
	size_a = ft_lstsize(*list_a);
	last = last_elt(list_a, size_a);
	max_a = biggest(list_a);
	min_a = smallest(list_a);
	if (((*list_b)->index > max_full_list) && (last->index == max_full_list))
		return (-1);
	else if ((*list_b)->index < (*list_a)->index)
	{
		 if (((*list_b)->index > last_top->index))
			return (0);
		if ((*list_a)->index == min_a && last_top->index == max_full_list)
			return (0);
		if ((middle > 1) && (*list_a)->index == max_a && (*list_b)->index > (*list_a)->next->index)
		{
			(*list_a) = (*list_a)->next;
			c++;
			middle--;
		}
		else if (((*list_b)->index > last->index) && ((*list_a)->index < max_a))
			return (-1);
		else if (((*list_b)->index > last->index) && ((*list_b)->index > tmp->index))
			return (-1);
		else
		{
			while ((middle > 0) && (*list_a))
			{
				while (((*list_b)->index < (*list_a)->index) && ((*list_a)->index < max_a))
				{
					(*list_a) = (*list_a)->next;
					c++;
					middle--;
				}
				if ((middle == 1) && ((*list_b)->index < (*list_a)->index))
					return (-1);
				else
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
				if ((middle == 0) && ((*list_b)->index < (*list_a)->index))
					return (-1);
				return (c);
			}
			return (c);
		}

	}
	else if((*list_b)->index > (*list_a)->index)
	{
		if ((*list_a)->index == min_a && (*list_b)->index > max_full_list)
			return (0);
		while ((middle > 0) && (*list_a))
		{
			while (((*list_b)->index > (*list_a)->index) && ((*list_a)->index < max_a))
			{
				(*list_a) = (*list_a)->next;
				c++;
				middle--;
			}
			if ((middle == 1) && ((*list_b)->index > (*list_a)->index))
				return (-1);
			if (((*list_a)->index == max_a) && (*list_b)->index > (*list_a)->index)
				return (c + 1);
			if ((*list_a)->index == max_a && (*list_b)->index > (*list_a)->index)
				return (c + 1);
			return (c);
		}
		return (-1);
	}
	return (-1);
}