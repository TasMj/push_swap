/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_hundread.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:20:18 by tmejri            #+#    #+#             */
/*   Updated: 2022/10/03 18:16:28 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// //trouver le nb le plus long de la liste pour savoir cb de fois on va diviser
// // faire attention au signe moins
// int find_biggest(t_list **list)
// {
//     int c;
//     int stockage;
    
//     while ((*list)->next != NULL)
//     {
//         if ((*list)->content > (*list)->next->content)
//             stockage = (*list)->content;
//         else
//             stockage = (*list)->next->content;
//         (*list) = (*list)->next;
//     }
//     c = size_nb(stockage);
//     return (c);
// }

void    *tab_to_sort(t_list **list)
{
    int     size;
    int    *tab_int;
    int i;
    
    i = 0;
    size = ft_lstsize(*list);
    if (size % 2 != 0)
        size = size + 1;
    tab_int = (int *)malloc(sizeof(int) * size);
    while (*list)
    {
        tab_int[i] = (*list)->content;
        (*list) = (*list)->next;
        i++;
    }
    return (tab_int);
}

int	count_elt_tab(int *tab)
{
	int i = 0;

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
	
	i = 0;
	size = count_elt_tab(tab);
	while (*list)
	{
		printf("ttttttttttt");
		while (size > 1)
		{
			printf("ttttttttttt");
			if ((*list)->content == tab[i])
				(*list)->index = i;
			i++;
			size--;
		}
		(*list) = (*list)->next;
		i = 0;
	}
}

// Calculer la mediane
// dans un premier temps compter le nb de nombre si paire -> mediane nb / 2 si impaire (nb + 1/2)
// int calcul_mediane(t_list **list)
// {
//     char    *tab_int;
    
//     tab_int = tab_to_sort(list);
// }

int main(int argc, char **argv)
{
    t_list  **list;
    int    *tab;
	// int i;
// 
    // i = 0;
    list = attribution_arg(argc,argv);
    tab = tab_to_sort(list);
	tab = tab_sorted(tab);
	index_tab(list, tab);
	
	// while (*list)
	// {
		// printf("bdshfsldhafha");
		// printf("[%d]  -->  %d\n", (*list)->content, (*list)->index);
		// printf("[%d]\n", (*list)->content);
		// (*list) = (*list)->next;
	// }
}