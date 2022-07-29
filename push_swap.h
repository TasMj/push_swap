/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:50:01 by tmejri            #+#    #+#             */
/*   Updated: 2022/07/29 14:40:47 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_list
{
	int			content;
	struct s_list	*next;
}		t_list;

t_list		*ft_lstnew(int content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void		del_lst(t_list *list);
long int	ft_atoi(char *nptr);
char		*ft_strjoin(char *s1, char *s2);
int			check_intru(int argc, char *argv[]);
// static size_t	nb_word(const char *s, char c);
// static char	*ft_copy(char *dest, char const *s, char c);
char		**ft_split(char *s, char c);
char		*creat_list(char *str);
int			check_intru(int argc, char *argv[]);
int			check_int(int argc, char **argv);
int			size_nb(int nb);
char		*ft_resize(char *src, int start);
int			ft_strlen(char *str);
void    	*decomposer_arg(int argc, char **argv);
void    	*attribution_arg(int argc, char *argv[]);
void  		swap(t_list *list);
void    	*sa(t_list *list_stack_a);

#endif