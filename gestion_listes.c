/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_listes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:18:23 by tas               #+#    #+#             */
/*   Updated: 2022/11/28 20:52:48 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	complete_list(t_list **list_a, t_list *start, int nb, char **stock)
{
	int	i;

	i = 1;
	while (stock[i])
	{
		nb = ft_atoi(stock[i]);
		start = ft_lstnew(nb);
		ft_lstadd_back(list_a, start);
		i++;
	}
}

/* découpe argv ds le cas ou argc = 2 (ex: "1 2 3")
et les attribue aux contents de la liste */
t_list	**decomposer_arg(int argc, char **argv, int i)
{
	char	**stockage;
	int		nb;
	t_list	*start;
	t_list	**list_stack_a;

	(void)argc;
	list_stack_a = malloc(sizeof(t_list));
	if (!list_stack_a)
		return (NULL);
	list_stack_a[0] = NULL;
	stockage = ft_split(argv[1], ' ');
	nb = ft_atoi(stockage[0]);
	start = ft_lstnew(nb);
	ft_lstadd_back(list_stack_a, start);
	complete_list(list_stack_a, start, nb, stockage);
	i = 0;
	while (stockage && stockage[i])
	{
		free(stockage[i]);
		i++;
	}
	free(stockage);
	return (list_stack_a);
}

/* attribue chacun des arguments au content d'une liste */
t_list	**attribution_arg(int argc, char **argv, int i)
{
	t_list	*start;
	t_list	**list_stack_a;

	if (argc == 2)
		list_stack_a = decomposer_arg(argc, argv, 1);
	else
	{
		list_stack_a = malloc(sizeof(t_list));
		if (!list_stack_a)
			return (NULL);
		list_stack_a[0] = NULL;
		start = ft_lstnew(ft_atoi(argv[1]));
		ft_lstadd_back(list_stack_a, start);
		while (argc-- > 2)
		{
			start = ft_lstnew(ft_atoi(argv[i++]));
			ft_lstadd_back(list_stack_a, start);
		}
	}
	return (list_stack_a);
}
