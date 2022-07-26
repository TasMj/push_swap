/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:47:20 by tmejri            #+#    #+#             */
/*   Updated: 2022/11/28 01:13:16 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* return 5 si il y a <= 100 nb et 10 sinon 
5 et 10 etant le nb de blocks */
int	five_or_ten(t_list **list_a)
{
	int	size_list;

	size_list = ft_lstsize(*list_a);
	if (size_list <= 100)
		return (5);
	if (size_list > 100)
		return (10);
	return (0);
}

/* return le nb d'elt par block (en blocks de 5 si <= 100
en blocks de 10 si > 100) */
int	size_block(t_list **list_a)
{
	int	size_list;

	size_list = ft_lstsize(*list_a);
	if (size_list <= 100)
		return (size_list / 5);
	return (size_list / 10);
}

/* return 1 si on passe par en haut 2 si par en bas */
int	side(t_list **list, t_elt elt, int *a, int *b)
{
	int	up;
	int	down;

	up = du_haut(list, elt, b);
	down = du_bas(list, elt, a);
	if ((up <= down && up >= 0) || down == -1)
		return (1);
	return (2);
}

/* return le premier indice du block */
int	block(t_elt elt)
{
	if (elt.num_block == 1)
		return (0);
	else if (elt.num_block == 2)
		return (elt.save_size_beg);
	else if (elt.num_block == 3)
		return (2 * elt.save_size_beg);
	else if (elt.num_block == 4)
		return (3 * elt.save_size_beg);
	else if (elt.num_block == 5)
		return (4 * elt.save_size_beg);
	else if (elt.num_block == 6)
		return (5 * elt.save_size_beg);
	else if (elt.num_block == 7)
		return (6 * elt.save_size_beg);
	else if (elt.num_block == 8)
		return (7 * elt.save_size_beg);
	else if (elt.num_block == 9)
		return (8 * elt.save_size_beg);
	else if (elt.num_block == 10)
		return (9 * elt.save_size_beg);
	return (0);
}

// return 1 si l'indice est compris ds le block 0 sinon
int	is_in_block(t_list *list, t_elt elt)
{
	int	min;
	int	max;

	min = block(elt);
	max = min + elt.save_size_beg - 1;
	if (list->index >= min && list->index <= max)
		return (1);
	return (0);
}
