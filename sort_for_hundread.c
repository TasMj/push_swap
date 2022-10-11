/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_hundread.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:20:18 by tmejri            #+#    #+#             */
/*   Updated: 2022/10/11 16:44:43 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* recupere tous les elts d'une liste et les range dans un tableau */
void    *tab_to_sort(t_list **list)
{
    int     size;
    int		*tab_int;
	t_list	*tmp;
    int 	i;
    
    i = 0;
    size = ft_lstsize(*list);
    tab_int = (int *)malloc(sizeof(int) * size);
	tmp = *list;
    while (*list)
    {
        tab_int[i] = (*list)->content;
        (*list) = (*list)->next;
        i++;
    }
	*list = tmp;
    return (tab_int);
}

/* trie dans l'ordre croissant les elts d'un tableau */ 
void	*tab_sorted(int	*tab, int argc)
{
	int	i;
	int	size;
	int	tmp;

	i = 1;
	size = argc - 1;
	while (size > 1)
	{
		while (i < size)
		{
			if (tab[i - 1] > tab[i])
			{
				tmp = tab[i];
				tab[i] = tab[i - 1];
				tab[i - 1] = tmp;
			}
			i++;
		}
		i = 1;
		size--;
	}
	return (tab);
}

/* attribue a chaque elt un index en fonction 
de l'indice de ce meme elt dans un tab trie */
void	index_tab(t_list **list, int *tab)
{
	int	i;
	int	size;
	int size_mem;
	t_list	*tmp;
	
	i = 0;
	size = ft_lstsize(*list);
	size_mem = size;
	tmp = *list;
	while (*list)
	{
		while (size > 0)
		{
			if ((*list)->content == tab[i])
			{
				(*list)->index = i;
				size = -1;
			}	
			else
			{
				i++;
				size--;
			}
		}
		(*list) = (*list)->next;
		i = 0;
		size = size_mem;
	}
	*list = tmp;	
}

/* calcule la mediane et push b tous les elt qui ont
un index inferieur a celui de la mediane */
t_list **seperate_by_mediane(t_list **list, t_list **list_b)
{
	t_list	*tmp_a;
	int		size;
	int		mediane;

	tmp_a = *list;
	size = ft_lstsize(*list);
	list_b = malloc(sizeof(t_list));
	mediane = size / 2;
	while (size > 0)
	{
		if (tmp_a->index < mediane)
			pb(list_b, list);
		else
			ra(list);
		size--;
		tmp_a = tmp_a->next;
	}
	(*list_b) = (*list_b)->premier;
	return (list_b);
}

/* pb tous les autres nombres jusqu'a ce qu'il n'en reste plus que 5 ds stack A */
void    stack_to_5(t_list **list_a, t_list **list_b)
{
    int size_a;
    
    size_a = ft_lstsize((*list_a));
    while (size_a > 5)
    {
        pb(list_b, list_a);
        size_a--;
    }
}