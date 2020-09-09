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
		if (ft_strequ(((t_room*)rooms->content)->name, room_name))
			return(rooms->content);
		rooms = rooms->next;
	}
	return (NULL);
}

void			ft_add_links(t_room *room, t_room *link)
{
	int i;

	i = 0;
	while(room->links[i] != NULL)
		i++;
	room->links[i] = link;
}

void			ft_make_graph(t_list *rooms, t_list *links, t_main *data)
{
	t_list		*link_head;
	char		**link;
	t_room		*from;
	t_room		*to;

	link_head = links;
	while(links)
	{
		if (ft_strstr(links->content, ((t_room*)data->start)->name) != NULL)
		{
			link = ft_strsplit(links->content, '-');
			from = ft_strequ(link[0], ((t_room*)data->start)->name) ? data->start : ft_find_room(link[0], rooms);
			to = ft_strequ(link[1], ((t_room*)data->start)->name) ? data->start : ft_find_room(link[1], rooms);
			ft_add_links(from, to);
			ft_add_links(to, from);
			ft_strclr(link[0]);
			ft_strclr(link[1]);
		}
		links = links->next;
	}
	links = link_head;
	while(links)
	{
		if (ft_strstr(links->content, ((t_room*)data->end)->name) != NULL)
		{
			link = ft_strsplit(links->content, '-');
			from = ft_strequ(link[0], ((t_room*)data->end)->name) ? data->end : ft_find_room(link[0], rooms);
			to = ft_strequ(link[1], ((t_room*)data->end)->name) ? data->end : ft_find_room(link[1], rooms);
			ft_add_links(from, to);
			ft_add_links(to, from);
			ft_strclr(link[0]);
			ft_strclr(link[1]);
		}
		links = links->next;
	}
	links = link_head;
	while(links)
	{
		if (ft_strstr(links->content, ((t_room*)data->start)->name) != NULL)
			;
		else if (ft_strstr(links->content, ((t_room*)data->end)->name) != NULL)
			;
		else
		{
			link = ft_strsplit(links->content, '-');
			from = ft_find_room(link[0], rooms);
			to = ft_find_room(link[1], rooms);
			ft_add_links(from, to);
			ft_add_links(to, from);
			ft_strclr(link[0]);
			ft_strclr(link[1]);
		}
		links = links->next;
	}
}
