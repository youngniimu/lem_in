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

// int		ft_dfs(t_room *curr, t_main *data)
// {
// 	curr->visited = 1;
// 	printf("[ %s ] -> ", curr->info[0]);
// 	if (ft_strequ(curr->info[0], data->end->info[0]))
// 	{
// 		data->reach_end = 1;
// 		printf("[ END ]!!!\n\n");
// 		return (data->reach_end);
// 	}
// 	else if (!((t_room*)curr->curr_link->content)->visited)
// 	{
// 		printf("[ %s ]\n", ((t_room*)curr->curr_link->content)->info[0]);
// 		ft_dfs(curr->curr_link->content, data);
// 	}
// 	else if (curr->curr_link->next && curr->curr_link->next->content)
// 	{
// 		printf("[ X ], %s visited, next\n", ((t_room*)curr->curr_link->content)->info[0]);
// 		curr->curr_link = curr->curr_link->next;
// 		ft_dfs(curr, data);
// 	}
// 	// REMOVE THIS TO DISABLE DFS
// 	if (curr->curr_link->next && curr->curr_link->next->content)
// 	{
// 		printf("[ %s ] -> ", curr->info[0]);
// 		printf("[ X ], %s visited, next\n", ((t_room*)curr->curr_link->content)->info[0]);
// 		curr->curr_link = curr->curr_link->next;
// 		ft_dfs(curr, data);
// 	}
// 	printf("[ NE ]\n");
// 	return (data->reach_end);
// }

// void		ft_start_dfs(t_main *data)
// {
// 	t_room	*curr;

// 	curr = data->start;
// 	int routes = 0;
// 	// int i = 20;
// 	printf("START FINDING\n\n");
	
// 	while (ft_dfs(curr, data))
// 	{
// 		++routes;
// 		data->reach_end = 0;
// 	}
// 	printf("%d routes found\n", routes);
// 	t_list *currr;
// 	currr = data->rooms;
// 	int err = 0;
// 	while (currr)
// 	{
// 		((t_room*)currr->content)->curr_link = ((t_room*)currr->content)->links;
// 		if (!((t_room*)currr->content)->visited)
// 			err++;
// 		((t_room*)currr->content)->visited = 0;
// 		currr = currr->next;
// 	}
// 	if (err)
// 		printf("not all roooms were visited\n");
// 	else
// 		printf("all roooms were visited, bonkers!\n");
// }

// int			ft_check_queue(t_main *data, t_room *curr_room)
// {
// 	t_list *curr;

// 	curr = data->queue;
// 	while (curr)
// 	{
// 		if (ft_strequ(curr_room->info[0], ((t_room*)curr->content)->info[0]))
// 			return (1);
// 		curr = curr->next;
// 	}
// 	return (0);
// }

// int			ft_bfs(t_list *queue,  t_list **curr, t_main *data, int level)
// {
// 	t_room *curr_room;

// 	printf("\nrecursion\n");
// 	// printf("%s\n", ((t_room*)((t_room*)(*curr)->content)->curr_link->next->content)->info[0]);
// 	curr_room = (*curr)->content;
// 	curr_room->level = level;
// 	// printf("%p %p %p %p\n", &(*data->start), &(*curr_room), &(*queue->content), &(*(*curr)->content));
// 	printf("current room: [ %s ]\n", curr_room->info[0]);
// 	while (curr_room->curr_link)
// 	{
// 		printf("links:%d", ft_lstlen(curr_room->curr_link));
// 		printf("visited?%d", ((t_room*)curr_room->curr_link->content)->visited);
// 		printf("name:[%s]\n", ((t_room*)curr_room->curr_link->content)->info[0]);
// 		// if (!((t_room*)curr_room->curr_link->content)->visited)
// 		if (!ft_check_queue(data, (t_room*)curr_room->curr_link->content))
// 		{
// 			printf("add link [ %s ]\n", ((t_room*)curr_room->curr_link->content)->info[0]);
// 			queue->next = ft_lstnew(NULL, sizeof(t_room));
// 			queue->next->content = curr_room->curr_link->content;
// 			if (ft_strequ(((t_room*)curr_room->curr_link->content)->info[0], data->end->info[0]))
// 			{
// 				// ft_build_residual(queue, data)
// 				data->reach_end = 1;
// 				printf("[ END ]!!!\n\n");
// 				ft_lstaddroom(curr_room->curr_link->content, &data->route);
// 				printf("FIRST\n");
// 				// ft_lstadd(&data->route, ft_lstnew(NULL, sizeof(t_room)));
// 				// data->route->content = (t_room*)curr_room->curr_link->content;
// 				ft_lstaddroom(curr_room, &data->route);
// 				printf("ND\n");
// 				printf("%d\n", ft_lstlen(data->route));
// 				// ft_lstadd(&data->route, ft_lstnew(NULL, sizeof(t_room)));
// 				// data->route->content = curr_room;
// 				return (data->reach_end);
// 			}
// 			queue = queue->next;
// 		}
// 		curr_room->curr_link = curr_room->curr_link->next;
// 	}
// 	if ((*curr)->next != NULL && !data->reach_end)
// 		ft_bfs(queue, &(*curr)->next, data, level + 1);
// 	curr_room->curr_link = curr_room->links;
// 	while(curr_room->curr_link)
// 	{
// 		if (ft_strequ(((t_room*)curr_room->curr_link->content)->info[0], ((t_room*)data->route->content)->info[0]))
// 			ft_lstaddroom(curr_room, &data->route);
// 		curr_room->curr_link = curr_room->curr_link->next;
// 	}
// 	return(data->reach_end);
// }

// void		print_list(t_list *elem)
// {
// 	printf("[ %s l:%d ] ", ((t_room*)elem->content)->info[0], ((t_room*)elem->content)->level);
// }

// void		check_room(t_list *elem)
// {
// 	((t_room*)elem->content)->visited = 1;
// }

// void		ft_start_bfs(t_main *data)
// {
// 	t_list *queue;
// 	t_list **curr;
	

// 	queue = ft_lstnew(NULL, sizeof(t_room));
// 	queue->content = data->start;
// 	curr = &queue;
// 	data->queue = queue;
// 	ft_bfs(queue, curr, data, 0);
// 	printf("queue: ");
// 	ft_lstiter(data->queue, &print_list);
// 	printf("\n");
// 	printf("route: ");
// 	ft_lstiter(data->route, &print_list);
// 	printf("\n");
// 	ft_lstiter(data->route, &check_room);
// 	// ft_lstiter(data->route, &c_room);
// }

// void		ft_find_routes(t_main *data)
// {
// 	// ft_start_dfs(data);
// 	ft_start_bfs(data);
// }