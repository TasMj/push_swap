/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:12:07 by tmejri            #+#    #+#             */
/*   Updated: 2022/07/21 15:09:08 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// int main(int argc, char **argv)
// {
// 	printf("%d", check_intru(argc, argv));
// 	// printf("%s", creat_list("1 2 3"));
// }
