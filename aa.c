// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   aa.c                                               :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/11/16 14:34:16 by tmejri            #+#    #+#             */
// /*   Updated: 2022/11/25 10:43:13 by tas              ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"



// int find_rank_top(t_list **list_a, t_list **list_b, int middle)
// {
// 	int	c;
// 	int	size_a;
// 	int max_a;
// 	int min_a;
// 	t_list	*last;
// 	t_list	*midd;

// 	c = 0;
// 	max_a = biggest(list_a);
// 	min_a = smallest(list_a);
// 	size_a = ft_lstsize(*list_a);
// 	last = last_elt(list_a, size_a);
// 	midd = last_elt(list_a, middle);
// 	// printf("middle: %d\n", middle);
// 	// printf("B: %d\n", (*list_b)->index);
// 	// printf("last index: %d\n", last->index);
// 	// printf("A: %d\n", (*list_a)->index);
// 	// printf("MAX: %d\n", max_a);
// 	// printf("MIN: %d\n", min_a);

	
// 	if (((*list_b)->index > max_a) && (last->index == max_a))
// 		return (0);
// 	else if ((*list_b)->index < (*list_a)->index)
// 	{
// 		if (last->index == max_a)
// 			return (0);
// 		else if (((*list_b)->index < (*list_a)->index) && ((*list_b)->index > last->index) && ((*list_a)->index == max_a))
// 			return (0);
// 		else if ((((*list_b)->index < (*list_a)->index) && ((*list_b)->index > last->index)) && ((*list_a)->index < max_a))
// 			return (0);
// 		else if (((*list_b)->index > midd->index))
// 		{
// 			printf("555555555555555555555\n");
// 			while ((*list_a) && middle > 0)
// 			{
// 				while (((*list_b)->index < (*list_a)->index) && (*list_a)->index > min_a)
// 				{
// 					(*list_a) = (*list_a)->next;
// 					c++;
// 					middle--;
// 				}
// 				if ((middle > 1) && ((*list_a)->index == max_a) && ((*list_a)->next->index == min_a))
// 				{
// 					printf("smlp\n");
// 					return (c);
// 				}
// 				while ((*list_b)->index > (*list_a)->index)
// 				{
// 					(*list_a) = (*list_a)->next;
// 					c++;
// 					middle--;
// 				}
// 				return (c);
// 			}
// 			return (c);
// 		}
// 		else if (((*list_b)->index < last->index))
// 		{
// 			printf("888888888888888888888\n");
// 			while ((*list_a) && middle > 0)
// 			{
// 				while ((*list_a)->index != max_a && middle > 0)
// 				{
// 					(*list_a) = (*list_a)->next;
// 					c++;
// 					middle--;
// 				}
// 				printf("middle: %d\n", middle);
// 				printf("index: %d\n", (*list_a)->index);
// 				if ((middle == 0) && ((*list_b)->index > (*list_a)->index))
// 					return (-1);
// 				else
// 				{
// 					if ((*list_a)->index == max_a)
// 					{
// 						(*list_a) = (*list_a)->next;
// 						c++;
// 						middle--;
// 					}
// 					while ((*list_b)->index > (*list_a)->index)
// 					{
// 						(*list_a) = (*list_a)->next;
// 						c++;
// 						middle--;
// 					}
// 					if ((middle == 0) && ((*list_b)->index > (*list_a)->index))
// 						return (-1);
// 				}
// 				return (c);
// 			}
// 		}
// 		return (-1);
// 	}
// 	else if ((*list_b)->index > (*list_a)->index)
// 	{
// 		if ((*list_a)->index == max_a)
// 			return (1);
// 		else
// 		{
// 			while ((middle > 0) && (*list_a))
// 			{
// 			printf("66666666666666666666\n");
// 				while (((*list_b)->index > (*list_a)->index) && ((middle > 0)))
// 				{
// 					printf("middle: %d\n", middle);
// 					printf("index: %d\n", (*list_a)->index);
// 					if ((*list_a)->index == max_a)
// 						return (c + 1);
// 					(*list_a) = (*list_a)->next;
// 					c++;
// 					middle--;
// 				}
// 				if (middle == 0 && (*list_a)->index < min_a)
// 					return (-1);
// 				return (c);
// 			}
// 		}
		
// 	}
// 	return (-1);
// }

// int find_rank_down(t_list **list_a, t_list **list_b, int middle, t_list	*last_top, t_list *tmp, int max_full_list, int min_full_list)
// {
// 	int		c;
// 	int		max_a;
// 	int		min_a;
// 	int		size_a;
// 	t_list	*last;

// 	c = 0;
// 	size_a = ft_lstsize(*list_a);
// 	last = last_elt(list_a, size_a);
// 	max_a = biggest(list_a);
// 	min_a = smallest(list_a);
// 	// printf("middle: %d\n", middle);
// 	// printf("first index: %d\n", tmp->index);
// 	// printf("B: %d\n", (*list_b)->index);
// 	// printf("last index: %d\n", last->index);
// 	// printf("A: %d\n", (*list_a)->index);
// 	// printf("MAX: %d\n", max_a);
// 	if (((*list_b)->index > max_full_list) && (last->index == max_full_list))
// 	{
// 		printf("cas 1\n");
// 		return (-1);
// 	}
// 	else if ((*list_b)->index < (*list_a)->index)
// 	{
// 		// if (((*list_b)->index > last->index) && ((*list_a)->index == max_full_list))
// 			// return (1); //may be middle
// 		if ((tmp->index = min_full_list) && (last->index == max_full_list))
// 		{
// 			printf("ANDRES\n")	;
// 			return (-1);
// 		}
// 		 if (((*list_b)->index > last_top->index))
// 		{
// 			printf("22222222222222222222\n");	
// 			return (0);
// 		}
// 		if ((*list_a)->index == min_a && last_top->index == max_full_list)
// 		{
// 			printf("22222222222222222222\n");	
// 			return (0);
// 		}
// 		if (((*list_a)->index == max_a) && (middle > 1) && ((*list_b)->index > (*list_a)->next->index))
// 		{
// 			(*list_a) = (*list_a)->next;
// 			c++;
// 			middle--;
// 		}
// 		else if (((*list_b)->index > last->index) && ((*list_a)->index < max_a))
// 			return (-1);
// 		else if (((*list_b)->index > last->index) && ((*list_b)->index > tmp->index))
// 			return (-1);
// 		else
// 		{
// 		printf("MAX: %d\n", max_a);
// 			while ((middle > 0) && (*list_a))
// 			{
// 				while (((*list_b)->index < (*list_a)->index) && ((*list_a)->index < max_a))
// 				{
// 					printf("333333333333333333\n");
// 					printf("index: %d\n", (*list_a)->index);
// 					(*list_a) = (*list_a)->next;
// 					c++;
// 					middle--;
// 				}
// 				printf("middle fin: %d, listB: %d, listeA: %d\n", middle, (*list_b)->index, (*list_a)->index);
// 				if ((middle == 1) && ((*list_b)->index < (*list_a)->index))
// 				{
// 					printf("PAS DEDANS\n");
// 					return (-1);
// 				}
// 				else
// 				{
// 					printf("on rentre ici");
// 					(*list_a) = (*list_a)->next;
// 					c++;
// 					middle--;
// 				}
// 				while ((*list_b)->index > (*list_a)->index)
// 				{
// 					(*list_a) = (*list_a)->next;
// 					c++;
// 					middle--;
// 				}
// 				// if ((*list_a)->index == max_a && (middle != 0))
// 					// return (c + 1);

// 				if ((middle == 0) && ((*list_b)->index < (*list_a)->index))
// 				{
// 					printf("PAS DEDANS\n");
// 					return (-1);
// 				}
// 				printf("ARRIVEE");
// 				return (c);
// 			}
// 			return (c);
// 		}

// 	}
// 	else if((*list_b)->index > (*list_a)->index)
// 	{
// 		while ((middle > 0) && (*list_a))
// 		{
// 		printf("7777777777777777777777777777\n");
// 			while (((*list_b)->index > (*list_a)->index) && ((*list_a)->index < max_a))
// 			{
// 			printf("index: %d\n", (*list_a)->index);
// 			printf("MIDDLE: %d\n", middle);
// 				(*list_a) = (*list_a)->next;
// 				c++;
// 				middle--;
// 			}
// 			printf("c: %d  mid: %d A: %d  B:%d\n", c, middle, (*list_a)->index, (*list_b)->index);
// 			if ((middle == 1) && ((*list_b)->index > (*list_a)->index))
// 			{
// 				printf("^^^^^");
// 				return (-1);
// 			}
// 			if (((*list_a)->index == max_a) && (*list_b)->index > (*list_a)->index)
// 			{
// 				printf("^^^^^");
// 				return (c + 1);
// 			}
			
// 			if ((*list_a)->index == max_a && (*list_b)->index > (*list_a)->index)
// 				return (c + 1);
// 			printf("aaaaaaaaaannnnnnnnnnndreeeeeeeeeeeesssssssssssssss\n");
// 			return (c);
// 		}
// 		return (-1);
// 	}
// 	return (-1);
// }
