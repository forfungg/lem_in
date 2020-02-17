/*
** from input_check.c
*/

static int	check_duplicate_ngb(t_prop *xt)
{
	int		cnt;
	int		len;
	t_node	*temp;

	temp = xt->elems;
	while (temp != 0)
	{
		if (check_duplicate(temp->ngb) == 1)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	print_queue(t_que *queue)
{
	if (!queue)
		return ;
	ft_printf("%s", queue->node->name);
	queue = queue->next;
	while (queue)
	{
		ft_printf(" - %s", queue->node->name);
		queue = queue->next;
	}
	ft_printf("\n");
}

/*
** Print Paths
*/

void	print_paths(t_paths *paths)
{
	int i;

	i = 1;
	while (paths)
	{
		ft_printf("%8d:\t", i);
		print_queue(paths->path);
		paths = paths->next;
		i++;
	}
}
