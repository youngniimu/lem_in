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

int		find_route(t_room *curr, t_main *data, int index)
{
	// printf("\n\ncurrent room is %s\n", curr->name);
	if (ft_strequ(curr->name, ((t_room*)data->end)->name))
	{
		data->reach_end = 1;
		return (data->reach_end);
	}
	if (!curr->links[index]->visited)
	{
		// printf("go to next %s\n", curr->links[index]->name);
		curr->visited = 1;
		find_route(curr->links[index], data, 0);
	}
	else if (curr->links[index + 1])
	{
		// printf("try next at index %d\n", index);
		find_route(curr, data, index + 1);
	}
	return (data->reach_end);
}

void		ft_find_routes(t_main *data)
{
	t_room	*curr;
	curr = data->start;
	int routes_found = 0;
	
	while (find_route(curr, data, 0))
	{
		data->reach_end = 0;
		routes_found++;
	}
	printf("%d routes found!!\n", routes_found);
}