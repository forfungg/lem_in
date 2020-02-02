/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny < jnovotny@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 11:25:04 by jnovotny          #+#    #+#             */
/*   Updated: 2020/02/02 12:25:13 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Breath First Search of All pathways
** Might change to bfs(start node, end node) ?
*/

void    bfs(t_node *head)
{
    int i;
    t_que *q;
    t_node *current;

    q = NULL;
    if (!head)
        return ;
    current = head;
    while (current)
    {
        i = 0;
        current->visited = TRUE;
        ft_putendl("here2");
        while (current->ngb && current->ngb[i])
        {
            if (!(current->ngb[i]->visited))
                q = enqueue(q, head->ngb[i]);
            i++;
        }
        print_queue(q);
        ft_putendl("here3");
        current = que_getnext(&q);
    }
}