/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:33:20 by tmejri            #+#    #+#             */
/*   Updated: 2022/10/18 11:33:21 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// // 1) en fonction du nb d'elt separer en plusieurs partie
// // 2) trier ds un tab
// // 3) pb les derniers du tab en fonction du nb d'elt de la liste en commençant 
// // par les derniers du tab
// // 4) une fois trier les pa
// // 5) refaire 3 et 4 jusqua ce que tout soit trié


// // si c'est au dessus de la premiere partie on pb et on trie


// // 1) en fonction du nb d'elt separer en plusieurs partie
// int	size_block(t_list **list_a)
// {
//     int	size_list;
	
//     size_list = ft_lstsize(list_a);
//     if (size_list < 51)
// 		return (size_list / 2);
//     if (size_list < 101)
// 		return (size_list / 4);
//     if (size_list < 200)
// 		return (size_list / 4);

	
// }

// // 2) trier ds un tab ds l'ordre décroissant
// void	*tab_to_sort(t_list **list)
// {
// 	int		size;
// 	int		*tab_int;
// 	t_list	*tmp;
// 	int		i;

// 	i = 0;
// 	size = ft_lstsize(*list);
// 	tab_int = (int *)malloc(sizeof(int) * size);
// 	tmp = *list;
// 	while (*list)
// 	{
// 		tab_int[size] = (*list)->content;
// 		(*list) = (*list)->next;
// 		size--;
// 	}
// 	*list = tmp;
// 	return (tab_int);
// }

// // trouver l'indice du premier elt du bloc
// int	find_index_block(t_list **list)
// {
// 	int	index;

// 	index = 
// }

// void	creat_block(t_list **list_a, t_list **list_b, int *tab_sorted)
// {
// 	int size_block;
// 	int	i;

// 	i = 0;
// 	size_block = size_block(list_a);
// 	while(size_block)
// 	{
// 		while (tab[i])
// 		{
// 			while (*list_a)
// 			{
// 				if ((*list_a)->content == tab[i])
					
// 				(*list_a) = (*list_a)->next;
// 			}
// 		}
// 	}
// 	size_block--;
// }



// void	sort_by_block(t_list **list_a, t_list **list_b)
// {
// 	int		*tab;

// 	tab = tab_to_sort(list_a);
// 	tab = tab_sorted(tab, list_a);
// 	index_tab(list_a, tab);
	
	
// 	list_b = seperate_by_mediane(list_a, list_b);
// 	if (size_list_a == 6)
// 		sort_for_3(list_a, (*list_a)->next, (*list_a)->next->next);
// 	if (size_list_a == 7)
// 		sort_for_4(list_a, list_b);
// 	else
// 	{
// 		stack_to_5(list_a, list_b);
// 		sort_for_5(list_a, list_b);
// 	}
// 	sort_in_stack_a(list_a, list_b);
// }