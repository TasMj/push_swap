/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:50:01 by tmejri            #+#    #+#             */
/*   Updated: 2022/11/16 18:47:10 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_list
{
	struct s_list	*premier;
	int				content;
	int				index;
	struct s_list	*next;
}		t_list;

// INITIALISATION
char	*creat_list(char *str);
int		check_intru(int argc, char *argv[]);
int		for_check_1(char **stockage, char **argv, int argc);
int		for_check_2(char **argv, int argc);
int		check_int(int argc, char **argv);
int		check_doublon(t_list **list);
int		check_signe_moins(char *str);

// SPLIT
size_t		nb_word(char *s, char c);
char		*ft_copy(char *dest, char *s, char c);
char		**ft_split(char *s, char c);

// FONCTIONS UTILES
long int	ft_atoi(char *nptr);
int			ft_strlen(char *str);
int			size_nb(int nb);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_resize(char *src, int start);

// GESTION LISTES
t_list		**decomposer_arg(int argc, char **argv, int i);
t_list		**attribution_arg(int argc, char **argv, int i);

// FONCTIONS LISTES CHAINEES
t_list		*ft_lstnew(int content);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
int			ft_lstsize(t_list *lst);

// SWAP
void		ft_swap(t_list *first, t_list *second);
void    	*sa(t_list **list_stack_a);
void    	*sb(t_list **list_stack_b);
void    	ss(t_list **list_stack_a, t_list **list_stack_b);

// PUSH
void    	pa(t_list **list_stack_a, t_list **list_stack_b);
void	   	pb(t_list **list_stack_b, t_list **list_stack_a);

// ROTATE
void		ra(t_list **list_stack_a);
void		rb(t_list **list_stack_b);
void	    rr(t_list **list_stack_a, t_list **list_stack_b);

// REVERSE ROTATE
void		rra(t_list **list_stack_a);
void		rrb(t_list **list_stack_b);
void	    rrr(t_list **list_stack_a, t_list **list_stack_b);

// AFFICHAGE
void    	*ft_print_all(t_list **list); //a suppr
void    	ft_print(t_list **list); //a suppr

// SORT 2, 3, 4 et 5
void	sort_for_2(t_list **list);
void	sort_for_3(t_list **list);
void	position_1(t_list **list_a);
void	position_2(t_list **list_a);
void    part_1_sort_5(t_list **list_a);
void	part_2_sort_5(t_list **list_a);
void    sort_for_4(t_list **list_a, t_list **list_b);
void    sort_for_5(t_list **list_a, t_list **list_b);

// SORT FOR HUNDREAD
void    *tab_to_sort(t_list **list);
void	*tab_sorted(int	*tab, t_list **list);
void	search_and_affect(t_list **list, int *size, int *tab, int *i);
void	index_tab(t_list **list, int *tab);
t_list	**seperate_by_mediane(t_list **list, t_list **list_b);
void    stack_to_5(t_list **list_a, t_list **list_b);
int		find_mediane_index(t_list **list);
int		up_or_down(t_list **list_a, t_list **list_b);
int    from_top(t_list **list_a, t_list **list_b);
int    from_down(t_list **list_a, t_list **list_b);
int		empty_list(t_list **list);
void    sort_in_stack_a(t_list **list_a, t_list **list_b);
void	sort_for_hundread(t_list **list_a, t_list **list_b, int size_list_a);

// MAIN FONCTION
int		error_free_ret(t_list* list);
void	direct_sort(int size_list, t_list **list_a, t_list **list_b);

// BUBBLE
void	bubble_sort(t_list **list_a, t_list **list_b);

// NEW SORT
int		size_block(t_list **list_a);
int 	block(int nb_of_block, int size_one_block);
int 	is_in_block(t_list *list, int nb_of_block, int size_one_block);
int 	du_haut(t_list **list, int position, int size_one_block, int *a);
void	ft_end(t_list **list, int position);
int 	du_bas(t_list **list, int numero_du_block, int size_one_block, int *a);
int 	side(t_list **list, int position, int size_one_block, int *a, int *b);
void	from_top_to_b(t_list **list_a, t_list **list_b, int a);
void	from_down_to_b(t_list **list_a, t_list **list_b, int a);
void    big_sort(t_list **list_a, t_list **list_b, int block_size);
int 	five_or_ten(t_list **list_a);
void sort_all_other(t_list **list_a, t_list **list_b);
void print_list(t_list **list_a, t_list **list_b);

#endif