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
	printf("START:\t%s\n", data->start->name);
	printf("END:\t%s\n", data->end->name);
	printf("\n");
	printf("1\t%s->%s\n", data->start->name, data->start->links[0]->name);
	printf("\n");
	printf("2\t\t%s->%s\n",data->start->links[0]->name, data->start->links[0]->links[0]->name);
	printf("2\t\t%s->%s\n",data->start->links[0]->name, data->start->links[0]->links[1]->name);
	printf("2\t\t%s->%s\n",data->start->links[0]->name, data->start->links[0]->links[2]->name);
	printf("\n");
	printf("3\t\t\t%s->%s\n", data->start->links[0]->links[1]->name, data->start->links[0]->links[1]->links[0]->name);
	printf("3\t\t\t%s->%s\n", data->start->links[0]->links[1]->name, data->start->links[0]->links[1]->links[1]->name);
	printf("3\t\t\t%s->%s\n", data->start->links[0]->links[1]->name, data->start->links[0]->links[1]->links[2]->name);
	printf("3\t\t\t%s->%s\n", data->start->links[0]->links[1]->name, data->start->links[0]->links[1]->links[3]->name);
	printf("\n");
	printf("3\t\t\t%s->%s\n", data->start->links[0]->links[2]->name, data->start->links[0]->links[2]->links[0]->name);
	printf("3\t\t\t%s->%s\n", data->start->links[0]->links[2]->name, data->start->links[0]->links[2]->links[1]->name);
	printf("3\t\t\t%s->%s\n", data->start->links[0]->links[2]->name, data->start->links[0]->links[2]->links[2]->name);	
	printf("\n");
	printf("4\t\t\t\t%s->%s\n", data->start->links[0]->links[2]->links[2]->name, data->start->links[0]->links[2]->links[2]->links[0]->name);	
	printf("4\t\t\t\t%s->%s\n", data->start->links[0]->links[2]->links[2]->name, data->start->links[0]->links[2]->links[2]->links[1]->name);	
	printf("4\t\t\t\t%s->%s\n", data->start->links[0]->links[2]->links[2]->name, data->start->links[0]->links[2]->links[2]->links[2]->name);	
	printf("\n");
	printf("1\t%s->%s\n", data->start->name, data->start->links[1]->name);
	printf("\n");
	printf("2\t\t%s->%s\n",data->start->links[1]->name, data->start->links[1]->links[0]->name);
	printf("2\t\t%s->%s\n",data->start->links[1]->name, data->start->links[1]->links[1]->name);
	printf("2\t\t%s->%s\n",data->start->links[1]->name, data->start->links[1]->links[2]->name);
	printf("2\t\t%s->%s\n",data->start->links[1]->name, data->start->links[1]->links[3]->name);
	printf("\n");
	printf("3\t\t\t%s->%s\n", data->start->links[1]->links[3]->name, data->start->links[1]->links[3]->links[0]->name);
	printf("3\t\t\t%s->%s\n", data->start->links[1]->links[3]->name, data->start->links[1]->links[3]->links[1]->name);
	printf("3\t\t\t%s->%s\n", data->start->links[1]->links[3]->name, data->start->links[1]->links[3]->links[2]->name);	
	printf("\n");
	printf("4\t\t\t\t%s->%s\n", data->start->links[1]->links[3]->links[0]->name, data->start->links[1]->links[3]->links[0]->links[0]->name);	
	printf("4\t\t\t\t%s->%s\n", data->start->links[1]->links[3]->links[0]->name, data->start->links[1]->links[3]->links[0]->links[1]->name);	
	printf("4\t\t\t\t%s->%s\n", data->start->links[1]->links[3]->links[0]->name, data->start->links[1]->links[3]->links[0]->links[2]->name);	
}

int			main(/* int ac, char **av */)
{
	t_main	*data;

	data = ft_init_lem_in();
	printf("init success\n");
	ft_handle_input(data);
	printf("input success\n");
	ft_find_routes(data);
	printf("route success\n");
	return (0);
}