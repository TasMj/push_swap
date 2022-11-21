// int find_rank_top(t_list **list_a, t_list **list_b, int middle)
// {
// 	int	c;
// 	int	size_a;
// 	t_list	*last;
// 	t_list	*before_last;

// 	c = 0;
// 	size_a = ft_lstsize(*list_a);
// 	while (middle > 0)
// 	{
// 		last = last_elt(list_a, size_a);
// 		before_last = last_elt(list_a, size_a - 1);

// 		if (((*list_b)->index < (*list_a)->index) && ((*list_b)->index > last->index)) //premier elt
// 			return (0);
			
// 		else if (((*list_b)->index < (*list_a)->index) && ((*list_b)->index < last->index) && ((*list_a)->index > last->index))
// 			return (-1);
// 		else if (((*list_b)->index < (*list_a)->index) && ((*list_b)->index < last->index))
// 		{
// 			printf("1-1er\n");	
// 			return (0); //a voir
// 		}
// 		else if (((*list_b)->index > before_last->index) && ((*list_b)->index < last->index))
// 		{
// 			printf("1-2eme\n");
// 			return (-1);
// 		}
// 		// else if (((*list_b)->index > (*list_a)->index)) //last
// 		else
// 		{
// 			while (((*list_b)->index > (*list_a)->index) && middle > 0)
// 			{
// 				printf("1-3eme\n");
// 				(*list_a) = (*list_a)->next;
// 				c++;
// 				middle--;
// 			}
// 			return (c);
// 		}
// 	}
// 	return (c);
// }

// int find_rank_down(t_list **list_a, t_list **list_b, int middle)
// {
// 	int	c;
// 	int	size_a;
// 	t_list	*last;
// 	t_list	*before_last;

// 	c = 0;
// 	size_a = ft_lstsize(*list_a);
// 	while (((*list_a)->next != NULL) && middle > 0)
// 	{
// 		last = last_elt(list_a, size_a);
// 		before_last = last_elt(list_a, (size_a - 1));
		
// 		if (((*list_b)->index < (*list_a)->index) && ((*list_b)->index < last->index) && ((*list_a)->index > last->index))
// 		{
// 			while (((*list_a)->next != NULL) && ((*list_b)->index < (*list_a)->index) && (middle > 0))
// 			{
// 				printf("{%d}\n", (*list_a)->index);
// 				(*list_a) = (*list_a)->next;
// 				middle--;
// 				c++;
// 			}
// 			return (c);
// 			// return (0);
// 		}
// 		if (((*list_b)->index < (*list_a)->index) && ((*list_b)->index > last->index)) //premier elt
// 		{
// 			printf("2-1er\n");
// 			return (-1); //a voir
// 		}
// 		else if (((*list_b)->index > before_last->index) && ((*list_b)->index < last->index))
// 		{
// 			printf("2-2eme\n");
// 			return (1);
// 		}
// 		else if (((*list_b)->index < (*list_a)->index) && ((*list_b)->index < last->index))
// 		{
// 			while (((*list_b)->index > (*list_a)->index) && middle > 0)
// 			{
// 				printf("1-3eme\n");
// 				(*list_a) = (*list_a)->next;
// 				c++;
// 				middle--;
// 			}
// 			return (c);
// 		}
// 		// else if (((*list_b)->index > (*list_a)->index)) //last
// 		while (((*list_b)->index > (*list_a)->index) && middle > 0)
// 		{
// 			printf("1-3eme\n");
// 			(*list_a) = (*list_a)->next;
// 			c++;
// 			middle--;
// 		}
// 		return (c);
// 	}
// 	return (c);
// }