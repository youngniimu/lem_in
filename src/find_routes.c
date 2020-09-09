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
	printf("[%s]->", curr->info[0]);	
	if (ft_strequ(curr->info[0], ((t_room*)data->end)->info[0]))
	{
		data->reach_end = 1;
		printf("END");
		return (data->reach_end);
	}
	if (!curr->links[index]->visited)
	{
		printf("[%s]->", curr->info[0]);
		// printf("go to next %s\n", curr->links[index]->info[0]);
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
	// int routes_found = 0;
	// int i = 20;
	printf("START FINDING\n");
	
	find_route(curr, data, 0);
	// while (i--)
	// {
	// 	find_route(curr, data, 0);
	// 	routes_found += data->reach_end;
	// 	data->reach_end = 0;
	// 	printf("\n\n");
	// }
	// printf("%d routes found!!\n", routes_found);
}