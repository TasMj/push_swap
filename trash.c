/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:42:37 by tmejri            #+#    #+#             */
/*   Updated: 2022/10/11 16:43:04 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_print(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	if (!tmp)
		return;
    while (tmp)
    {
        printf("content: %d  ", tmp->content);
        printf("index: %d\n", tmp->index);
        tmp = tmp->next;
    }
}