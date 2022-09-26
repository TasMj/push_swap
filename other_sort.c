/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 02:12:07 by tas               #+#    #+#             */
/*   Updated: 2022/09/26 17:26:37 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap a et b si a > b, sinon renvoie la liste de départ
void    sort_for_2(t_list **list)
{
    (*list) = (*list)->premier;
    if ((*list)->content > (*list)->next->content)
    {
        sa(list);
        write(1, "sa\n", 3);
    }
}

void    sort_for_3(t_list **list)
{
    t_list  *middle;
    t_list  *last;
    
    (*list) = (*list)->premier;
    middle = (*list)->next;
    last = (middle)->next;
    if ((*list)->premier->content > middle->content)
    {
        if ((*list)->premier->content < last->content)
        {
            sa(list);
            write(1, "sa\n", 3);
        }
        else if (middle->content > last->content)
        {
            sa(list);
            rra(list);
            write(1, "sa\nrra\n", 7);
        }
        else if (middle->content < last->content)
        {
            ra(list);
            write(1, "ra\n", 3);
        }
    }
    else if ((*list)->premier->content < middle->content)
    {
        if ((*list)->premier->content > last->content)
        {
            rra(list);
            write(1, "rra\n", 4);
        }
        else if (middle->content > last->content)
        {
            sa(list);
            ra(list);
            write(1, "sa\nra\n", 6);            
        }
    }
}

void    sort_for_5(t_list **list_a, t_list **list_b)
{
    t_list *trois;
    t_list *quatre;
    t_list *cinq;
    
    (*list_a) = (*list_a)->premier;
    pb(list_b, list_a);
    pb(list_b, list_a);
    write(1, "pb\npb\n", 6);
    sort_for_3(list_a);
    printf("\nLIST B :\n");
    ft_print(list_b);
    printf("\n");
    // printf("\nLIST A :\n");
    // ft_print(list_a);
    // printf("\n");
    (*list_a) = (*list_a)->premier;
    printf("prem %d\n", (*list_a)->premier->content);
    trois = (*list_a);
    quatre = (*list_a)->next;
    cinq = quatre->next;
    pa(list_b, list_a);
    write(1, "pa\n", 3);
    if ((*list_a)->content > cinq->content)
    {
        ra(list_a);
        write(1, "ra\n", 3);
    }
    else if ((*list_a)->content > quatre->content)
    {
        rra(list_a);
        sa(list_a);
        ra(list_a);
        ra(list_a);
        write(1, "rra\nsa\nra\nra\n", 13);
    }
    else if ((*list_a)->content > trois->content)
    {
        sa(list_a);
        write(1, "sa\n", 3);
    }
    pa(list_a, list_b);
    
}

void    *ft_print(t_list **list)
{
    while (*list)
    {
        printf("%d\n", (*list)->content);
        (*list) = (*list)->next;
    }
    return (list);
}

int main(int argc, char **argv)
{
    t_list  **list_a;
    t_list  **list_b;

    list_b = malloc(sizeof(t_list));
    list_a = attribution_arg(argc, argv);
    (*list_a) = (*list_a)->premier;
    sort_for_5(list_a, list_b);
    printf("\nAFTER SORT\n");
    ft_print(list_a);
    
}