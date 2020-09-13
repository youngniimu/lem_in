/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_routes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 10:33:44 by thalme            #+#    #+#             */
/*   Updated: 2020/09/08 10:33:44 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem-in.h"

int		ft_dfs(t_room *curr, t_main *data)
{
	curr->visited = 1;
	printf("[ %s ] -> ", curr->info[0]);
	if (ft_strequ(curr->info[0], data->end->info[0]))
	{
		data->reach_end = 1;
		printf("[ END ]!!!\n\n");
		return (data->reach_end);
	}
	else if (!((t_room*)curr->curr_link->content)->visited)
	{
		printf("[ %s ]\n", ((t_room*)curr->curr_link->content)->info[0]);
		ft_dfs(curr->curr_link->content, data);
	}
	else if (curr->curr_link->next && curr->curr_link->next->content)
	{
		printf("[ X ], %s visited, next\n", ((t_room*)curr->curr_link->content)->info[0]);
		curr->curr_link = curr->curr_link->next;
		ft_dfs(curr, data);
	}
	// REMOVE THIS TO DISABLE DFS
	if (curr->curr_link->next && curr->curr_link->next->content)
	{
		printf("[ %s ] -> ", curr->info[0]);
		printf("[ X ], %s visited, next\n", ((t_room*)curr->curr_link->content)->info[0]);
		curr->curr_link = curr->curr_link->next;
		ft_dfs(curr, data);
	}
	printf("[ NE ]\n");
	return (data->reach_end);
}

void		ft_start_dfs(t_main *data)
{
	t_room	*curr;

	curr = data->start;
	int routes = 0;
	// int i = 20;
	printf("START FINDING\n\n");
	
	while (ft_dfs(curr, data))
	{
		++routes;
		data->reach_end = 0;
	}
	printf("%d routes found\n", routes);
	t_list *currr;
	currr = data->rooms;
	int err = 0;
	while (currr)
	{
		((t_room*)currr->content)->curr_link = ((t_room*)currr->content)->links;
		if (!((t_room*)currr->content)->visited)
			err++;
		((t_room*)currr->content)->visited = 0;
		currr = currr->next;
	}
	if (err)
		printf("not all roooms were visited\n");
	else
		printf("all roooms were visited, bonkers!\n");
}

int			ft_bfs(t_list *queue,  t_list **curr, t_main *data, int level)
{
	t_room *curr_room;

	printf("recursion\n");
	printf("%s\n", ((t_room*)((t_room*)(*curr)->content)->curr_link->next->content)->info[0]);
	curr_room = (*curr)->content;
	curr_room->visited = 1;
	printf("%p %p %p\n", &data->start, &curr_room, &queue->content);
	printf("[ %s ]\n", curr_room->info[0]);
	while (curr_room->curr_link)
	{
		printf("links:%d visited?%d name:[%s]\n", ft_lstlen(curr_room->curr_link), ((t_room*)curr_room->curr_link)->visited, ((t_room*)curr_room->curr_link)->info[0]);
		if (!((t_room*)curr_room->curr_link)->visited)
		{
			printf("add link [ %s ]\n", ((t_room*)curr_room->curr_link)->info[0]);
			queue->next = ft_lstnew(NULL, sizeof(t_room));
			queue->next->content = curr_room->curr_link->content;
		}
		curr_room->curr_link = curr_room->curr_link->next;
		queue = queue->next;
	}
	while(1);
	data->ant_amount += 0;
	printf("%d\n", ft_lstlen(*curr));
	printf("%d\n", level);
	if (!level)
	{
		ft_bfs(queue, &(*curr)->next, data, level + 1);
	}
	return(1);
}

void		ft_start_bfs(t_main *data)
{
	t_list *queue;
	t_list **curr;

	queue = ft_lstnew(NULL, sizeof(t_room));
	queue->content = data->start;
	curr = &queue;
	ft_bfs(queue, curr, data, 0);
}

void		ft_find_routes(t_main *data)
{
	// ft_start_dfs(data);
	ft_start_bfs(data);
}