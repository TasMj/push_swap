/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:21:44 by tmejri            #+#    #+#             */
/*   Updated: 2022/11/11 19:18:54 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* return 1 si on passe par en haut 2 si par en bas */
int side(t_list **list, int position, int size_one_block)
{
    int up;
    int down;
    
    up = du_haut(list, position, size_one_block);
    printf("\nup: %d\n", up);
    down = du_bas(list, size_one_block);
    printf("down: %d\n\n", down);
    if (up < down)
        return (1);
    else
        return (2);
}

/* recup l'elt par le haut de la liste */
void	from_top_to_b(t_list **list_a, t_list **list_b, int num_du_block, int size_one_block)
{
    while (*list_a)
    {
        if (is_in_block(list_a, num_du_block, size_one_block))
        {
            pb(list_b, list_a);
            break;
        }
        else
        {
            ra(list_a);
            break;
        }
    }
}

/* recup l'elt par le bas de la liste */
void	from_down_to_b(t_list **list_a, t_list **list_b, int num_du_block, int size_one_block)
{
    while (*list_a)
    {
        if (is_in_block(list_a, num_du_block, size_one_block))
        {
            pb(list_b, list_a);
            break;
        }
        else
            rra(list_a);
    }
}

void    sort_hundread(t_list **list_a, t_list **list_b, int block_size)
{
    int pos;
    int size_one_block;
    int save_size_block_beg;
    t_list  *tmp;

    pos = 1;
    size_one_block = size_block(list_a);
    save_size_block_beg = size_one_block; // regler pb du cas ou block pas plein
    tmp = *list_a;
    while (block_size > 1)  //faire pour 2 instead of 1 //ou pas
    {
        while (size_one_block > 0)
        {
            printf("size one block: %d\n", size_one_block);
            if (side(list_a, pos, save_size_block_beg) == 1)
            {
                printf("11111111111111111111111\n");
                from_top_to_b(list_a, list_b, pos, size_one_block);
            }
            else
            {
                printf("22222222222222222222222\n");
                from_down_to_b(list_a, list_b, pos, size_one_block);
            }
            printf("CA SORT\n");
            size_one_block--;
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
    printf("/////////////// LISTE A /////////////////\n\n");
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
