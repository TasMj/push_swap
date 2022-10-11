/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_hundread_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:41:27 by tmejri            #+#    #+#             */
/*   Updated: 2022/10/11 16:54:33 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* trouve la mediane dans la stack actuelle et return l'index de la mediane */
int find_mediane_index(t_list **list)
{
    int size;
    int pos_mediane;
    int stock_index;
    t_list *tmp;

    stock_index = 0;
    tmp = *(list);
    size = ft_lstsize(*list);
    pos_mediane = size / 2;
    (*list) = (*list)->premier;
    while (pos_mediane)
    {
        (*list) = (*list)->next;
        pos_mediane--;
    }
    stock_index = (*list)->index;
    (*list) = tmp;
    return (stock_index);
}

/* bool qui renvoie 1 si l'index de l'elt fait partie de la premiere 
partie de la stack A en fonction de la mediane, 2 sinon */
int up_or_down(t_list **list_a, t_list **list_b)
{
    int mediane;

    mediane = find_mediane_index(list_a);
    if ((*list_b)->index < mediane)
        return (1);
    else
        return (2);
}

/* trie dans le cas ou l'index de b est > l'index du premier elt de a */
void    from_top(t_list **list_a, t_list **list_b)
{
    int t_index;
    int stock_index;
    t_list *tmp;
    
    tmp = *list_a;
    t_index = 0;
    stock_index = 0;
    while ((*list_b)->index > (*list_a)->index)
    {
        (*list_a) = (*list_a)->next;
        stock_index++;
    }
    *list_a = tmp;
    t_index = stock_index;
    while (stock_index > 0)
    {
        ra(list_a);
        stock_index--;
    }
    pa(list_a, list_b);
    while (t_index > 0)
    {
        rra(list_a);
        t_index--;
    }
}

/* trie dans le cas ou l'index de b est < l'index du dernier elt de a */
void    from_down(t_list **list_a, t_list **list_b)
{
    int t_index;
    int stock_index;
    t_list *tmp;
    
    tmp = *list_a;
    t_index = 0;
    stock_index = 1;
    while ((*list_b)->index < (*list_a)->index)
    {
        rra(list_a);
        stock_index++;
    }
    ra(list_a);
    *list_a = tmp;
    t_index = stock_index;
    pa(list_a, list_b);
    while (t_index > 0)
    {
        ra(list_a);
        t_index--;
    }
}


/* verifie qu'une liste n'est pas vide */
int empty_list(t_list **list)
{
    if ((*list) != NULL)
        return (1);
    else
        return (0);
}


/* EN FONCTION DE LA TAILLE DE LA STACK A
si ce bool renvoie 1 : si
                    1) x < prem elt de la stack a --> pa
                    2) x > on cherche entre quel nb et quel nb il est compris et on 
                             ra x la position ou il doit se trouver
                             sa
                             rra x meme nb qu au dessus
si ce bool renvoie 2 : 
                    1) x > dernier 
                    2) x < on cherche entre quel nb et quel nb il est compris et on 
                             rra x la position ou il doit se trouver
                             pa
                             ra x meme nb qu au dessus */
void    sort_in_stack_a(t_list **list_a, t_list **list_b)
{
    while (*list_b)
    {
        if (up_or_down(list_a, list_b) == 1)
        {
            if ((*list_b)->index < (*list_a)->index)
                pa(list_a, list_b);
            else
                from_top(list_a, list_b);
        }
        else if (up_or_down(list_a, list_b) == 2)
        {
            rra(list_a);
            if ((*list_b)->index > (*list_a)->index)
            {
                ra(list_a);
                pa(list_a, list_b);
                ra(list_a);
            }
            else
                from_down(list_a, list_b);
        }
    }
}


void sort_for_hundread(t_list **list_a, int argc)
{
    t_list **list_b;
    int    *tab;

    tab = tab_to_sort(list_a);
	tab = tab_sorted(tab, argc);
	list_b = NULL;
	index_tab(list_a, tab);
	list_b = seperate_by_mediane(list_a, list_b);
    stack_to_5(list_a, list_b);
    sort_for_5(list_a, list_b);
    sort_in_stack_a(list_a, list_b);
    printf("\n\nSTACK A\n\n");
    ft_print(list_a);
    printf("\n\nSTACK B\n\n");
    ft_print(list_b);
}

int main(int argc, char **argv)
{
    t_list **list_a;

    list_a = attribution_arg(argc, argv);
    sort_for_hundread(list_a, argc);
}
