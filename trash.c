/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:06:24 by tmejri            #+#    #+#             */
/*   Updated: 2022/08/04 11:19:47 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void    *copy_content(t_list *list_to_copy)
// {
//     t_list  *new_list;

//     new_list = malloc(sizeof(t_list));
//     if (!new_list)
//         return (NULL);
//     new_list->content = list_to_copy->content;
// }



int main()

t_list *list;

while (i < contenu total)
list = lstadd(&list, ft_lstnew(str[i]));
i++;
fonction(&list);

list->contenu
void    fonctionquifaitdestrucsdanslaliste(t_list **list)
[
    fonction2(list);
    (*list)->contenu;
    (*list)->next;
]

void(fonction(t_list **list))






void    *decomposer_arg(int argc, char **argv)
{
    char    *stockage;
    int     nb;
    int     i;
	int		size_char;
    t_list  *ptr;
    t_list  *start;
    t_list  **list_stack_a;

    list_stack_a = malloc(sizeof(t_list) * argc);
    if (!list_stack_a)
		return (NULL);
	i = 0;
    stockage = argv[1];
	size_char = ft_strlen(stockage);
    nb = 0;
    while (stockage[i])
    {
        nb = ft_atoi(stockage);
        printf("%d\n", nb);
        start = ft_lstnew(nb);
        ft_lstadd_back(list_stack_a, start);
        if (ft_strlen(stockage + i) == size_char)
        {
            start->premier = start;
            ptr = start->premier;
        }
        else
            start->premier = ptr;
        printf("add prem : %p\n", start->premier);
        i = size_nb(nb) + 1;
        stockage = ft_resize(stockage, i);
        i = 0;
    }
    return (list_stack_a);
}



























