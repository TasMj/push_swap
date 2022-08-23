/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:16:33 by tmejri            #+#    #+#             */
/*   Updated: 2022/08/23 17:17:50 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

//garde en memoire la valeur de l'unité de chaque contente
void	stockage_unite(t_list **list)
{
	(*list) = (*list)->premier;
	while ((*list)->next != NULL)
	{
		(*list)->stockage = (*list)->content;
		(*list) = (*list)->next;
	}
	(*list)->stockage = (*list)->content;
	(*list) = (*list)->premier;
}

void	compare_unite(t_list **list_stack)
{
	t_list	*tmp;
	int		comp_a;
	int		comp_b;
	int		div_a;
	int		div_b;
	int 	standby;

	tmp = (*list_stack)->next;
	standby = 0;
	div_a = (*list_stack)->content;
	div_b = tmp->content;
	comp_a = unite(div_a);
	comp_b = unite(div_b);
	if (comp_a > comp_b)
	{
		sa(list_stack);
		standby = (*list_stack)->stockage;
		(*list_stack)->stockage = tmp->stockage;
		tmp->stockage = standby;
	}
	(*list_stack) = (*list_stack)->next;
	tmp = (*list_stack)->next;
}


// compare unité puis dizaine puis centaine
t_list	**ft_pre_radix(t_list **list_stack)
{
	int		size;

	size = ft_lstsize((*list_stack));
	while (size >= 0)
	{
		while ((*list_stack)->next != NULL)
			compare_unite(list_stack);
		(*list_stack) = (*list_stack)->premier;
		size--;
	}
	(*list_stack) = (*list_stack)->premier;
	return (list_stack);
}

t_list	**ft_radix(t_list **list_stack)
{
	t_list	**new_list;
	
	stockage_unite(list_stack);
	new_list = ft_pre_radix(list_stack);
	while (ordre_croissant(list_stack) != 0)
	{
		new_list = divise_content(new_list);
		new_list =ft_pre_radix(new_list);
	}
	(*new_list) = (*new_list)->premier;
	while ((*new_list)->next != NULL)
	{
		(*new_list)->content = (*new_list)->stockage;
		(*new_list) = (*new_list)->next;	
	}
	(*new_list)->content = (*new_list)->stockage;
	(*new_list) = (*new_list)->premier;
	new_list = ft_print(new_list);
	return (new_list);
}

// 
// int main(int argc, char **argv)
// {
	// t_list	**list;
// 
	// list = attribution_arg(argc, argv);
	// 
	// ft_radix(list);
	// printf("STACK A\n");
	// list = ft_print_all(list);
// }