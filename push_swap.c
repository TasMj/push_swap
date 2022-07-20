/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:28:11 by tmejri            #+#    #+#             */
/*   Updated: 2022/07/20 16:19:05 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// ft_lstadd_back()
// ft_lstiter()

//check si il y a un char qui n'est pas un int
int check_intru(int argc, char *argv[])
{
    char    *list;
    int     i;
//faire pour argc = 2
    list = argv[0];    
    i = 0;
    while(argc > 0)
    {
        list = ft_strjoin(list, argv[i]);
        argc--;
        i++;
    }
    i = 0;
    while (list[i])
    {
        if (!(list[i] >= '0' && list[i] <= '9' || list[i] == '-'))
            return (0);
        else
            i++;
    }
    return (1);
}


//teste si il s'agit bien d'un entier
int is_an_int(char *x)
{
    int nb;

    nb = ft_atoi(x);
    if (nb >= INT_MIN && nb <= INT_MAX)
        return (1);
    else
        return (0);

}

// donner chaque argument a un content d'une liste
void    *attribution_arg(int argc, char *argv[])
{
    int     i;

    i = 0;
    while (argv[])
    {
        if i
        arg = ft_lstnew(va_arg(list_stack_a, int));
        ft_lstadd_back(**list_stack_a, *arg)
    }
}

//recupere la liste d'int (stack a) prealablement faite pour la trier
void *push_swap(t_list list_stack_a)
{ 
}








#include <stdlib.h>
int main ()
{

// soit 1 2 3 4 5    --> argc = 6
//soit "1 2 3 4 5"   --> argc = 2
// faire 2 fonctions pour ces 2 cas
//en fonction de argc appeler l'une ou l'autre

    printf("%d", is_an_int("78"));
}