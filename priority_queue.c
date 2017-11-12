/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority_queue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 19:19:08 by douglas           #+#    #+#             */
/*   Updated: 2017/08/12 17:04:33 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void			priority_enqueue(t_ant_hill *hill, t_room *room, int priority)
{
	t_priority		*queue;
	int				len;

	len = hill->priority_len;
	queue = hill->priority_queue;
	queue[len].room = room;
	queue[len].priority = priority;
	hill->priority_len++;
}

void			priority_dequeue(t_ant_hill *hill)
{
	t_priority	*queue;

	queue = hill->priority_queue;
	if (0 == hill->priority_len--)
		return ;
	ft_memmove(queue, queue + 1, hill->priority_len * sizeof(t_priority));
}
