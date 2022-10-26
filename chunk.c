/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:33:20 by tmejri            #+#    #+#             */
/*   Updated: 2022/10/26 12:52:51 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// // // 1) en fonction du nb d'elt separer en plusieurs partie
// // // 2) trier ds un tab
// // // 3) pb les derniers du tab en fonction du nb d'elt de la liste en commençant 
// // // par les derniers du tab
// // // 4) une fois trier les pa
// // // 5) refaire 3 et 4 jusqua ce que tout soit trié


// // // si c'est au dessus de la premiere partie on pb et on trie


// // 1) en fonction du nb d'elt separer en plusieurs partie
// int	size_block(t_list **list_a)
// {
//     int	size_list;
	
//     size_list = ft_lstsize(*list_a);
//     if (size_list <= 50)
// 		return (size_list / 2);
//     else if (size_list <= 100)
// 		return (size_list / 4);
//     else if (size_list <= 200)
// 		return (size_list / 6);
//     else
//     	return (size_list / 10);
// }



// /* Creation d'un block */
// // void	creat_block(t_list **list_a, t_list **list_b, int *tab)
// // {
// // 	int size_of_block;
// // 	int	i;
// //     t_list  *tmp;

// // 	i = 0;
// //     tmp = *list_a;
// // 	size_of_block = size_block(list_a);
// //     tab = tab_to_sort(list_a);
// //     tab = tab_sorted(tab, list_a);
// // 	while(size_of_block)
// // 	{
// // 		while (*list_a)
// // 		{
// // 			while (tab[i])
// // 			{
// // 				if ((*list_a)->content == tab[i])
// // 					pb(list_b, list_a);
// //                 else
// //                     i++;
// // 			}
// //             i = 0;
// // 		}
// // 	    size_of_block--;
// // 	}
// //     *list_a = tmp;
// // }

// void	sort_by_block(t_list **list_a, t_list **list_b)
// {
// 	int		*tab;

// 	tab = tab_to_sort(list_a);
// 	tab = tab_sorted(tab, list_a);
// 	index_tab(list_a, tab);
	
// 	list_b = creat_block(list_a, list_b);
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

// int main(int argc, char **argv)
// {
// 	t_list **list;
// 	t_list **list_b;
//     int    *tab;
//     int i = 0;

// 	list = attribution_arg(argc, argv, 2);
// 	list_b = malloc(sizeof(t_list));
// 	// bubble_sort(list, list_b);
//     tab = tab_to_sort(list);
//     tab = tab_sorted(tab, list);
// 	index_tab(list, tab);
//     // creat_block(list, list_b, tab);
//    	printf("TAAAAAAAAAAAAAAAAB\n\n");
// 	while (tab[i])
// 	{
// 		printf("[%d]\n", tab[i]);
// 		i++;
// 	}

// 	printf("/////////////// LISTE A /////////////////\n\n");
// 	while (*list)
// 	{
// 		printf("[%d]\n", (*list)->content);
// 		(*list) = (*list)->next;
// 	}
// 	printf("\n////////////// LISTE B //////////////////\n");
// 	while (*list_b)
// 	{
// 		printf("[%d]\n", (*list_b)->content);
// 		(*list_b) = (*list_b)->next;
// 	}
// 	printf("////////////////////////////////\n");
	
// }












// // 2) trier ds un tab ds l'ordre décroissant
// void	*tab_to_sort_dec(t_list **list)
// {
// 	int		size;
// 	int		*tab_int;
// 	t_list	*tmp;
// 	// int		i;

// 	// i = 0;
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