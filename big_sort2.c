/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:09:56 by tmejri            #+#    #+#             */
/*   Updated: 2022/11/28 01:10:43 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* return la position d'en haut du premier elt du block rencontre */
int	du_haut(t_list **list, t_elt elt, int *b)
{
	int		c;
	t_list	*tmp;

	c = 0;
	tmp = *list;
	while (*list)
	{
		if (is_in_block(*list, elt) == 1)
		{
			(*b) = (*list)->index;
			*list = tmp;
			return (c);
		}
		else
		{
			c++;
			(*list) = (*list)->next;
		}
	}
	return (-1);
}

/* return l'indice de l'elm a l'indice position */
void	ft_end(t_list **list, int size_list)
{
	while (size_list > 0)
	{
		(*list) = (*list)->next;
		size_list--;
	}
}

/* return la position d'en bas du premier elt du block rencontre */
int	du_bas(t_list **list, t_elt elt, int *a)
{
	int		c;
	int		size_list;
	t_list	*tmp;

	c = 0;
	tmp = *list;
	size_list = ft_lstsize(*list) - 1;
	while (*list)
	{
		ft_end(list, size_list);
		if (is_in_block(*list, elt) == 1)
		{
			(*a) = (*list)->index;
			*list = tmp;
			return (c);
		}
		else
		{
			c++;
			size_list--;
			*list = tmp;
		}
	}
	*list = tmp;
	return (-1);
}
