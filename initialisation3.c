/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:48:08 by tmejri            #+#    #+#             */
/*   Updated: 2022/11/26 16:06:31 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* transforme les char en int pour verifier qu'il 
ne s'agit ni d'un min ni d'un max */
int	check_int(int argc, char **argv)
{
	char	**stockage;
	int		i;

	if (check_intru(argc, argv) != 1)
	{
		if (argc == 2)
		{
			stockage = ft_split(argv[1], ' ');
			if (for_check_1(stockage, argv, argc) == 1)
			{
				i = 0;
				while (stockage && stockage[i])
				{
					free(stockage[i]);
					i++;
				}
				free(stockage);
				return (1);
			}
			else
			{
				i = 0;
				while (stockage && stockage[i])
				{
					free(stockage[i]);
					i++;
				}
				free(stockage);
				return (0);
			}
		}		
		else
		{
			if (for_check_2(argv, argc) == 1)
				return (1);
			else
				return (0);
		}
	}
	return (1);
}
