// int	size_list(t_list **list_a)
// {
// 	int size_a;
// 	int middle;
	
// 	size_a = ft_lstsize(*list_a);
// 	if (size_a % 2 == 0)
// 		middle = (size_a / 2);
// 	else
// 		middle = (size_a / 2) + 1;
// 	return (middle);
// }


// int	from_top(t_list **list_a, t_list **list_b)
// {
// 	int		middle;
// 	int		keep_middle;
// 	int		c;
// 	t_list	*tmp;
// 	int		r;

// 	c = 0;
// 	r = 0;
// 	tmp = *list_a;
// 	middle = size_list(list_a);
// 	keep_middle = middle;
// 	while (middle > 0)
// 	{
// 		if ((*list_b)->index > (*list_a)->index)
// 		{
// 			(*list_a) = (*list_a)->next;
// 			c++;
// 		}
// 		middle--;
// 	}
// 	if (c == keep_middle && ((*list_b)->index > (*list_a)->index))
// 		r = -1;
// 	else
// 		r = c;
// 	*list_a = tmp;
// 	return (r);
// }

// int	down_even(t_list **list_a, t_list **list_b, int middle) //paire
// {
// 	int	c;
// 	int keep_middle;
// 	t_list	*tmp;

// 	keep_middle = middle;
// 	tmp = *list_a;
// 	while (middle > 0)
// 	{
// 		if ((*list_a)->next)
// 			(*list_a) = (*list_a)->next;
// 		middle--;
// 	}
// 	middle = keep_middle;
// 	while ((*list_a) && middle > 0)
// 	{
// 		if ((*list_b)->index > (*list_a)->index)
// 		{
// 			if ((*list_a)->next)
// 			{
// 				(*list_a) = (*list_a)->next;
// 				c++;
// 			}
// 		}
// 		middle--;
// 	}
// 	if (c == keep_middle && ((*list_b)->index > (*list_a)->index))
// 	{
// 		*list_a = tmp;
// 		return (0);
// 	}
// 	else
// 	{
// 		*list_a = tmp;
// 		return (keep_middle - c);
// 	}
// }


// int	down_odd(t_list **list_a, t_list **list_b, int middle) // impaire
// {
// 	int	c;
// 	int keep_middle;
// 	t_list	*tmp;

// 	tmp = *list_a;
// 	keep_middle = middle;
// 	while (middle > 0)
// 	{
// 		if ((*list_a)->next)
// 			(*list_a) = (*list_a)->next;
// 		middle--;
// 	}
// 	middle = keep_middle - 1;
// 	while ((*list_a) && middle > 0)
// 	{
// 		if ((*list_b)->index > (*list_a)->index)
// 		{
// 			if ((*list_a)->next)
// 			{
// 				(*list_a) = (*list_a)->next;
// 				c++;
// 			}
// 		}
// 		middle--;
// 	}
// 	if (c == (keep_middle - 1) && ((*list_b)->index > (*list_a)->index))
// 	{
// 		*list_a = tmp;
// 		return (0);
// 	}
// 	else
// 	{
// 		*list_a = tmp;
// 		return ((keep_middle - 1) - c);
// 	}
// }




// int	from_down(t_list **list_a, t_list **list_b)
// {
// 	int		res;
// 	int		middle;

// 	res = 0;
// 	middle = size_list(list_a);
// 	if (middle % 2 == 0)
// 		res = down_even(list_a, list_b, middle);
// 	else
// 		res = down_odd(list_a, list_b, middle);
// 	return (res);
// }