/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 10:33:44 by thalme            #+#    #+#             */
/*   Updated: 2020/09/08 10:33:44 by thalme           ###   ########.fr       */
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
			data->end->level = MAX_INT;
		}
		curr = curr->next;
	}
}

t_room		*ft_create_room(char *str, int pos)
{
	t_room	*room;

	room = (t_room*)malloc(sizeof(t_room));
	room->info = ft_strsplit(str, ' ');
	room->visited = 0;
	room->level = 0;
	room->pos = pos;
	room->links = NULL;
	room->curr_link = NULL;
	return (room);
}

t_link		*ft_create_link(t_room *to, t_room *from)
{
	t_link	*link;

	link = (t_link*)malloc(sizeof(t_link));
	link->from = from;
	link->to = to;
	link->flow = 0;
	link->capacity = 0;
	link->dir = 0;
	return (link);
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

void		ft_add_link(t_main *data, char *link_name)
{
	char		**link_split;
	t_room		*from;
	t_room		*to;
	t_link		*link;

	link_split = ft_strsplit(link_name, '-');
	from = ft_find_room(link_split[0], data->rooms);
	to = ft_find_room(link_split[1], data->rooms);
	link = ft_create_link(to, from);
	ft_lstadd(&data->links, ft_lstnew(NULL, sizeof(t_link)));
	data->links->content = link;
	ft_lstadd(&from->links, ft_lstnew(NULL, sizeof(t_link)));
	from->links->content = link;
	ft_lstadd(&to->links, ft_lstnew(NULL, sizeof(t_link)));
	to->links->content = link;
	ft_strdel(&link_split[0]);
	ft_strdel(&link_split[1]);
	free(link_split);
}

void		ft_handle_input(t_main *data)
{
	char	*str;

	while(get_next_line(0, &str))
	{
		if (str[0] == '#' && str[1] != '#')
			;
		else if (!data->ant_amount)
			data->ant_amount = ft_atoi(str);
		else if (ft_strequ(str, "##start"))
			data->pos = ST;
		else if (ft_strequ(str, "##end"))
			data->pos = END;
		else if (ft_strchr(str, ' '))
		{
				ft_lstaddroom(ft_create_room(str, data->pos), &data->rooms);
				data->pos = 0;
		}
		else
			ft_add_link(data, str);
		free(str);
	}
	ft_find_st_end(data);
	// while(1);
	/*
	** PRINT OUTPUT
	*/
	// t_list *rcurr = data->rooms;
	// t_list *lcurr = data->links;
	// // t_list *ccurr = data->comments;
	// printf("\n");
	// printf("ANTS: %d\n", data->ant_amount);
	// printf("\n");
	// printf("ROOMS:\n");
	// while(rcurr)
	// {
	// 	printf("name: [%s]\tpos: [%d]\n", ((t_room*)rcurr->content)->info[0], ((t_room*)rcurr->content)->pos);
	// 	rcurr = rcurr->next;
	// }
	// printf("\n");
	// printf("LINKS:\n");
	// while(lcurr)
	// {
	// 	printf("[%s]->[%s]\n", ((t_room*)((t_link*)lcurr->content)->to)->info[0], ((t_room*)((t_link*)lcurr->content)->from)->info[0]);
	// 	lcurr = lcurr->next;
	// }
	
	// printf("\n\nEND HANDLE_INPUT\n\n");
	// printf("start [%s] is connected to %d rooms,", data->start->info[0], ft_lstlen(data->start->links));
	// printf("[%s] and [%s]\n", ((t_room*)((t_link*)data->start->curr_link->content)->from)->info[0], ((t_room*)((t_link*)data->start->curr_link->next->content)->to)->info[0]);
	// printf("end [%s] is connected to %d rooms ", data->end->info[0], ft_lstlen(data->end->links));
	// printf("[%s] and [%s]\n", ((t_room*)((t_link*)data->end->curr_link->content)->to)->info[0], ((t_room*)((t_link*)data->end->curr_link->next->content)->to)->info[0]);

}
