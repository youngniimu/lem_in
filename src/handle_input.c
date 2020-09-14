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

void		ft_add_room(t_main *data, char *str)
{
	t_room *room;

	room = ft_create_room(str, data->pos);
	ft_lstaddroom(room, &data->rooms);
	data->pos = 0;
}



void		ft_handle_input(t_main *data)
{
	char	*str;

	while(get_next_line(0, &str))
	{
		printf("str %s\n", str);
		if (str[0] == '#' && str[1] != '#')
			;
		else if (!data->ant_amount)
			data->ant_amount = ft_atoi(str);
		else if (ft_strequ(str, "##start"))
			data->pos = ST;
		else if (ft_strequ(str, "##end"))
			data->pos = END;
		else if (ft_strchr(str, ' '))
			ft_add_room(data, str);
		else
			ft_lstadd(&data->links, ft_lstnew(str, ft_strlen(str) + 1));
		free(str);
	}

	/*
	** PRINT OUTPUT
	*/
	t_list *rcurr = data->rooms;
	t_list *lcurr = data->links;
	// t_list *ccurr = data->comments;
	printf("\n");
	printf("ANTS: %d\n", data->ant_amount);
	printf("\n");
	printf("ROOMS:\n");
	while(rcurr)
	{
		printf("name: [%s]\tpos: [%d]\n", ((t_room*)rcurr->content)->info[0], ((t_room*)rcurr->content)->pos);
		rcurr = rcurr->next;
	}
	printf("\n");
	printf("LINKS:\n");
	while(lcurr)
	{
		printf("[%s]\n", lcurr->content);
		lcurr = lcurr->next;
	}

	printf("\n\nEND HANDLE_INPUT\n\n");
}
