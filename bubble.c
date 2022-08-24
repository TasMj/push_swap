/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:34:16 by tas               #+#    #+#             */
/*   Updated: 2022/08/24 20:59:57 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**ft_bubble_sort(t_list **list_stack)
{
	t_list	*tmp;
	int		size;

	(*list_stack) = (*list_stack)->premier;
	size = ft_lstsize((*list_stack));
	tmp = (*list_stack)->next;
	while (size > 1)
	{
		while ((*list_stack)->next != NULL)
		{
			if ((*list_stack)->content > tmp->content)
			{
				sa(list_stack);
				write(1, "sa\n", 3);
			}
			(*list_stack) = (*list_stack)->next;
			tmp = (*list_stack)->next;
		}
		(*list_stack) = (*list_stack)->premier;
		tmp = (*list_stack)->next;
		size--;
	}
	(*list_stack) = (*list_stack)->premier;
	return (list_stack);
}

// int main(int argc, char **argv)
// {
	// t_list	**list;
// 
	// list = attribution_arg(argc, argv);
	// printf("\n******sorting process******\n\n");
	// ft_bubble_sort(list);
	// printf("\n******after sort******\n\n");
	// printf("STACK A\n");
	// list = ft_print(list);
// }