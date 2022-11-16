/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:34:16 by tmejri            #+#    #+#             */
/*   Updated: 2022/11/16 18:45:52 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void move_from_top(t_list **list_a, t_list **list_b, int c)
{
    int keep_c;

    keep_c = c;
    while (c > 0)
    {
        ra(list_a);
        c--;
    }
    pa(list_a, list_b);
    while (keep_c > 0)
    {
        rra(list_a);
        keep_c--;
    }
}

void move_from_down(t_list **list_a, t_list **list_b, int c)
{
    int keep_c;

    keep_c = c;
    if (c == 0)
    {
        pa(list_a, list_b);
        ra(list_a);
    }
    else
    {
        while (c > 0)
        {
            rra(list_a);
            c--;
        }
        pa(list_a, list_b);
        while (keep_c > 0)
        {
            ra(list_a);
            keep_c--;
        }
    }
}

int from_top(t_list **list_a, t_list **list_b)
{
    int size_a;
    int middle;
    int keep_middle;
    int c;
    t_list  *tmp;
    int r = 0;

    tmp = *list_a;
    c = 0;
    size_a = ft_lstsize(*list_a);
    if (size_a % 2 == 0)
        middle = (size_a / 2);
    else
        middle = (size_a / 2) + 1;
    keep_middle = middle;
    while (middle > 0)
    {
        if ((*list_b)->index > (*list_a)->index)
        {
            (*list_a) = (*list_a)->next;
            c++;
        }
        middle--;
    }
    if (c == keep_middle && ((*list_b)->index > (*list_a)->index))
        r = -1;
    else
        r = c;
    *list_a = tmp;
    return (r);
}

int from_down(t_list **list_a, t_list **list_b)
{
    int size_a;
    int middle;
    int keep_middle;
    int c;
    t_list  *tmp;
    int r = 0;

    c = 0;
    tmp = *list_a;
    size_a = ft_lstsize(*list_a);
    if (size_a % 2 == 0)
        middle = (size_a / 2);
    else
        middle = (size_a / 2) + 1;
    keep_middle = middle;
    while (middle > 0)
    {
        (*list_a) = (*list_a)->next;
        middle--;
    }
    middle = keep_middle;
    while ((*list_a) && middle > 0)
    {
        if ((*list_b)->index > (*list_a)->index)
        {
            (*list_a) = (*list_a)->next;
            c++;
        }
        middle--;
    }
    if (c == keep_middle && ((*list_b)->index > (*list_a)->index))
        r = 0;
    else
        r = keep_middle - c - 1;
    *list_a = tmp;
    return (r);
}

void    sort_in_stack_a(t_list **list_a, t_list **list_b)
{
    int final_size;
    int top;
    int down;
    
    final_size = ft_lstsize(*list_a) + ft_lstsize(*list_b);
    while (ft_lstsize(*list_a) != final_size)
    {
        top = from_top(list_a, list_b);
        down = from_down(list_a, list_b);
        if (down == 0 || down < top || top == -1)
            move_from_down(list_a, list_b, down);
        if (top <= down || down == -1)
            move_from_top(list_a, list_b, top);
    }
}
