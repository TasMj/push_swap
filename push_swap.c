/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:28:11 by tmejri            #+#    #+#             */
/*   Updated: 2022/10/12 16:32:15 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* recupere la liste d'int (stack a) prealablement faite
pour la trier dans l'ordre croissant */
void	push_swap(int argc, char **argv)
{
	t_list	**list_a;
	t_list	**list_b;
	int		size_list;
	t_list	*tmp;

	list_b = malloc(sizeof(t_list));
	if (check_int(argc, argv))
	{
		write(2, "Error\n", 6);
		free (list_b);
		return ;
	}
	else
	{
		list_a = attribution_arg(argc, argv, 2);
		tmp = *list_a;
		size_list = ft_lstsize(*list_a);
		if (check_doublon(list_a) != 0)
			write(2, "Error\n", 6);
		else if (size_list == 1)
			return ;
		else if (size_list == 2)
			sort_for_2(list_a);
		else if (size_list == 3)
			sort_for_3(list_a);
		else if (size_list == 4)
		{
			(*list_a) = tmp;
			sort_for_4(list_a, list_b);
		}
		else if (size_list == 5)
		{
			(*list_a) = tmp;
			sort_for_5(list_a, list_b);
		}
		else if (size_list > 5)
		{
			(*list_a) = tmp;
			sort_for_hundread(list_a, list_b, size_list);
		}
	}
	ft_print(list_a);
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
}
