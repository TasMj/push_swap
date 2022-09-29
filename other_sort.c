/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 02:12:07 by tas               #+#    #+#             */
/*   Updated: 2022/09/29 14:40:17 by tmejri           ###   ########.fr       */
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

void    part_1_sort_5(t_list **list_a)
{
    t_list *trois;
    t_list *quatre;
    t_list *cinq;

    trois = (*list_a)->next;
    quatre = trois->next;
    cinq = quatre->next;
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
}

void    part_2_sort_5(t_list **list_a)
{
    t_list *deux;
    t_list *trois;
    t_list *quatre;
    t_list *cinq;
    
    deux = (*list_a)->next;
    trois = deux->next;
    quatre = trois->next;
    cinq = quatre->next;
    if (((*list_a)->content < trois->content) && ((*list_a)->content > deux->content))
    {
        sa(list_a);
        write(1, "sa\n", 3);
    }
    else if (((*list_a)->content < quatre->content) && ((*list_a)->content > trois->content))
    {
        sa(list_a);
        ra(list_a);
        sa(list_a);
        rra(list_a);
        write(1, "sa\nra\nsa\nrra\n", 13);
    }
    else if (((*list_a)->content < cinq->content) && ((*list_a)->content > quatre->content))
    {
        rra(list_a);
        sa(list_a);
        ra(list_a);
        ra(list_a);
        write(1, "rra\nsa\nra\nra\n", 13);
    }
    else if ((*list_a)->content > cinq->content)
    {
        ra(list_a);
        write(1, "ra\n", 3);
    }
}

void    sort_for_5(t_list **list_a, t_list **list_b)
{
    pb(list_b, list_a);
    pb(list_b, list_a);
    write(1, "pb\npb\n", 6);
    sort_for_3(list_a);
    pa(list_a, list_b);
    write(1, "pa\n", 3);
    part_1_sort_5(list_a);
    pa(list_a, list_b);
    write(1, "pa\n", 3);
    part_2_sort_5(list_a);
}
