/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:12:07 by tmejri            #+#    #+#             */
/*   Updated: 2022/07/23 11:32:50 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* On s'assure ici que la liste d'argument soit bien composée 
uniquement d'int et qu'ils soient bien tous compris entre 
int min et int max
*/

//pour argc = 2 on split la liste et on la join par la suite
char	*creat_list(char *str)
{
	char	**stockage;
	char	*list;
	int	i;
	
	i = 0;
	list = "";
	stockage = ft_split(str, ' ');
	while (stockage[i])
	{
		list = ft_strjoin(list, stockage[i]);
		i++;
	}
	return (list);
}

//vérifie qu'il n'y a que des int
int check_intru(int argc, char *argv[])
{
    char    *list;
    int     i;

	if (argc == 2)
		list = creat_list(argv[1]);
	else
	{
		list = argv[1];
		i = 2;
		while(argc > 2)
		{
			list = ft_strjoin(list, argv[i]);
			argc--;
			i++;
		}
	}
    i = 0;
    while (list[i])
    {
        if (!((list[i] >= '0' && list[i] <= '9') || list[i] == '-'))
            return (0);
        else
            i++;
    }
    return (1);
}

//transforme les char en int pour verifier qu'il ne s'agit ni d'un min ni d'un max
int check_int(int argc, char **argv)
{
    long int nb;
	char	**stockage;
	int i;

	i = 1;
    if (check_intru(argc, argv) == 1)
    {
		if (argc == 2)
		{
			stockage = ft_split(argv[1], ' ');
			i = 0;
			while (stockage[i])
			{
				nb = ft_atoi(stockage[i]);
				if (!(nb >= INT_MIN && nb <= INT_MAX))
                return (0);
				else
				{
                	argc--;
					i++;
				}
				
			}
			return (1);
		}
		else
		{
        	while (argc > 1)
        	{
        	    nb = ft_atoi(argv[i]);
        	    if (!(nb >= INT_MIN && nb <= INT_MAX))
        	        return (0);
				else
				{
        	        argc--;
					i++;
				}
        	}
			return (1);
		}
	}
	return (0);
}

// #include <stdio.h>
// int main(int argc, char **argv)
// {
// 	printf("%d\n", check_int(argc, argv));
// 	// printf("%d", check_intru(argc, argv));
// 	// printf("%s", creat_list("1 2 3"));
// }
