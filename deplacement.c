/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:49:44 by tas               #+#    #+#             */
/*   Updated: 2022/07/29 00:11:46 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// // swap les 2 premiers elts du haut de la stack A
// void    sa(int a, int b)

// // swap les 2 premiers elts du haut de la stack B
// void    sb(int a, int b)

// // swap les 2 premiers elts du haut des stacks A et B
// void    ss()

// ***** OU ALORS ******

// void    swap(t_list stack) // marche pour A et B

#include "push_swap.h"

void    *copy_content(t_list *list_to_copy)
{
    t_list  *new_list;

    new_list = malloc(sizeof(t_list));
    if (!new_list)
        return (NULL);
    new_list->content = list_to_copy->content;
}



void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst && f)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}

void    *swap(t_list **list_stack_a)
{
    t_list *tmp;
    t_list *tmp2;

    while (list_stack_a)
    {
        tmp->content = copy_content(list_stack_a);
        list_stack_a = list_stack_a->next;
        tmp2->content = copy_content(list_stack_a);
    }
}