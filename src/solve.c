/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 10:33:22 by thalme            #+#    #+#             */
/*   Updated: 2020/09/08 10:33:22 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem-in.h"

void		print_list(t_list *elem)
{
	printf("[ %s ] ", ((t_room*)elem->content)->info[0]);
}

int			ft_in_queue(t_main *data, t_room *curr_room)
{
	t_list *curr;

	curr = data->queue;
	while (curr)
	{
		if (ft_strequ(curr_room->info[0], ((t_room*)curr->content)->info[0]))
			return (1);
		curr = curr->next;
	}
	return (0);
}

int			ft_check_link(char *from, t_link *link, t_main *data)
{
	t_room *destination;
	t_list *curr;
	int		ret;
	t_room *temp;


	curr = data->queue;
	while(curr->next)
		curr = curr->next;
	if (!ft_strequ(from, ((t_room*)link->from)->info[0]))
	{
		temp = link->to;
		link->to = link->from;
		link->from = temp;
	}
	destination = link->to;
	ret = ft_strequ(destination->info[0], data->end->info[0]) ? 1 : 0;
	if (!ft_in_queue(data, destination))
	{
		printf("add [%s] to queue\n", destination->info[0]);
		curr->next = ft_lstnew(NULL, sizeof(t_room));
		curr->next->content = destination;
	}
	return(ret);
}

int		ft_bfs(t_list **current_elem, int level, t_main *data)
{
	t_room *current_room;

	current_room = (*current_elem)->content;
	if (current_room->visited)
		ft_bfs(&(*current_elem)->next, level + 1, data);
	current_room->visited = 1;
	while(current_room->curr_link != NULL)
	{
		if (ft_check_link(current_room->info[0] ,current_room->curr_link->content, data))
			// IF END IS REACHED
			printf("END REACHED\n");
		current_room->curr_link = current_room->curr_link->next;
	}
	if ((*current_elem)->next)
		ft_bfs(&(*current_elem)->next, level + 1, data);
	return(1);
}

void		ft_solve(t_main *data)
{
	t_list **curr;
	
	ft_lstaddroom(data->start, &data->queue);
	curr = &data->queue;
	ft_bfs(curr, 0, data);
	ft_lstiter(data->queue, &print_list);
}