/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 10:33:22 by thalme            #+#    #+#             */
/*   Updated: 2020/09/08 10:33:22 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem-in.h"

t_main		*ft_init_lem_in()
{
	t_main *data;

	data = (t_main*)malloc(sizeof(t_main));
	data->start = NULL;
	data->end = NULL;
	data->ant_amount = 0;
	data->room_index = 0;
	data->reach_end = 0;
	// data->route = NULL;
	return (data);
}