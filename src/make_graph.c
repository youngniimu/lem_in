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

void			ft_find_st_end(t_main *data)
{
	t_list	*curr;

	curr = data->rooms;
	while (curr)
	{
		((t_room*)curr->content)->curr_link = ((t_room*)curr->content)->links;
		if (((t_room*)curr->content)->pos == ST)
			data->start = curr->content;
		else if (((t_room*)curr->content)->pos == END)
		{
			data->end = curr->content;
			data->end->level = 999;
		}
		curr = curr->next;
	}
}

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

void			ft_connect_rooms(char *link_name,t_main *data)
{
	char		**link;
	t_room		*from;
	t_room		*to;

	link = ft_strsplit(link_name, '-');
	from = ft_find_room(link[0], data->rooms);
	to = ft_find_room(link[1], data->rooms);
	ft_lstaddroom(to, &from->links);
	ft_lstaddroom(from, &to->links);
	ft_strdel(&link[0]);
	ft_strdel(&link[1]);
	free(link);
}

void			ft_make_graph(t_main *data)
{
	t_list		*curr_link;

	curr_link = data->links;
	while(curr_link)
	{
		ft_connect_rooms(curr_link->content, data);
		curr_link = curr_link->next;
	}
	ft_find_st_end(data);
}