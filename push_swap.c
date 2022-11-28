/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:28:11 by tmejri            #+#    #+#             */
/*   Updated: 2022/11/28 21:27:56 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list **list)
{
	t_list	*to_free;
	t_list	*iter;

	iter = *list;
	while (iter)
	{
		to_free = iter;
		iter = iter->next;
		free(to_free);
	}
	*list = NULL;
	free(list);
}

int	error_free_ret(t_list **list)
{
	write(2, "Error\n", 8);
	free_list(list);
	return (1);
}

void	direct_sort(int size_list, t_list **list_a, t_list **list_b)
{
	if (size_list == 2)
		sort_for_2(list_a);
	else if (size_list == 3)
		sort_for_3(list_a);
	else if (size_list == 4)
		sort_for_4(list_a, list_b);
	else if (size_list == 5)
		sort_for_5(list_a, list_b);
	else if (size_list > 5)
		sort_all_other(list_a, list_b);
}

int	free_if_wrong(t_list **list_a, t_list **list_b, int size_list)
{
	if (check_doublon(list_a) != 0)
	{
		free_list(list_a);
		return (error_free_ret(list_b));
	}
	else if (size_list == 1)
		free_2_lists(list_a, list_b);
	return (0);
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
	{
		free_list(list_b);
		return (1);
	}
	list_b[0] = NULL;
	if (check_int(argc, argv))
		return (error_free_ret(list_b));
	else
	{
		list_a = attribution_arg(argc, argv, 2);
		size_list = ft_lstsize(*list_a);
		if (free_if_wrong(list_a, list_b, size_list))
			return (1);
		if (size_list < 2)
			return (1);
		direct_sort(size_list, list_a, list_b);
	}
	free_2_lists(list_a, list_b);
}
