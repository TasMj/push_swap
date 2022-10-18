/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:28:11 by tmejri            #+#    #+#             */
/*   Updated: 2022/10/18 18:11:09 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* recupere la liste d'int (stack a) prealablement faite
pour la trier dans l'ordre croissant */
// void	push_swap(int argc, char **argv)
// {

// }

int	error_free_ret(t_list *list)
{
	write(2, "Error\n", 6);
	free (list);
	return (1);
}

void	direct_sort(int size_list, t_list **list_a, t_list **list_b)
{
	if (size_list == 2)
		sort_for_2(list_a);
	else if (size_list == 3)
		sort_for_3(list_a, (*list_a)->next, (*list_a)->next->next);
	else if (size_list == 4)
		sort_for_4(list_a, list_b);
	else if (size_list == 5)
		sort_for_5(list_a, list_b);
	else if (size_list > 5)
		sort_for_hundread(list_a, list_b, size_list);
}

int	main(int argc, char **argv)
{
	t_list	**list_a;
	t_list	**list_b;
	int		size_list;

	if (argc < 2)
		return (1);
	list_b = malloc(sizeof(t_list));
	if (!list_b)
		return (1);
	list_b[0] = NULL;
	if (check_int(argc, argv))
		return (error_free_ret(*list_b));
	else
	{
		list_a = attribution_arg(argc, argv, 2);
		size_list = ft_lstsize(*list_a);
		if (check_doublon(list_a) != 0)
			return (error_free_ret(*list_b));
		else if (size_list == 1)
			return (0);
		direct_sort(size_list, list_a, list_b);
	}
}
