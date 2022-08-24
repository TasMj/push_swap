/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:50:01 by tmejri            #+#    #+#             */
/*   Updated: 2022/08/23 17:58:39 by tas              ###   ########.fr       */
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
	int				stockage;
	struct s_list	*next;
}		t_list;

// INITIALISATION
char	*creat_list(char *str);
int		check_intru(int argc, char *argv[]);
int		check_int(int argc, char **argv);
int		check_doublon(t_list **list);
int		check_signe_moins(char *str);

// SPLIT
size_t	nb_word(char *s, char c);
// char		*ft_copy(char *dest, char const *s, char c);
char		**ft_split(char *s, char c);

// FONCTIONS UTILES
long int	ft_atoi(char *nptr);
int			ft_strlen(char *str);
int			size_nb(int nb);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_resize(char *src, int start);

// GESTION LISTES
t_list		**decomposer_arg(int argc, char **argv);
t_list		**attribution_arg(int argc, char **argv);

// FONCTIONS LISTES CHAINEES
t_list		*ft_lstnew(int content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);

// SWAP
void		ft_swap(t_list *first, t_list *second);
void    	*sa(t_list **list_stack_a);
void    	*sb(t_list **list_stack_b);
void    	ss(t_list **list_stack_a, t_list **list_stack_b);

// PUSH
void    	pa(t_list **list_stack_a, t_list **list_stack_b);
void   		pb(t_list **list_stack_b, t_list **list_stack_a);

// ROTATE
t_list    	**ra(t_list **list_stack_a);
t_list    	**rb(t_list **list_stack_b);
void	    rr(t_list **list_stack_a, t_list **list_stack_b);

// REVERSE ROTATE
t_list    	**rra(t_list **list_stack_a);
t_list    	**rrb(t_list **list_stack_b);
void	    rrr(t_list **list_stack_a, t_list **list_stack_b);

// AFFICHAGE
void    	*ft_print_all(t_list **list);
void    	*ft_print(t_list **list);

// BUBBLE SORT
t_list	**ft_bubble_sort(t_list **list_stack);

// RADIX SORT
int		unite(int a);
int		ordre_croissant(t_list **list_stack);
t_list	**divise_content(t_list **list);
void	stockage_unite(t_list **list);
void	compare_unite(t_list **list_stack);
t_list	**ft_pre_radix(t_list **list_stack);
t_list	**ft_radix(t_list **list_stack);

// SORT 2, 3 et 5
t_list  **sort_for_2(t_list **list);

#endif