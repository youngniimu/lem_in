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

int			main()
{
	t_main	*data;

	data = ft_init_lem_in();
	ft_handle_input(data);
	ft_make_graph(data);
	ft_find_routes(data);
	return (0);
}