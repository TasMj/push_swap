/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:16:33 by tmejri            #+#    #+#             */
/*   Updated: 2022/08/11 13:17:50 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{	
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{	
				ft_swap(&tab[i], &tab[j]);
			}
			j++;
		}
		i++;
	}
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	cal;

	cal = size - 1;
	i = 0;
	while (i < (size / 2))
	{
		ft_swap(&tab[i], &tab[cal]);
		i++;
		cal--;
	}
}