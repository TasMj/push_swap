    /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:06:24 by tmejri            #+#    #+#             */
/*   Updated: 2022/08/06 19:39:00 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

///////////////////////////////////////////////////////////
//                                                       //
//     A FAIRE POUR FINIR LE PRJET                       //
//                                                       //
//  X  1) finir mon bubble sort                          //
//     2) adapter mon radix avec les fonctions du sujet  //
//     3) adapter mon bubble avec les fonctions du sujet //
//     4) gerer les leaks                                //
//     5) voir si c'est assez opti                       //
//     6) fonction 25 lignes                             //
//     7) norminer                                       //
//                                                       //
///////////////////////////////////////////////////////////


// #include "push_swap.h"

// void    *ft_print(t_list **list)
// {
//     while (*list)
//     {
//         printf("content: %d\n", (*list)->content);
//         (*list) = (*list)->next;
//     }
//     return (list);
// }

// void    *ft_print_all(t_list **list)
// {
//     while (*list)
//     {
//         printf("content: %d\n", (*list)->content);
//         printf("ADD: %p\n", (*list));
//         printf("add_prem: %p\n", (*list)->premier);
//         printf("add_next: %p\n", (*list)->next);
//         printf("stockage: %d\n\n", (*list)->stockage);
//         (*list) = (*list)->next;
//     }
//     return (list);
// }

// t_list	**ft_bubble_sort(t_list **list_stack)
// {
// 	t_list	*tmp;
// 	int		size;
// 	int		comp_a;
// 	int		comp_b;
// 	int		div_a;
// 	int		div_b;

// 	size = ft_lstsize((*list_stack));
// 	tmp = (*list_stack)->next;
// 	while (size >= 0)
// 	{
// 		while ((*list_stack)->next != NULL)
// 		{
// 			div_a = (*list_stack)->content;
// 			div_b = tmp->content;
// 			printf("A: %d   B:%d\n",div_a, div_b);
// 			comp_a = unite(div_a);
// 			comp_b = unite(div_b);
// 			printf("div_a [%d]---> %d\n", div_a, comp_a);
// 			printf("div_b [%d]---> %d\n\n", div_b, comp_b);
// 			if (comp_a < comp_b)
// 				ft_swap((*list_stack), tmp);
// 			(*list_stack) = (*list_stack)->next;
// 			tmp = (*list_stack)->next;
// 		}
// 		printf("***TOUR***\n");
// 		(*list_stack) = (*list_stack)->premier;
// 		tmp = (*list_stack)->next;
// 		size--;
		
// 	}
// 	(*list_stack) = (*list_stack)->premier;
// 	return (list_stack);
// }

// void	ft_rev_int_tab(t_list **list_stack)
// {
// 	int	i;
// 	int size;
// 	int	cal;
// 	t_list	*tmp;

// 	tmp = (*list_stack)->next;
// 	size = ft_lstsize(list_stack);
// 	cal = size - 1;
// 	i = 0;
// 	while (i < (size / 2))
// 	{
// 		ft_swap((*list_stack), tmp);
// 		(*list_stack) = (*list_stack)->next;
// 		tmp = (*list_stack)->next;
// 		i++;
// 		cal--;
// 	}
// }

//MAIN PUSH


// int main(int argc, char **argv)
// {
//     t_list  **a;
//     t_list  **b;
  
//     b = malloc(sizeof(t_list));
//     t_list *tmp;
  
//     a = attribution_arg(argc, argv);
//     tmp = *a;
//     printf("*****stack A avant push*****\n");
//     a = ft_print(a);
//     printf("\n");
//     printf("*****Stack B avant push*****\n");
//     printf("\n");
//     b = ft_print(b);
//     printf("*****stack A apres push*****\n");
//     *a = tmp;
//     pa(b, a);
//     pa(b, a);
//     a = ft_print(a);
//     printf("\n");
//     printf("*****Stack B apres push*****\n");
//     b = ft_print(b);
//     return (0);
// }

// MAIN ROTATE

// int main(int argc, char **argv)
// {
//     t_list  **a;
//     t_list  *tmp;

//     a = attribution_arg(argc, argv);
//     tmp = *a;
//     printf("*****Stack A avant rotate*****\n\n");
//     a = ft_print(a);
//     printf("\n*****stack A apres rotate*****\n\n");
//     *a = tmp;
//     rb(a);
//     a = ft_print_all(a);
//     return (0);
// }


// MAIN RRR

// int main(int argc, char **argv)
// {
    // t_list  **a;
    // // t_list  *tmp;

    // a = attribution_arg(argc, argv);
    // tmp = *a;
    // printf("*****Stack A avant rotate*****\n\n");
    // a = ft_print(a);
    // printf("\n*****stack A apres rotate*****\n\n");
    // *a = tmp;
    // rrb(a);
    // a = ft_print(a);
    // return (0);
// }

// MAIN FT_SORT_IN_TAB

// int main(int argc, char **argv)
// {
// 	t_list	**list;

// 	list = attribution_arg(argc, argv);
	
// 	printf("\n******sorting process******\n\n");
// 	ft_sort_int_tab(list);

// 	printf("\n******after sort******\n\n");
// 	printf("STACK A\n");
// 	list = ft_print(list);
	
// }

// SORT FOR 5

// void    *ft_print(t_list **list)
// {
    // while (*list)
    // {
        // printf("%d\n", (*list)->content);
        // (*list) = (*list)->next;
    // }
    // return (list);
// }
// 
// int main(int argc, char **argv)
// {
    // t_list  **list_a;
    // t_list  **list_b;
// 
    // list_b = malloc(sizeof(t_list));
    // list_a = attribution_arg(argc, argv);
    // (*list_a) = (*list_a)->premier;
    // sort_for_5(list_a, list_b);
    // printf("\nAFTER SORT\n");
    // ft_print(list_a);
// }

// FIND BIGGEST
// 
// int main (int argc, char **argv)
// {
    // t_list  **list;
// 
    // list = attribution_arg(argc, argv);
    // printf("////%d////\n", find_biggest(list));
// }


// BUBBLE

// void	ft_bubble_sort(t_list **list_stack)
// {
	// t_list	*tmp;
	// int		size;
// 
	// (*list_stack) = (*list_stack)->premier;
	// tmp = (*list_stack)->next;
	// size = ft_lstsize((*list_stack));
	// while (size > 1)
	// {
		// while ((*list_stack)->next != NULL)
		// {
			// if ((*list_stack)->content > tmp->content)
			// {
				// sa(list_stack);
				// write(1, "sa\n", 3);
			// }
			// ra(list_stack);
			// write(1, "ra\n", 3);
			// (*list_stack) = (*list_stack)->next;
			// tmp = (*list_stack)->next;
		// }
		// (*list_stack) = (*list_stack)->premier;
		// tmp = (*list_stack)->next;
		// size--;
	// }
	// ra(list_stack);
	// write(1, "ra\n", 3);
	// (*list_stack) = (*list_stack)->premier;
	// return (list_stack);
// }
// 






// size = 16
// size mem = 16
// 
// 
// 
// 
// 
// 
// 
// 











