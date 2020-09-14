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

void		ft_lstaddroom(t_room *content, t_list **list)
{
	ft_lstadd(list, ft_lstnew(NULL, sizeof(t_room)));
	(*list)->content = content;
}