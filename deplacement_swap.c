/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:49:44 by tas               #+#    #+#             */
/*   Updated: 2022/11/18 16:18:41 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/* swap 2 elts d'une liste */
void	ft_swap(t_list **first, t_list *second)
{
	int	p;
	int	index;

	p = (*first)->content;
	(*first)->content = second->content;
	second->content = p;
	index = (*first)->index;
	(*first)->index = second->index;
	second->index = index;
}

/* swap les 2 premiers elts du haut de la stack A */
void	sa(t_list **list_a)
{
	t_list	*temp;

	if ((*list_a)->next != NULL)
	{
		temp = (*list_a)->next;
		ft_swap(list_a, temp);
	}
	write(1, "sa\n", 3);
}	

/* swap les 2 premiers elts du haut de la stack B */
void	sb(t_list **list_b)
{
	t_list	*temp;

	if ((*list_b)->next != NULL)
	{
		temp = (*list_b)->next;
		ft_swap(list_b, temp);
	}
	write(1, "sb\n", 3);
}

/* swap les 2 premiers elts de la stack A et ceux de la stack B */
void	ss(t_list **list_a, t_list **list_b)
{
	sa(list_a);
	sb(list_b);
	write(1, "ss\n", 3);
}
