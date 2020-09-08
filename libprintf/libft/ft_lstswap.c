/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 16:09:25 by thalme            #+#    #+#             */
/*   Updated: 2020/08/13 16:09:25 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstswap(t_list *alst1, t_list *alst2)
{
	void	*c_content;
	size_t	c_content_size;

	if (!alst1 || !alst2)
		return ;
	c_content = alst1->content;
	c_content_size = alst1->content_size;
	alst1->content = alst2->content;
	alst1->content_size = alst2->content_size;
	alst2->content = c_content;
	alst2->content_size = c_content_size;
}
