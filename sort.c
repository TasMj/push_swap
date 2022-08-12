/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:16:33 by tmejri            #+#    #+#             */
/*   Updated: 2022/08/12 19:02:08 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**ft_sort_int_tab(t_list **list_stack)
{
	t_list	*tmp;
	t_list	**b;
	int		size;
	int		c;

	c = 0;
    b = malloc(sizeof(t_list));
	tmp = (*list_stack)->next;
	size = ft_lstsize((*list_stack));
	while (size > 0)
	{
		while ((*list_stack)->next != NULL)
		{
			printf("list: [%d],  tmp: [%d] | size: %d\n", (*list_stack)->content, tmp->content, size);
			if ((*list_stack)->content < tmp->content)
			{
				ft_swap((*list_stack), tmp);
				c++;
			}
			(*list_stack) = (*list_stack)->next;
			tmp = (*list_stack)->next;
		}
		printf("###############################\n");
		(*list_stack) = (*list_stack)->premier;
		tmp = (*list_stack)->next;
		size--;
		rra(list_stack);
		pb(b, list_stack);
		(*list_stack) = (*list_stack)->next;
	}
	(*list_stack) = (*list_stack)->premier;
	printf("c = %d\n", c);
	printf("\nSTACK B\n");
	ft_print(b);
	return (list_stack);
}

// void	ft_sort_int_tab(int *tab, int size)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < size)
// 	{	
// 		j = i + 1;
// 		while (j < size)
// 		{
// 			if (tab[i] > tab[j])
// 			{	
// 				ft_swap(&tab[i], &tab[j]);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	ft_rev_int_tab(t_list **list_stack)
// {
// 	int	i;
// 	int size;
// 	int	cal;

// 	size = ft_lstsize(list_stack);
// 	cal = size - 1;
// 	i = 0;
// 	while (i < (size / 2))
// 	{
// 		ft_swap(&tab[i], &tab[cal]);
// 		i++;
// 		cal--;
// 	}
// }

int main(int argc, char **argv)
{
	t_list	**list;

	list = attribution_arg(argc, argv);
	
	printf("\n******sorting process******\n\n");
	ft_sort_int_tab(list);

	printf("\n******after sort******\n\n");
	printf("STACK A\n");
	list = ft_print(list);
	
}
