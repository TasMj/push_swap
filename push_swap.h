/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:50:01 by tmejri            #+#    #+#             */
/*   Updated: 2022/11/28 20:36:42 by tmejri           ###   ########.fr       */
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

typedef struct s_elt
{
	int	num_block;
	int	size_one_block;
	int	save_size_beg;
}	t_elt;

typedef struct s_info
{
	int	size_a;
	int	max_a;
	int	min_a;
}	t_info;

typedef struct s_list
{
	struct s_list	*premier;
	int				content;
	int				index;
	struct s_list	*next;
}		t_list;

typedef struct s_full_list
{
	t_list	*tmp;
	t_list	*last_top;
	t_list	*last_elt;
	t_list	*midd;
	int		max_full_list;
	int		middle;
	int		size;
}	t_full_list;

// BIG SORT TOOLS
void		*tab_to_sort(t_list **list);
void		*tab_sorted(int	*tab, t_list **list);
void		search_and_affect(t_list **list, int *size, int *tab, int *i);
void		index_tab(t_list **list, int *tab);
void		stack_to_5(t_list **list_a, t_list **list_b);

// BIG SORT
int			five_or_ten(t_list **list_a);
int			size_block(t_list **list_a);
int			side(t_list **list, t_elt elt, int *a, int *b);
int			block(t_elt elt);
int			is_in_block(t_list *list, t_elt elt);

// BIG SORT 2
int			du_haut(t_list **list, t_elt elt, int *b);
void		ft_end(t_list **list, int size_list);
int			du_bas(t_list **list, t_elt elt, int *a);

// BIG SORT 3
void		from_top_to_b(t_list **list_a, t_list **list_b, int b);
void		from_down_to_b(t_list **list_a, t_list **list_b, int a);
void		big_sort(t_list **list_a, t_list **list_b, int block_size);
void		diminuer(t_list **list_a, t_list **list_b);
void		sort_all_other(t_list **list_a, t_list **list_b);

// BIG SORT 4
int			middle_size(t_list **list_a);
t_list		*last_elt(t_list **list, int size_list);
t_list		*index_middle(t_list **list_a, int middle);
int			biggest(t_list	**list_a);
int			smallest(t_list	**list_a);

// BIG SORT 5
void		move_from_top(t_list **list_a, t_list **list_b, int c);
void		move_from_down(t_list **list_a, t_list **list_b, int c);
int			from_top(t_list **list_a, t_list **list_b);
int			down_even_odd(int keep_middle, int size_a, int c);
int			from_down(t_list **list_a, t_list **list_b);
void		sort_in_stack_a(t_list **list_a, t_list **list_b);
int			annex_down(t_list **l_a, t_list **l_b, t_full_list f_l, int keep_m);

// PUSH
void		pa(t_list **list_stack_a, t_list **list_stack_b);
void		pb(t_list **list_stack_b, t_list **list_stack_a);

// REVERSE ROTATE
void		rra(t_list **list_stack_a);
void		rrb(t_list **list_stack_b);
void		rrr(t_list **list_stack_a, t_list **list_stack_b);

// ROTATE
void		ra(t_list **list_stack_a);
void		rb(t_list **list_stack_b);
void		rr(t_list **list_stack_a, t_list **list_stack_b);

// SWAP
void		sa(t_list **list_stack_a);
void		sb(t_list **list_stack_b);
void		ss(t_list **list_a, t_list **list_b);

// FONCTIONS UTILES
long int	ft_atoi(char *nptr);
int			ft_strlen(char *str);
int			size_nb(int nb);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_resize(char *src, int start);

// SPLIT
size_t		nb_word(char *s, char c);
char		*ft_copy(char *dest, char *s, char c);
char		**ft_split(char *s, char c);

// GESTION LISTES
void		complete_list(t_list **list_a, t_list *start, int nb, char **stock);
t_list		**decomposer_arg(int argc, char **argv, int i);
t_list		**attribution_arg(int argc, char **argv, int i);

// INITIALISATION
char		*creat_list(char *str);
int			for_check_intru(char *list, int i);
int			check_intru(int argc, char *argv[]);
int			for_check_1(char **stockage, char **argv, int argc);
int			for_check_2(char **argv, int argc);
int			check_int(int argc, char **argv);
int			check_doublon(t_list **list);
int			check_signe_moins(char *str);

// FONCTIONS LISTES CHAINEES
t_list		*ft_lstnew(int content);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
int			ft_lstsize(t_list *lst);

// SORT 2, 3, 4 et 5
void		sort_for_2(t_list **list);
void		sort_for_3(t_list **list);
void		position_1(t_list **list_a);
void		position_2(t_list **list_a);
void		part_1_sort_5(t_list **list_a);
void		part_2_sort_5(t_list **list_a);
void		sort_for_4(t_list **list_a, t_list **list_b);
void		sort_for_5(t_list **list_a, t_list **list_b);

// MAIN FONCTION
void		free_list(t_list **list);
int			error_free_ret(t_list **list);
void		direct_sort(int size_list, t_list **list_a, t_list **list_b);
void		free_2_lists(t_list **list_a, t_list **list_b);
int			free_if_wrong(t_list **list_a, t_list **list_b, int size_list);

// RANK TOP
void		go(t_list **list_a, int *middle, int *c);
int			fst_pos(t_list **list_a, t_list **list_b, int middle, t_info info);
int			mid_pos(t_list **list_a, t_list **list_b, int middle, t_info info);
int			other_p(t_list **list_a, t_list **list_b, int middle, t_info info);
int			find_rank_top(t_list **list_a, t_list **list_b, int middle);

// AUTRE
int			find_down(t_list **list_a, t_list **list_b, t_full_list full_list);
int			find_start_top(t_list **list);
int			find_start_down(t_list **list);
void		order(t_list **list);

#endif