/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:16:33 by tmejri            #+#    #+#             */
/*   Updated: 2022/08/17 17:10:52 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_list	**ft_sort_int_tab(t_list **list_stack)
// {
// 	t_list	*tmp;
// 	t_list	**b;
// 	int		size;
// 	int		c;

// 	c = 0;
//     b = malloc(sizeof(t_list));
// 	tmp = (*list_stack)->next;
// 	size = ft_lstsize((*list_stack));
// 	while (size > 0)
// 	{
// 		while ((*list_stack)->next != NULL)
// 		{
// 			printf("list: [%d],  tmp: [%d] | size: %d\n", (*list_stack)->content, tmp->content, size);
// 			if ((*list_stack)->content > tmp->content)
// 			{
// 				ft_swap((*list_stack), tmp);
// 				c++;
// 			}
// 			(*list_stack) = (*list_stack)->next;
// 			tmp = (*list_stack)->next;
// 		}
// 		printf("###############################\n");
// 		(*list_stack) = (*list_stack)->premier;
// 		tmp = (*list_stack)->next;
// 		size--;
// 	}
// 	(*list_stack) = (*list_stack)->premier;
// 	printf("c = %d\n", c);
// 	printf("\nSTACK B\n");
// 	ft_print(b);
// 	return (list_stack);
// }

int unite(int a)
{
	while (a > 9)
		a = a % 10;
	return (a);
}

int	ordre_croissant(t_list **list_stack)
{
	t_list	*tmp;
	
	tmp = (*list_stack)->next;	
	while ((*list_stack)->next != NULL)
	{
		if((*list_stack)->content < tmp->content)
			return (1);
		else
		{
			(*list_stack) = (*list_stack)->next;
			tmp = (*list_stack)->next;
		}
	}
	return (0);
}

t_list	**divise_content(t_list **list)
{
	while((*list)->next != NULL)
	{
		(*list)->content = ((*list)->content / 10);
		(*list) = (*list)->next;
	}
	(*list)->content = ((*list)->content / 10);
	(*list) = (*list)->premier;
	return (list);
}

int	empty_list(t_list **list)
{
	while ((*list)->next != NULL)
	{
		if ((*list)->content != 0)
			return (1);
	}
	return (0);
}

// compare unité puis dizaine puis centaine
t_list	**ft_bubble_sort(t_list **list_stack)
{
	t_list	*tmp;
	int		size;
	int		comp_a;
	int		comp_b;
	int		div_a;
	int		div_b;

	size = ft_lstsize((*list_stack));
	tmp = (*list_stack)->next;
	while (size >= 0)
	{
		while ((*list_stack)->next != NULL)
		{
			div_a = (*list_stack)->content;
			div_b = tmp->content;
			printf("A: %d   B:%d\n",div_a, div_b);
			comp_a = unite(div_a);
			comp_b = unite(div_b);
			printf("div_a [%d]---> %d\n", div_a, comp_a);
			printf("div_b [%d]---> %d\n\n", div_b, comp_b);
			if (comp_a < comp_b)
				ft_swap((*list_stack), tmp);
			(*list_stack) = (*list_stack)->next;
			tmp = (*list_stack)->next;
		}
		printf("***TOUR***\n");
		(*list_stack) = (*list_stack)->premier;
		tmp = (*list_stack)->next;
		size--;
	}
	(*list_stack) = (*list_stack)->premier;
	return (list_stack);
}

t_list	**ft_the_tri(t_list **list_stack)
{
	t_list	**new_list;
	int		size;

	size = ft_lstsize((*list_stack));
	ft_bubble_sort(list_stack);
	new_list = list_stack;
	while (ordre_croissant(list_stack) != 0)
	{
		while (size > 0)
		{
			new_list = divise_content(new_list);
			ft_bubble_sort(new_list);
			size--;	
		}
		if (empty_list(new_list) == 1)
			break;
	}
	(*new_list) = (*new_list)->premier;
	return (new_list);
}

int main(int argc, char **argv)
{
	t_list	**list;

	list = attribution_arg(argc, argv);
	
	printf("\n******sorting process******\n\n");
	ft_the_tri(list);
	printf("\n******after sort******\n\n");
	printf("STACK A\n");
	list = ft_print_all(list);
}
