/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:12:07 by tmejri            #+#    #+#             */
/*   Updated: 2022/11/17 20:26:36 by tmejri           ###   ########.fr       */
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

int	for_check_1(char **stockage, char **argv, int argc)
{
	long int	nb;
	int			i;

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
		else
		{
			argc--;
			i++;
		}
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
