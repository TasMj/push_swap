/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_chainees2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:10:35 by tmejri            #+#    #+#             */
/*   Updated: 2022/08/05 17:08:55 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_lstclear(t_list **lst, void (*del)(void*))
// {
// 	t_list	*tmp;

// 	if (lst && del)
// 	{
// 		while (lst && *lst)
// 		{
// 			tmp = (*lst)->next;
// 			ft_lstdelone(*lst, del);
// 			*lst = tmp;
// 		}
// 	}
// }


// void	ft_lstdelone(t_list *lst, void (*del)(int*))
// {
	// if (lst && del)
	// {
		// (*del)(lst->content);
		// free(lst);
	// }
// }


// void	ft_lstiter(t_list *lst, void (*f)(void *))
// {
// 	if (lst && f)
// 	{
// 		while (lst)
// 		{
// 			f(lst->content);
// 			lst = lst->next;
// 		}
// 	}
// }


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
