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
