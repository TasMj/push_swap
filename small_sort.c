/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:17:17 by tmejri            #+#    #+#             */
/*   Updated: 2022/11/27 03:34:03 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* swap a et b si a > b, sinon renvoie la liste de départ */
void	sort_for_2(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	if ((*list)->content > (*list)->next->content)
		sa(list);
	*list = tmp;
}

void	annex_sort_3(t_list **list, t_full_list full_list)
{
	if (full_list.tmp->content < full_list.last_elt->content)
		sa(list);
	else if (full_list.midd->content > full_list.last_elt->content)
	{
		sa(list);
		rra(list);
	}
	else if (full_list.midd->content < full_list.last_elt->content)
		ra(list);
}

/* trie dans l'ordre croissant une liste de 3 elts en fonction
de tous les differents cas de figures qu'on peut rencontrer */
void	sort_for_3(t_list **list)
{
	t_full_list	full_list;

	full_list.tmp = *list;
	full_list.midd = (*list)->next;
	full_list.last_elt = full_list.midd->next;
	if (full_list.tmp->content > full_list.midd->content)
		annex_sort_3(list, full_list);
	else if (full_list.tmp->content < full_list.midd->content)
	{
		if (full_list.tmp->content > full_list.last_elt->content)
			rra(list);
		else if (full_list.midd->content > full_list.last_elt->content)
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
