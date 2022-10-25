/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:32:05 by tmejri            #+#    #+#             */
/*   Updated: 2022/10/25 15:56:33 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_list **list_a, t_list **list_b)
{
	int size_list;
	int nb_tour;
	t_list	*nex;

	size_list = ft_lstsize(*list_a);
	nb_tour = size_list;
	while (nb_tour)
	{
		nex = (*list_a)->next;
		while (size_list > 1)
		{
			if (nex && ((*list_a)->content > nex->content))
			{
				printf("content: %d, next:  %d\n", (*list_a)->content, nex->content);
				sa(list_a);
				ra(list_a);
			}
			else
				ra(list_a);
			size_list--;
			nex = (*list_a)->next;
		}
		pb(list_b, list_a);
		nb_tour--;
        size_list = nb_tour;
	}
}

// int main(int argc, char **argv)
// {
// 	t_list **list;
// 	t_list **list_b;

// 	list = attribution_arg(argc, argv, 2);
// 	list_b = malloc(sizeof(t_list));
// 	bubble_sort(list, list_b);
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









// void	bubble_sort(t_list **list, t_list **b)
// {
// 	int size_list;
// 	// int nb_tour;
// 	t_list	*nex;

// 	size_list = ft_lstsize(*b);
//     printf("SIZE B: %d\n", ft_lstsize(*b));
// 	// nb_tour = size_list;
// 	// while (nb_tour)
// 	// {
// 		while (size_list)
// 		{
// 			nex = (*b)->next;
// 			printf("content: %d, next:  %d\n", (*b)->content, nex->content);
// 			if ((*b)->content > nex->content)
// 			{
// 				sb(b);
// 				rb(b);
// 			}
// 			else
// 				rb(b);
// 			size_list--;
// 		}
// 		pa(list, b);
// 		// nb_tour--;
//         // size_list = nb_tour;
// 	// }
// }

// int main(int argc, char **argv)
// {
// 	t_list **list;
// 	t_list **list_b;

// 	list_b = attribution_arg(argc, argv, 2);
// 	list = malloc(sizeof(t_list));
// 	// while (*list_b)
// 	// {
// 		// printf("[%d]\n", (*list_b)->content);
// 		// (*list_b) = (*list_b)->next;
//     // }
//     pa(list, list_b);
//     pa(list, list_b);
// 	// bubble_sort(list, list_b);
// 	printf("/////////////// LISTE A //////////////////\n\n");
//     while (*list)
// 	{
// 		printf("[%d]\n", (*list)->content);
// 		(*list) = (*list)->next;
// 	}
// 	// printf("\n////////////// LISTE B //////////////////\n");
// 	// while (*list_b)
// 	// {
// 	// 	printf("[%d]\n", (*list_b)->content);
// 	// 	(*list_b) = (*list_b)->next;
// 	// }
// 	// printf("c: %d\n", c);
// 	// printf("\n////////////////////////////////////////\n");
	
// }