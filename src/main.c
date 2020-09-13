/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 10:05:03 by thalme            #+#    #+#             */
/*   Updated: 2020/09/08 10:05:03 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem-in.h"

void		print_grid(t_main *data)
{
	printf("==== PRINT GRID ========\n");
	printf("START: [ %s ]\tEND: [ %s ]\n", data->start->info[0], data->end->info[0]);
	printf("link [ %s ] has %d links: ", data->start->info[0], ft_lstlen(data->start->links));
	data->start->curr_link = data->start->links;
	// printf("->[ %s ] and ->[ %s ]", ((t_room*)data->start->links->content)->info[0], ((t_room*)data->start->links->next->content)->info[0]);
	while (data->start->curr_link)
	{
		printf("->[ %s ] ", ((t_room*)data->start->curr_link->content)->info[0]);
		data->start->curr_link = data->start->curr_link->next;
	}
	// printf("\n");
	// printf("1\t%s->%s\n", data->start->info[0], data->start->links[0]->info[0]);

	// printf("END:\t%s\n", data->end->info[0]);
	// printf("\n");
	// while(1);
	// printf("\n");
	// printf("2\t\t%s->%s\n",data->start->links[0]->info[0], data->start->links[0]->links[0]->info[0]);
	// printf("2\t\t%s->%s\n",data->start->links[0]->info[0], data->start->links[0]->links[1]->info[0]);
	// printf("2\t\t%s->%s\n",data->start->links[0]->info[0], data->start->links[0]->links[2]->info[0]);
	// printf("\n");
	// printf("3\t\t\t%s->%s\n", data->start->links[0]->links[1]->info[0], data->start->links[0]->links[1]->links[0]->info[0]);
	// printf("3\t\t\t%s->%s\n", data->start->links[0]->links[1]->info[0], data->start->links[0]->links[1]->links[1]->info[0]);
	// printf("3\t\t\t%s->%s\n", data->start->links[0]->links[1]->info[0], data->start->links[0]->links[1]->links[2]->info[0]);
	// printf("3\t\t\t%s->%s\n", data->start->links[0]->links[1]->info[0], data->start->links[0]->links[1]->links[3]->info[0]);
	// printf("\n");
	// printf("3\t\t\t%s->%s\n", data->start->links[0]->links[2]->info[0], data->start->links[0]->links[2]->links[0]->info[0]);
	// printf("3\t\t\t%s->%s\n", data->start->links[0]->links[2]->info[0], data->start->links[0]->links[2]->links[1]->info[0]);
	// printf("3\t\t\t%s->%s\n", data->start->links[0]->links[2]->info[0], data->start->links[0]->links[2]->links[2]->info[0]);	
	// printf("\n");
	// printf("4\t\t\t\t%s->%s\n", data->start->links[0]->links[2]->links[2]->info[0], data->start->links[0]->links[2]->links[2]->links[0]->info[0]);	
	// printf("4\t\t\t\t%s->%s\n", data->start->links[0]->links[2]->links[2]->info[0], data->start->links[0]->links[2]->links[2]->links[1]->info[0]);	
	// printf("4\t\t\t\t%s->%s\n", data->start->links[0]->links[2]->links[2]->info[0], data->start->links[0]->links[2]->links[2]->links[2]->info[0]);	
	// printf("\n");
	// printf("1\t%s->%s\n", data->start->info[0], data->start->links[1]->info[0]);
	// printf("\n");
	// printf("2\t\t%s->%s\n",data->start->links[1]->info[0], data->start->links[1]->links[0]->info[0]);
	// printf("2\t\t%s->%s\n",data->start->links[1]->info[0], data->start->links[1]->links[1]->info[0]);
	// printf("2\t\t%s->%s\n",data->start->links[1]->info[0], data->start->links[1]->links[2]->info[0]);
	// printf("2\t\t%s->%s\n",data->start->links[1]->info[0], data->start->links[1]->links[3]->info[0]);
	// printf("\n");
	// printf("3\t\t\t%s->%s\n", data->start->links[1]->links[3]->info[0], data->start->links[1]->links[3]->links[0]->info[0]);
	// printf("3\t\t\t%s->%s\n", data->start->links[1]->links[3]->info[0], data->start->links[1]->links[3]->links[1]->info[0]);
	// printf("3\t\t\t%s->%s\n", data->start->links[1]->links[3]->info[0], data->start->links[1]->links[3]->links[2]->info[0]);	
	// printf("\n");
	// printf("4\t\t\t\t%s->%s\n", data->start->links[1]->links[3]->links[0]->info[0], data->start->links[1]->links[3]->links[0]->links[0]->info[0]);	
	// printf("4\t\t\t\t%s->%s\n", data->start->links[1]->links[3]->links[0]->info[0], data->start->links[1]->links[3]->links[0]->links[1]->info[0]);	
	// printf("4\t\t\t\t%s->%s\n", data->start->links[1]->links[3]->links[0]->info[0], data->start->links[1]->links[3]->links[0]->links[2]->info[0]);	
}

int			main()
{
	t_main	*data;

	data = ft_init_lem_in();
	ft_handle_input(data);
	ft_make_graph(data);
	// print_grid(data);
	ft_find_routes(data);
	return (0);
}