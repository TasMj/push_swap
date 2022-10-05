/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_chainees.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:33:40 by tmejri            #+#    #+#             */
/*   Updated: 2022/10/05 16:45:31 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		new->next = *lst;
		*lst = new;
	}
}

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

// #include <stdio.h>
// int main(int argc, char **argv)
// {
//     t_list  **list;
	
//     list = attribution_arg(argc, argv);
// 	printf("**********retour au main*************\n");
// 	for (int i = 0; i < 3; i++)
// 	{
// 		printf("address: %p\n", (*list));
// 		printf("content: %d\n", (*list)->content);
// 		(*list) = (*list)->next;
// 	}
// 	(*list) = (*list)->premier;
// 	printf("aled %p\n", (*list)->premier);
// 	printf("content: %d\n", (*list)->content);

//     return (0);
// }