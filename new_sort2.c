/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:21:44 by tmejri            #+#    #+#             */
/*   Updated: 2022/10/26 15:32:50 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* return 1 si on passe par en haut 2 si par en bas */
int side(t_list **list, int position)
{
    int up;
    int down;
    
    up = du_haut(list, position);
    down = du_bas(list, position);
    if (up < down)
        return (1);
    else
        return (2);
}

/* recup l'elt par le haut de la liste */
void	from_top_to_b(t_list **list_a, t_list **list_b, int num_du_block)
{
    while (*list_a)
    {
        if (is_in_block(list_a, num_du_block))
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
void	from_down_to_b(t_list **list_a, t_list **list_b, int num_du_block)
{
    while (*list_a)
    {
        if (is_in_block(list_a, num_du_block))
        {
            pb(list_b, list_a);
            break;
        }
        else
        {
            rra(list_a);
            break;
        }
    }
}

void    sort_hundread(t_list **list_a, t_list **list_b, int block_size)
{
    int num_du_block;
    int pos;
    int size_one_block;
    t_list  *tmp;

    pos = 1;
    size_one_block = 20;
    tmp = *list_a;
    while (block_size > 1)
    {
        while (size_one_block > 0)
        {
            printf("****************************\n\n");
            num_du_block = block(pos);
            printf("num du block: %d\n", side(list_a, pos));
            if (side(list_a, pos) == 1)
            {

                from_top_to_b(list_a, list_b, num_du_block);
            }
            else if (side(list_a, num_du_block) == 2)
                from_down_to_b(list_a, list_b, num_du_block);
            size_one_block--;
        }
        size_one_block = 20;
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
        block_size = size_block(list_a); 
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
