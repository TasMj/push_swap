/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:17:17 by tmejri            #+#    #+#             */
/*   Updated: 2022/10/12 15:32:41 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* trie dans l'ordre croissant une liste de 4 elts en fonction
de tous les differents cas de figures qu'on peut rencontrer */
void	sort_for_4(t_list **list_a, t_list **list_b)
{
	pb(list_b, list_a);
	sort_for_3(list_a);
	pa(list_a, list_b);
	part_1_sort_5(list_a);
}
