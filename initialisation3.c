/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:48:08 by tmejri            #+#    #+#             */
/*   Updated: 2022/12/05 13:35:11 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	annex(char **stockage, char **argv, int argc, int i)
{
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
	i = 0;
	while (stockage && stockage[i])
	{
		free(stockage[i]);
		i++;
	}
	free(stockage);
	return (0);
}

/* transforme les char en int pour verifier qu'il 
ne s'agit ni d'un min ni d'un max */
int	check_int(int argc, char **argv)
{
	char	**stockage;
	int		i;

	i = 0;
	if (check_intru(argc, argv) != 1)
	{
		if (argc == 2)
		{
			stockage = ft_split(argv[1], ' ');
			if (annex(stockage, argv, argc, i) == 1)
				return (1);
		}		
		if (for_check_2(argv, argc) == 1)
			return (1);
		return (0);
	}
	return (1);
}
