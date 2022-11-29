/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:09:56 by tmejri            #+#    #+#             */
/*   Updated: 2022/11/29 15:10:21 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	for_exit(t_list **list_a, t_list **list_b, int size_list)
{
	if (free_if_wrong(list_a, list_b, size_list))
		return (1);
	if (size_list < 2)
		return (1);
	if (is_sorted(list_a) == 0)
	{
		free_2_lists(list_a, list_b);
		return (1);
	}
	return (0);
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

int	from_down(t_list **list_a, t_list **list_b)
{
	int			r;
	int			keep_middle;
	t_full_list	full_list;

	full_list.tmp = *list_a;
	full_list.size = ft_lstsize(*list_a);
	full_list.middle = middle_size(list_a);
	full_list.last_top = *list_a;
	full_list.max_full_list = biggest(list_a);
	full_list.last_elt = last_elt(list_a, full_list.size);
	keep_middle = full_list.middle;
	r = annex_down(list_a, list_b, full_list, keep_middle);
	*list_a = full_list.tmp;
	return (r);
}

int	is_sorted(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while ((*list)->next)
	{
		if (!((*list)->content < (*list)->next->content))
		{
			*list = tmp;
			return (1);
		}
		(*list) = (*list)->next;
	}
	*list = tmp;
	return (0);
}
