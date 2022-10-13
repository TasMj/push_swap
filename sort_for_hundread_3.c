/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_hundread_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:42:09 by tmejri            #+#    #+#             */
/*   Updated: 2022/10/13 15:36:16 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* recupere tous les elts d'une liste et les range dans un tableau */
void	*tab_to_sort(t_list **list)
{
	int		size;
	int		*tab_int;
	t_list	*tmp;
	int		i;

	i = 0;
	size = ft_lstsize(*list);
	tab_int = (int *)malloc(sizeof(int) * size);
	tmp = *list;
	while (*list)
	{
		tab_int[i] = (*list)->content;
		(*list) = (*list)->next;
		i++;
	}
	*list = tmp;
	return (tab_int);
}

/* trie dans l'ordre croissant les elts d'un tableau */
void	*tab_sorted(int	*tab, t_list **list)
{
	int	i;
	int	size;
	int	tmp;

	i = 1;
	size = ft_lstsize(*list);
	while (size > 1)
	{
		while (i < size)
		{
			if (tab[i - 1] > tab[i])
			{
				tmp = tab[i];
				tab[i] = tab[i - 1];
				tab[i - 1] = tmp;
			}
			i++;
		}
		i = 1;
		size--;
	}
	return (tab);
}

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
		sort_for_3(list_a, (*list_a)->next, (*list_a)->next->next);
	if (size_list_a == 7)
		sort_for_4(list_a, list_b);
	else
	{
		stack_to_5(list_a, list_b);
		sort_for_5(list_a, list_b);
	}
	sort_in_stack_a(list_a, list_b);
}
