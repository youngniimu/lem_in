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

t_room			*ft_find_room(char *room_name, t_list *rooms)
{
	while(rooms)
	{
		if (ft_strequ(((t_room*)rooms->content)->info[0], room_name))
			return(rooms->content);
		rooms = rooms->next;
	}
	return (NULL);
}

// void			ft_add_links(t_room *room, t_room *link)
// {
// 	t_list *curr;

// 	ft_lstadd(room->links, ft_lstnew(link, sizeof(link)));
// }

void			ft_connect_start_end(char *link_name, t_list *rooms, t_room *edge)
{
	char		**link;
	t_room		*from;
	t_room		*to;

	link = ft_strsplit(link_name, '-');
	from = ft_strequ(link[0], edge->info[0]) ? edge : ft_find_room(link[0], rooms);
	to = ft_strequ(link[1], edge->info[0]) ? edge : ft_find_room(link[1], rooms);
	printf("[%s]->[%s]\n", from->info[0], to->info[0]);
	ft_lstadd(&from->links, ft_lstnew(to, sizeof(to)));
	ft_lstadd(&to->links, ft_lstnew(from, sizeof(from)));
	// ft_add_links(from, to);
	// // printf("first===");
	// ft_add_links(to, from);
	// // printf("second\n");
	ft_strclr(link[0]);
	ft_strclr(link[1]);

	// printf("check links\n");
	printf("[%s]->[%s]\n", from->info[0], ((t_room*)from->links->content)->info[0]);
	printf("[%s]->[%s]\n", to->info[0], ((t_room*)to->links->content)->info[0]);
	// printf("[%s]->[%s]\n", to->info[0], to->links[0]->info[0]);
	// printf("links ok\n\n");
	// while(1);
}

void			ft_connect_rooms(char *link_name, t_list *rooms)
{
	char		**link;
	t_room		*from;
	t_room		*to;

	link = ft_strsplit(link_name, '-');
	from = ft_find_room(link[0], rooms);
	to = ft_find_room(link[1], rooms);
	// printf("[%s]->[%s]\n", from->info[0], to->info[0]);
	
	ft_lstadd(&from->links, ft_lstnew(to, sizeof(to)));
	ft_lstadd(&to->links, ft_lstnew(from, sizeof(from)));
	// ft_add_links(from, to);
	// ft_add_links(to, from);
	ft_strclr(link[0]);
	ft_strclr(link[1]);
}

void			ft_make_graph(t_list *rooms, t_list *links, t_main *data)
{
	t_list		*link_head;

	link_head = links;
	printf("START IS: %s\t\t\tEND IS: %s\n\n", data->start->info[0], data->end->info[0]);
	printf("%d links in graph\n", ft_lstlen(links));
	while(links)
	{
		// printf("%s\n", links->content);
		if (ft_strstr(links->content, data->start->info[0]) != NULL)
			ft_connect_start_end(links->content, rooms, data->start);
		else if (ft_strstr(links->content, data->end->info[0]) != NULL)
			ft_connect_start_end(links->content, rooms, data->end);
		else
			ft_connect_rooms(links->content, rooms);
		// printf("[%s]->[%s]\n", data->end->info[0], ((t_room*)data->end->links->content)->info[0]);
		// while(1);
		links = links->next;
	}

	printf("out\n\n");
	// printf("%s\n", data->start->links[0]->info[0]);
	// while(1);
}

	// links = link_head;
	// while(links)
	// {
	// 	if (ft_strstr(links->content, ((t_room*)data->end)->info[0]) != NULL)
	// 	{
	// 		printf("make end\n");
	// 		link = ft_strsplit(links->content, '-');
	// 		from = ft_strequ(link[0], ((t_room*)data->end)->info[0]) ? data->end : ft_find_room(link[0], rooms);
	// 		to = ft_strequ(link[1], ((t_room*)data->end)->info[0]) ? data->end : ft_find_room(link[1], rooms);
	// 		ft_add_links(from, to);
	// 		ft_add_links(to, from);
	// 		ft_strclr(link[0]);
	// 		ft_strclr(link[1]);
	// 	}
	// 	links = links->next;
	// }
	// links = link_head;
	// while(links)
	// {
	// 	if (ft_strstr(links->content, ((t_room*)data->start)->info[0]) != NULL)
	// 		;
	// 	else if (ft_strstr(links->content, ((t_room*)data->end)->info[0]) != NULL)
	// 		;
	// 	else
	// 	{
	// 		link = ft_strsplit(links->content, '-');
	// 		from = ft_find_room(link[0], rooms);
	// 		to = ft_find_room(link[1], rooms);
	// 		ft_add_links(from, to);
	// 		ft_add_links(to, from);
	// 		ft_strclr(link[0]);
	// 		ft_strclr(link[1]);
	// 	}
	// 	links = links->next;
	// }