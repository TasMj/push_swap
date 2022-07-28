/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_chainees2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:10:35 by tmejri            #+#    #+#             */
/*   Updated: 2022/07/28 14:32:29 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*new_list;
// 	t_list	*the_list;

// 	the_list = 0;
// 	while (lst)
// 	{
// 		new_list = ft_lstnew((*f)(lst->content));
// 		if (!new_list)
// 		{
// 			while (the_list)
// 			{
// 				new_list = the_list->next;
// 				(*del)(the_list->content);
// 				free(the_list);
// 				the_list = new_list;
// 			}
// 			lst = NULL;
// 			return (NULL);
// 		}
// 		ft_lstadd_back(&the_list, new_list);
// 		lst = lst->next;
// 	}
// 	return (the_list);
// }

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

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// void del_lst(t_list *list)
// {
// 	void	*a_supprimer;
//     // if (!list)
//     //     return (NULL);

//     if (list->content != NULL)
//     {
//         a_supprimer = list->content;
//         list->content = list->next;
//         free(a_supprimer);
//     }
// }
