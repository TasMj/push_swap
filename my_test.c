/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:12:07 by tmejri            #+#    #+#             */
/*   Updated: 2022/07/20 16:28:43 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == 0)
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

int check_intru(int argc, char *argv[])
{
    char    *list;
    int     i;
//faire pour argc = 2
    list = argv[1];    
    i = 2;
    while(argc > 2)
    {
        list = ft_strjoin(list, argv[i]);
        printf("%s\n", list);
        argc--;
        i++;
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

int main(int argc, char *argv[])
{
    printf("%d", check_intru(argc, argv));
}