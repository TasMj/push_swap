/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:47:20 by tmejri            #+#    #+#             */
/*   Updated: 2022/11/17 20:01:49 by tmejri           ###   ########.fr       */
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
	else
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
	else
		return (size_list / 10);
}

/* return 1 si on passe par en haut 2 si par en bas */
int	side(t_list **list, int numero_du_block, int size_one_block, int *a, int *b)
{
	int	up;
	int	down;

	up = du_haut(list, numero_du_block, size_one_block, b);
	down = du_bas(list, numero_du_block, size_one_block, a);
	if ((up <= down && up >= 0) || down == -1)
		return (1);
	else
		return (2);
}

/* return le premier indice du block */
int	block(int numero_du_block, int size_one_block)
{
	if (numero_du_block == 1)
		return (0);
	else if (numero_du_block == 2)
		return (size_one_block);
	else if (numero_du_block == 3)
		return (2 * size_one_block);
	else if (numero_du_block == 4)
		return (3 * size_one_block);
	else if (numero_du_block == 5)
		return (4 * size_one_block);
	else
		return (0);
}

// return 1 si l'indice est compris ds le block 0 sinon
int	is_in_block(t_list *list, int numero_du_block, int size_one_block)
{
	int	min;
	int	max;

	min = block(numero_du_block, size_one_block);
	max = min + size_one_block - 1;
	if (list->index >= min && list->index <= max)
		return (1);
	else
		return (0);
}