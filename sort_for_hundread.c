/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_hundread.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:20:18 by tmejri            #+#    #+#             */
/*   Updated: 2022/10/05 16:39:54 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void    *tab_to_sort(t_list **list)
{
    int     size;
    int		*tab_int;
	t_list	*temp;
    int 	i;
    
    i = 0;
    size = ft_lstsize(*list);
    tab_int = (int *)malloc(sizeof(int) * size);
	temp = *list;
    while (*list)
    {
        tab_int[i] = (*list)->content;
        (*list) = (*list)->next;
        i++;
    }
	*list = temp;
    return (tab_int);
}

int	count_elt_tab(int *tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	*tab_sorted(int	*tab)
{
	int	i;
	int	size;
	int	tmp;

	i = 1;
	size = count_elt_tab(tab);
	while (size > 1)
	{
		while (tab[i])
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

void	index_tab(t_list **list, int *tab)
{
	int	i;
	int	size;
	int size_mem;
	t_list	*temp;
	
	i = 0;
	size = ft_lstsize(*list);
	size_mem = size;
	temp = *list;
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
	*list = temp;	
}

void    ft_print(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	if (!tmp)
		return;
    while (tmp)
    {
        printf("content: %d  \n", tmp->content);
        // printf("index: %d\n", (*tmp)->index);
        tmp = tmp->next;
    }
}

// Calculer la mediane
// dans un premier temps compter le nb de nombre si paire -> mediane nb / 2 si impaire (nb + 1/2)
void seperate_by_mediane(t_list **list, t_list **list_b)
{
	t_list	*tmp_a;
	int		size;
	int		mediane;

	tmp_a = *list;
	size = ft_lstsize(*list);
	list_b = malloc(sizeof(t_list));
	if (!(size % 2 == 0))
		size = size + 1;
	mediane = size / 2;
	while (size)
	{
		if (tmp_a->index < mediane)
		{
			pb(list_b, list);
			write(1, "pb\n", 3);
		}
		else
		{
			ra(list);
			write(1, "ra\n", 3);
		}
		size--;
		tmp_a = tmp_a->next;
	}
}

int main(int argc, char **argv)
{
    t_list  **list;
    t_list  **list_b;
    int    *tab;

    list = attribution_arg(argc,argv);
    tab = tab_to_sort(list);
	tab = tab_sorted(tab);
	list_b = NULL;
	
	index_tab(list, tab);
	// ft_print(list);
	printf("STACK A BEFORE SORT\n");
	ft_print(list);
	seperate_by_mediane(list, list_b);
	printf("STACK A\n");
	ft_print(list);
	printf("STACK B\n");
	ft_print(list_b);
	
}