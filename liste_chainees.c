/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_chainees.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:33:40 by tmejri            #+#    #+#             */
/*   Updated: 2022/10/18 17:16:01 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* creer un nouveu maillon de la liste
lui affect le content demande */
t_list	*ft_lstnew(int content)
{
	t_list	*ma_liste;

	ma_liste = malloc(sizeof(t_list));
	if (!ma_liste)
		return (NULL);
	ma_liste->content = content;
	ma_liste->next = NULL;
	return (ma_liste);
}

/* ajoute un nouvel elt a la fin de la liste */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*dernier;

	if (lst)
	{
		if (*lst)
		{
			dernier = ft_lstlast(*lst);
			dernier->next = new;
		}
		else
			*lst = new;
	}
}

/* ajoute un nouvel elt au debut de la liste */
		// (*lst)->premier = new;
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		new->next = *lst;
		*lst = new;
	}
}

/* return le dernier elt de la liste */
t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

/* return la taille de la liste (cb d'elts) */
int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;

	tmp = lst;
	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	lst = tmp;
	return (i);
}
