/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_utiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:06:15 by tas               #+#    #+#             */
/*   Updated: 2022/11/27 02:29:27 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* transforme les char* en int */
long int	ft_atoi(char *nptr)
{
	long int		res;
	long int		i;
	long int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' '))
		i++;
	if (nptr && nptr[i] == '-')
	{
		sign = -sign;
		i++;
	}
	while (nptr && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		res = (res * 10) + (nptr[i] - 48);
		i++;
	}
	return (res * sign);
}

/* return la taille d'une char* */
int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* return le nb de chiffre d'un nb */
int	size_nb(int nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

/* ajoute a une char* une autre char* */
char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

void	free_2_lists(t_list **list_a, t_list **list_b)
{
	free_list(list_a);
	free_list(list_b);
}
