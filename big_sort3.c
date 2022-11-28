/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:21:44 by tmejri            #+#    #+#             */
/*   Updated: 2022/11/28 01:21:42 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* recup l'elt par le haut de la liste */
void	from_top_to_b(t_list **list_a, t_list **list_b, int b)
{
	while ((*list_a)->index != b)
		ra(list_a);
	if ((*list_a)->index == b)
		pb(list_b, list_a);
}

/* recup l'elt par le bas de la liste */
void	from_down_to_b(t_list **list_a, t_list **list_b, int a)
{
	while ((*list_a)->index != a)
		rra(list_a);
	if ((*list_a)->index == a)
		pb(list_b, list_a);
}

void	big_sort(t_list **list_a, t_list **list_b, int block_size)
{
	int		a;
	int		b;
	t_elt	elt;

	elt.num_block = 1;
	elt.size_one_block = size_block(list_a);
	elt.save_size_beg = size_block(list_a);
	while (block_size > 1)
	{
		while (elt.size_one_block > 0)
		{
			if (side(list_a, elt, &a, &b) == 1)
				from_top_to_b(list_a, list_b, b);
			else if (side(list_a, elt, &a, &b) == 2)
				from_down_to_b(list_a, list_b, a);
			elt.size_one_block--;
		}
		elt.size_one_block = elt.save_size_beg;
		elt.num_block++;
		block_size--;
	}
}

void	diminuer(t_list **list_a, t_list **list_b)
{
	int	size_a;

	size_a = ft_lstsize(*list_a);
	if (size_a == 2)
		sort_for_2(list_a);
	if (size_a == 3)
		sort_for_3(list_a);
	if (size_a == 4)
		sort_for_4(list_a, list_b);
	if (size_a == 5)
		sort_for_5(list_a, list_b);
	if (size_a > 5)
	{
		stack_to_5(list_a, list_b);
		sort_for_5(list_a, list_b);
	}
}

void	sort_all_other(t_list **list_a, t_list **list_b)
{
	int	*tab;
	int	block_size;

	tab = tab_to_sort(list_a);
	tab = tab_sorted(tab, list_a);
	index_tab(list_a, tab);
	free(tab);
	block_size = five_or_ten(list_a);
	big_sort(list_a, list_b, block_size);
	diminuer(list_a, list_b);
	sort_in_stack_a(list_a, list_b);
}
