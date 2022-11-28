/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:15:51 by tmejri            #+#    #+#             */
/*   Updated: 2022/11/28 20:10:18 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* verifie qu'il n'y a pas 2 fois le meme nombre dans les arguments */
int	check_doublon(t_list **list)
{
	t_list	*tmp;
	t_list	*beg;

	beg = *list;
	tmp = (*list)->next;
	while (beg != NULL)
	{
		tmp = beg->next;
		while (tmp != NULL)
		{
			if (beg->content == tmp->content)
				return (1);
			else
				tmp = tmp->next;
		}
		beg = beg->next;
	}
	return (0);
}

/* return 1 si int neg et 0 si positif */
int	check_signe_moins(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] == '-')
			c++;
		i++;
	}
	if (c > 1)
		return (1);
	return (0);
}
