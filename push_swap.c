/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:28:11 by tmejri            #+#    #+#             */
/*   Updated: 2022/11/18 16:20:23 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* recupere la liste d'int (stack a) prealablement faite
pour la trier dans l'ordre croissant */
// void	push_swap(int argc, char **argv)
// {

// }

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
	write(2, "Error\n", 6);
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

void    print_list(t_list **list_a, t_list **list_b)
{
    t_list  *tmp;
    t_list  *tmp1;

    tmp = *list_a;
    tmp1 = *list_b;
    printf("/////////////// LISTE A /////////////////\n");
    while (*list_a)
    {
        printf("[%d] -> %d\n", (*list_a)->content, (*list_a)->index);
        (*list_a) = (*list_a)->next;
    }
    printf("\n////////////// LISTE B //////////////////\n");
    while (*list_b)
    {
        printf("[%d] -> %d\n", (*list_b)->content, (*list_b)->index);
        (*list_b) = (*list_b)->next;
    }
    printf("\n////////////// FIN //////////////////\n");
    *list_a = tmp;
    *list_b = tmp1;
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
		if (check_doublon(list_a) != 0)
		{
			free_list(list_a);
			return (error_free_ret(list_b));
		}
		else if (size_list == 1)
		{
			free_list(list_a);
			free_list(list_b);
			return (0);
		}
		direct_sort(size_list, list_a, list_b);
		print_list(list_a, list_b);
	}
	free_list(list_a);
	free_list(list_b);
}
