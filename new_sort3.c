/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:47:20 by tmejri            #+#    #+#             */
/*   Updated: 2022/11/10 18:49:25 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* return 5 si il y a <= 100 nb et 10 sinon 
5 et 10 etant le nb de blocks */
int five_or_ten(t_list **list_a)
{
    int	size_list;
	
    size_list = ft_lstsize(*list_a);
    if (size_list <= 100)
        return (5);
    if (size_list > 100)
        return (10);
    else
        return (0);
}

/* return le nb d'elt par block (en blocks de 5 si <= 100
en blocks de 10 si > 100) */
int	size_block(t_list **list_a)
{
    int	size_list;
    int	div;
	
    size_list = ft_lstsize(*list_a);
    if (size_list <= 100)
    {
        div = size_list / 5;
        if (div * 5 != size_list)
            return ((size_list / 5) + 1);
        else
            return (div);
    }
    else
    {
        div = size_list / 10;
        if (div * 10 != size_list)
            return ((size_list / 10) + 1);
        else
            return (div);
    }
}
