/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 20:42:06 by douglas           #+#    #+#             */
/*   Updated: 2017/08/16 14:12:22 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

t_room		*create_room(void)
{
	t_room	*room;

	room = (t_room*)ft_malloc_e(sizeof(t_room));
	room->name = NULL;
	room->x = NULL;
	room->y = NULL;
	room->visited = 0;
	room->end = 0;
	room->start = 0;
	room->ant = 0;
	room->link = NULL;
	room->next = NULL;
	room->priority = 0;
	room->prev = NULL;
	return (room);
}

t_link		*create_link(t_room *link_room, t_link *next)
{
	t_link	*link;

	link = (t_link*)ft_malloc_e(sizeof(t_link));
	link->link_room = link_room;
	link->next = next;
	return (link);
}

t_ant_hill	*create_ant_hill(void)
{
	t_ant_hill *hill;

	hill = (t_ant_hill*)ft_malloc_e(sizeof(t_ant_hill));
	hill->start = NULL;
	hill->end = NULL;
	hill->priority_len = 0;
	hill->num_rooms = 0;
	hill->num_ants = 0;
	hill->first = NULL;
	return (hill);
}
