/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 10:33:44 by thalme            #+#    #+#             */
/*   Updated: 2020/09/08 10:33:44 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem-in.h"

void		ft_get_ant_amount(t_main *data, char *str)
{
	data->ant_amount = ft_atoi(str);
}

t_room		*ft_create_room(char *str, t_main *data)
{
	t_room	*room;
	char		**info;
	// char	*temp;

	info = ft_strsplit(str, ' ');
	room = (t_room*)malloc(sizeof(t_room));
	room->name = info[0];
	room->x = ft_atoi(info[1]);
	room->y = ft_atoi(info[2]);
	// room->links = NULL;
	room->id = data->room_index++;
	room->visited = 0;
	// free(temp);
	// free(info[0]);
	free(info[1]);
	free(info[2]);
	return (room);
}

void		ft_add_room(t_main *data, t_list **curr, t_list **head, char *str)
{
	t_room *room;
	// printf("start add room\n");
	room = ft_create_room(str, data);
	// printf("room created\n");
	// printf("name: %s\nx: %d\ny: %d\nid: %d\nvisited: %d\n", room->name, room->x, room->y, room->id, room->visited);
	if (*head == NULL)
	{
		*curr = ft_lstnew(room, sizeof(t_room));
		*head = *curr;
	}
	else
	{
		(*curr)->next = ft_lstnew(room, sizeof(t_room));
		*curr = (*curr)->next;
	}
	// free(room);
}

// t_link		*ft_create_link(char *str)
// {
// 	t_link	*link;
	
// 	link = (t_link*)malloc(sizeof(t_link));
// 	link->from = NULL;
// 	link->to = NULL;
// 	link->flow = 0;
// 	link->capacity = 0;
// 	link->available = 0;
// 	return (link);
// }

void		ft_add_link(t_list **curr, t_list **head, char *str)
{
	char *ret;
	// t_link *link;
	// printf("start add link\n");
	// link = ft_create_link(str);
	// printf("link created\n");
	// printf("name: %s\nx: %d\ny: %d\nid: %d\nvisited: %d\n", room->name, room->x, room->y, room->id, room->visited);
	ret = (char*)malloc(ft_strlen(str) + 1);
	ret = ft_strcpy(ret, str);
	if (*head == NULL)
	{
		*curr = ft_lstnew(ret, ft_strlen(str) + 1);
		*head = *curr;
	}
	else
	{
		(*curr)->next = ft_lstnew(ret, ft_strlen(str) + 1);
		*curr = (*curr)->next;
	}
	free(ret);
}

void		ft_add_start(t_main *data, char *str)
{
	t_room *room;
	room = ft_create_room(str, data);
	data->start = room;
}

void		ft_add_end(t_main *data, char *str)
{
	t_room *room;
	room = ft_create_room(str, data);
	data->end = room;
}

void		ft_handle_input(t_main *data)
{
	char *str;
	t_list *room_head;
	t_list *curr_room;
	t_list *link_head;
	t_list *curr_link;
	int		start;

	room_head = NULL;
	link_head = NULL;
	while(get_next_line(0, &str))
	{
		start = 0;
		if (str[0] == '#' && str[1] != '#')
			;
		else if (!data->ant_amount)
			ft_get_ant_amount(data, str);
		else if (ft_strequ(str, "##start") || ft_strequ(str, "##end"))
		{
			start = ft_strequ(str, "##start") ? 1 : 0;
			// free(str);
			get_next_line(0, &str);
			start == 1 ? ft_add_start(data, str) : ft_add_end(data, str);
		}
		else if (ft_strchr(str, ' '))
			ft_add_room(data, &curr_room, &room_head, str);
		else
			ft_add_link(&curr_link, &link_head, str);
		// free(str);
	}
	printf("input read\n");
	ft_make_graph(room_head, link_head, data);
	printf("graph built\n");

	// while(room_head)
	// {
	// 	printf("%s\n", ((t_room*)room_head->content)->name);
	// 	room_head = room_head->next;
	// }
	// printf("\n\n\n");
	// while(link_head)
	// {
	// 	printf("%s\n", link_head->content);
	// 	link_head = link_head->next;
	// }
	// printf("\n\n\n");
	// printf("%s\n", data->start->name);
	// printf("%s\n", data->end->name);
}
