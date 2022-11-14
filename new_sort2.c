/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:21:44 by tmejri            #+#    #+#             */
/*   Updated: 2022/11/14 15:51:32 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* recup l'elt par le haut de la liste */
int	from_top_to_b(t_list **list_a, t_list **list_b, int num_du_block, int size_one_block)
{
    while (*list_a-index != a)
    {
        if (is_in_block(list_a, num_du_block, size_one_block))
        {
            pb(list_b, list_a);
            return (8);
        }
        else
        {
            ra(list_a);
            return (6);
        }
    }
    return (0);
}

/* recup l'elt par le bas de la liste */
int	from_down_to_b(t_list **list_a, t_list **list_b, int num_du_block, int size_one_block)
{
    while (*list_a)
    {
        if (is_in_block(list_a, num_du_block, size_one_block))
        {
            pb(list_b, list_a);
            return (8);
        }
        else
        {
            rra(list_a);
            return (6);
        }
    }
    return (0);
}

void    sort_hundread(t_list **list_a, t_list **list_b, int block_size)
{
    int     pos;
    int     size_one_block;
    int     save_size_block_beg;
    t_list  *tmp;
    int     c;
    int     a;
    
    pos = 1;
    size_one_block = size_block(list_a);
    save_size_block_beg = size_one_block; // regler pb du cas ou block pas plein
    tmp = *list_a;
    while (block_size > 1)  //faire pour 2 instead of 1 //ou pas
    {
        while (size_one_block > 0)
        {
            printf("size one block: %d\n", size_one_block);
            if (side(list_a, pos, save_size_block_beg, &a) == 1)
            {
                printf("11111111111111111111111\n");
                c = from_top_to_b(list_a, list_b, pos, size_one_block, a);
            }
            else if (side(list_a, pos, save_size_block_beg) == 2)
            {
                printf("22222222222222222222222\n");
                c = from_down_to_b(list_a, list_b, pos, size_one_block);
            }
            printf("THE C MGL: %d\n", c);

            if (c == 8)
            {
                size_one_block--;
            }
        }
        printf("*****CHANGE BLOCK*****\n");
        size_one_block = save_size_block_beg;
        pos++;
        block_size--;
        *list_a = tmp;
    }
}

int main(int argc, char **argv)
{
    t_list  **list_a;
    t_list  **list_b;
    int		*tab;
    int     block_size;

	list_a = attribution_arg(argc, argv, 2);
	list_b = malloc(sizeof(t_list));
	list_b[0] = NULL;
	tab = tab_to_sort(list_a);
	tab = tab_sorted(tab, list_a);
	index_tab(list_a, tab);
    if (ft_lstsize(*list_a) <= 100)
    {
        block_size = five_or_ten(list_a);
        sort_hundread(list_a, list_b, block_size);
        // stack_to_5(list_a, list_b);
        // sort_for_5(list_a, list_b);
        // sort_in_stack_a(list_a, list_b);
    }
    
    // else if (size_block(list_a) == 10)
    // {
    //     // sort_500();
    // }
    printf("/////////////// LISTE A /////////////////\n");
	while (*list_a)
	{
		printf("[%d]\n", (*list_a)->content);
		(*list_a) = (*list_a)->next;
	}
	printf("\n////////////// LISTE B //////////////////\n");
	while (*list_b)
	{
		printf("[%d]\n", (*list_b)->content);
		(*list_b) = (*list_b)->next;
	}
	printf("/////////////////////////////////////////\n");
}
