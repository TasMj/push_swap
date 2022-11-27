/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:12:07 by tmejri            #+#    #+#             */
/*   Updated: 2022/11/27 03:31:46 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* On s'assure ici que la liste d'argument soit bien composée 
uniquement d'int et qu'ils soient bien tous compris entre 
int min et int max
*/

/* pour argc = 2 : split en fonction de l'espace
et la join par la suite */
char	*creat_list(char *str)
{
	char	**stockage;
	char	*list;
	char	*tmp;
	int		i;

	i = 0;
	list = malloc(1);
	list[0] = '\0';
	stockage = ft_split(str, ' ');
	while (stockage[i])
	{
		tmp = list;
		list = ft_strjoin(tmp, stockage[i]);
		i++;
		free(tmp);
	}
	i = 0;
	while (stockage && stockage[i])
	{
		free(stockage[i]);
		i++;
	}
	free(stockage);
	return (list);
}

int	for_check_intru(char *list, int i)
{
	while (list[i])
	{
		if (!((list[i] >= '0' && list[i] <= '9') || list[i] == '-'))
		{
			free(list);
			return (1);
		}
		else
			i++;
	}
	free(list);
	return (0);
}

/* vérifie qu'il n'y a que des int */
int	check_intru(int argc, char *argv[])
{
	char	*list;
	int		i;

	if (argc == 2)
		list = creat_list(argv[1]);
	else
	{
		i = 2;
		list = argv[1];
		while (argc > 2)
		{
			list = ft_strjoin(list, argv[i]);
			argc--;
			i++;
		}
	}
	i = 0;
	for_check_intru(list, i);
	return (0);
}

int	for_check_1(char **stockage, char **argv, int argc)
{
	int			i;
	long int	nb;

	stockage = ft_split(argv[1], ' ');
	i = 0;
	while (stockage[i])
	{
		if (check_signe_moins(stockage[i]) == 1)
			return (1);
		if (ft_strlen(stockage[i]) == 1)
		{
			if (stockage[i][0] == '-')
				return (1);
		}
		nb = ft_atoi(stockage[i]);
		if (!(nb >= INT_MIN && nb <= INT_MAX))
			return (1);
		argc--;
		i++;
	}
	i = 0;
	while (stockage && stockage[i++])
		free(stockage[i++]);
	free(stockage);
	return (0);
}

int	for_check_2(char **argv, int argc)
{
	long int	nb;
	int			i;

	i = 1;
	while (argc > 1)
	{
		if (check_signe_moins(argv[i]) == 1)
			return (1);
		if (ft_strlen(argv[i]) == 1)
		{
			if (argv[i][0] == '-')
				return (1);
		}
		nb = ft_atoi(argv[i]);
		if (!(nb >= INT_MIN && nb <= INT_MAX))
			return (1);
		else
		{
			argc--;
			i++;
		}
	}
	return (0);
}
