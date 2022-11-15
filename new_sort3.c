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
void	from_top_to_b(t_list **list_a, t_list **list_b, int b)
{
    while ((*list_a)->index != b)
        ra(list_a);
    if ((*list_a)->index == b)
        pb(list_b, list_a);
}

/* recup l'elt par le bas de la liste */
void	from_down_to_b(t_list **list_a, t_list **list_b, int a)
{
    while ((*list_a)->index != a)
        rra(list_a);
    if ((*list_a)->index == a)
        pb(list_b, list_a);
}

void    sort_hundread(t_list **list_a, t_list **list_b, int block_size)
{
    int     numero_du_block;
    int     size_one_block;
    int     save_size_block_beg;
    t_list  *tmp;
    int     a;
    int     b;
    
    numero_du_block = 1;
    size_one_block = size_block(list_a);
    save_size_block_beg = size_one_block;
    tmp = *list_a;
    while (block_size > 1)
    {
        while (size_one_block > 0)
        {
            if (side(list_a, numero_du_block, save_size_block_beg, &a, &b) == 1)
            {
                printf("11111111111111111111111\n");
                from_top_to_b(list_a, list_b, b);
            }
            else if (side(list_a, numero_du_block, save_size_block_beg, &a, &b) == 2)
            {
                printf("22222222222222222222222\n");
                from_down_to_b(list_a, list_b, a);
            }
            printf("A: %d\n", a);
            printf("B: %d\n", b);
            size_one_block--;
        }
        printf("***********************CHANGE BLOCK*************************\n");
        size_one_block = save_size_block_beg;
        numero_du_block++;
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
		// printf("[%d] -> %d\n", (*list_a)->content, (*list_a)->index);
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
