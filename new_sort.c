/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:09:56 by tmejri            #+#    #+#             */
/*   Updated: 2022/10/26 12:54:31 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// voir si une fonction pour 100 et 500 ou 2 fonxtions diff



void	search_and_affect(t_list **list, int *size, int *tab, int *i);
void	*tab_to_sort(t_list **list);
void	*tab_sorted(int	*tab, t_list **list);
void	index_tab(t_list **list, int *tab);
void	stack_to_5(t_list **list_a, t_list **list_b);

// 1) en fonction du nb d'elt separer en plusieurs parties
int	size_block(t_list **list_a)
{
    int	size_list;
	
    size_list = ft_lstsize(*list_a);
    if (size_list <= 100)
		return (size_list / 5);
    else
		return (size_list / 10);
}

// bool si l'indice est compris ds le block
int is_in_block(t_list **list, int *tab)
{
    
}

/* return la position d'en haut du premier elt du block rencontre */
int du_haut(t_list **list, int *tab)
{
    int c;

    c = 0;
    while (*list)
    {
        if (is_in_bock(list, tab))
            return (c);
        else
            c++;
    }
    return (0);
}

int *ft_end(t_list **list, int position)
{
	while (*list && position)
	{
		(*list) = (*list)->next;
        position--;
	}
	return ((*list)->index);
}

/* return la position d'en bas du premier elt du block rencontre */
int du_bas(t_list **list, int *tab, int position)
{
    int     c;
    int     index_last;
    t_list  *tmp;

    c = 0;
    tmp = *list;
    while (*list)
    {
        index_last = ft_end(list, position); 
        if (is_in_block(index_last))
            return (c);
        else
        {
            c++;
            position--;
            (*list) = tmp;
        }
    }
    return (0);
}


int main(int argc, char **argv)
{
    t_list  **list_a;
   	int		size_list;
    int		*tab;

	list_a = attribution_arg(argc, argv, 2);
	size_list = ft_lstsize(*list_a);
	tab = tab_to_sort(list_a);
	tab = tab_sorted(tab, list_a);
	index_tab(list_a, tab);
    
}





// //* Creation d'un block */
// void	creat_block(t_list **list_a, t_list **list_b, int *tab, int size_of_block)
// {
// 	int	i;
// 	int	c;

// 	i = 0;
// 	c = 0;
// 	size_of_block = size_block(list_a);
//     tab = tab_to_sort(list_a); //A RETIRER
//     tab = tab_sorted(tab, list_a); //A RETIRER
// 	index_tab(list_a, tab); //A RETIRER
// 	while(size_of_block)
// 	{
// 		while (*list_a)
// 		{
// 			while (tab[i])
// 			{
// 				if ((*list_a)->index == i)
//                     c++;
//                 else
//                     i++;
// 			}
//             i = 0;
// 		}
// 	    size_of_block--;
// 	}
//     *list_a = tmp;
// }

// // fonction qui cherche en haut et en bas ou est le plus proche elt du groupe
// // voir comment conserver le block




// int main(int argc, char **argv)
// {
//     t_list  **list_a;
//     t_list  **list_b;
//    	int		size_list;
//     int		*tab;

// 	list_a = attribution_arg(argc, argv, 2);
// 	list_b = malloc(sizeof(t_list));
// 	list_b[0] = NULL;
// 	size_list = ft_lstsize(*list_a);

// 	tab = tab_to_sort(list_a);
// 	tab = tab_sorted(tab, list_a);
// 	index_tab(list_a, tab);
//     if (size_block(list_a) == 5)
//     {
//         // sort_100();
//     }
//     else if (size_block(list_a) == 10)
//     {
//         // sort_500();
//     }
    
    
// }
