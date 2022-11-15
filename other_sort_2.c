/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:17:17 by tmejri            #+#    #+#             */
/*   Updated: 2022/11/15 16:35:35 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* swap a et b si a > b, sinon renvoie la liste de départ */
void	sort_for_2(t_list **list)
{
	(*list) = (*list)->premier;
	if ((*list)->content > (*list)->next->content)
		sa(list);
}

/* trie dans l'ordre croissant une liste de 3 elts en fonction
de tous les differents cas de figures qu'on peut rencontrer */
void	sort_for_3(t_list **list)
{
	t_list	*middle;
	t_list	*last;
	
	(*list) = (*list)->premier;
	middle = (*list)->next;
	last = (middle)->next;
	if ((*list)->premier->content > middle->content)
	{
		if ((*list)->premier->content < last->content)
			sa(list);
		else if (middle->content > last->content)
		{
			sa(list);
			rra(list);
		}
		else if (middle->content < last->content)
			ra(list);
	}
	else if ((*list)->premier->content < middle->content)
	{
		if ((*list)->premier->content > last->content)
			rra(list);
		else if (middle->content > last->content)
		{
			sa(list);
			ra(list);
		}
	}
}

/* trie dans l'ordre croissant une liste de 4 elts en fonction
de tous les differents cas de figures qu'on peut rencontrer */
void	sort_for_4(t_list **list_a, t_list **list_b)
{
	pb(list_b, list_a);
	sort_for_3(list_a);
	pa(list_a, list_b);
	part_1_sort_5(list_a);
}
