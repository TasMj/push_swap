/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_hundread_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:42:09 by tmejri            #+#    #+#             */
/*   Updated: 2022/10/12 15:27:34 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* EN FONCTION DE LA TAILLE DE LA STACK A
si ce bool renvoie 1 : si
            1) x < prem elt de la stack a --> pa
            2) x > on cherche entre quel nb et quel nb il est compris et on 
                    ra x la position ou il doit se trouver
                    sa
                    rra x meme nb qu au dessus
si ce bool renvoie 2 : 
            1) x > dernier 
            2) x < on cherche entre quel nb et quel nb il est compris et on 
                    rra x la position ou il doit se trouver
                    pa
                    ra x meme nb qu au dessus */
void	sort_in_stack_a(t_list **list_a, t_list **list_b)
{
	while (*list_b)
	{
		if (up_or_down(list_a, list_b) == 1)
		{
			if ((*list_b)->index < (*list_a)->index)
				pa(list_a, list_b);
			else
				from_top(list_a, list_b);
		}
		else if (up_or_down(list_a, list_b) == 2)
		{
			rra(list_a);
			if ((*list_b)->index > (*list_a)->index)
			{
				ra(list_a);
				pa(list_a, list_b);
				ra(list_a);
			}
			else
				from_down(list_a, list_b);
		}
	}
}

void	sort_for_hundread(t_list **list_a, t_list **list_b, int size_list_a)
{
	int		*tab;

	tab = tab_to_sort(list_a);
	tab = tab_sorted(tab, list_a);
	index_tab(list_a, tab);
	list_b = seperate_by_mediane(list_a, list_b);
	if (size_list_a == 6)
		sort_for_3(list_a);
	if (size_list_a == 7)
		sort_for_4(list_a, list_b);
	else
	{
		stack_to_5(list_a, list_b);
		sort_for_5(list_a, list_b);
	}
	sort_in_stack_a(list_a, list_b);
}
