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

t_room		*ft_create_room(char *str, int pos)
{
	t_room	*room;
	room = (t_room*)malloc(sizeof(t_room));
	room->info = ft_strsplit(str, ' ');
	room->visited = 0;
	room->pos = pos;
	room->links = NULL;
	return (room);
}

void		ft_add_room(t_main *data, char *str)
{
	t_room *room;

	room = ft_create_room(str, data->pos);
	ft_lstadd(&data->rooms, ft_lstnew(NULL, sizeof(t_room)));
	data->rooms->content = room;
	data->pos = 0;
}

void		ft_add_link(t_main *data, char *str)
{
	// char *ret;

	
	printf("add link [%s]\n", str);
	// ret = (char*)malloc(ft_strlen(str) + 1);
	// ret = ft_strcpy(ret, str);

	ft_lstadd(&data->links, ft_lstnew(str, ft_strlen(str) + 1));
}

void		ft_add_comment(t_main *data, char *str)
{
	// char *ret;
	// ret = (char*)malloc(ft_strlen(str) + 1);
	// ret = ft_strcpy(ret, str);
	printf("add comment [%s]\n", str);
	ft_lstadd(&data->comments, ft_lstnew(str, ft_strlen(str) + 1));
}

void		ft_handle_input(t_main *data)
{
	char	*str;

	while(get_next_line(0, &str))
	{
		printf("str %s\n", str);
		if (str[0] == '#' && str[1] != '#')
			// ;
			ft_lstadd(&data->comments, ft_lstnew(str, ft_strlen(str) + 1));
			// ft_add_comment(data, str);
		else if (!data->ant_amount)
			data->ant_amount = ft_atoi(str);
		else if (ft_strequ(str, "##start"))
			data->pos = ST;
		else if (ft_strequ(str, "##end"))
			data->pos = END;
		else if (ft_strchr(str, ' '))
			ft_add_room(data, str);
		else
			// ft_lstadd(&data->links, ft_lstnew(str, ft_strlen(str) + 1));
			ft_add_link(data, str);
		free(str);
	}

	/*
	** PRINT OUTPUT
	*/
	t_list *rcurr = data->rooms;
	t_list *lcurr = data->links;
	t_list *ccurr = data->comments;
	printf("\n");
	printf("ANTS: %d\n", data->ant_amount);
	// printf("START: [%s]\tEND:[%s]\n", data->start->info[0], data->end->info[0]);
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
	printf("\n");
	printf("COMMENTS\n");
	while(ccurr)
	{
		printf("[%s]\n", ccurr->content);
		ccurr = ccurr->next;
	}

	printf("\n\nEND\n\n");
}
