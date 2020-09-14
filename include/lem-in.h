/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 10:05:26 by thalme            #+#    #+#             */
/*   Updated: 2020/09/08 10:05:26 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define ST 1
# define END 2

# include "../libprintf/include/ft_printf.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_link
{
	struct t_room	*from;
	struct t_room	*to;
	int				flow;
	int				capacity;
	int				available;
}					t_link;

typedef struct		s_room
{
	char			**info;
	int				pos;
	int				visited;
	t_list			*links;
	t_list		*curr_link;
}					t_room;

typedef struct		s_main
{
	t_list			*rooms;
	t_list			*links;
	t_list			*queue;
	t_room			*start;
	t_room			*end;
	int				reach_end;
	int				ant_amount;
	int				pos;
}					t_main;

t_main			*ft_init_lem_in();
void			ft_handle_input(t_main *data);
void			ft_make_graph(t_main *data);
void			ft_find_routes(t_main *data);

#endif