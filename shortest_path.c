/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 20:12:09 by douglas           #+#    #+#             */
/*   Updated: 2017/08/17 14:18:34 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static void	dijkstra(t_ant_hill *hill)
{
	t_priority	*current;
	t_room		*next;
	t_link		*link;

	current = hill->priority_queue;
	if (hill->priority_len <= 0 || current->room->end)
		return ;
	link = current->room->link;
	while (link && link->link_room->visited)
		link = link->next;
	if (!link)
	{
		priority_dequeue(hill);
		dijkstra(hill);
		return ;
	}
	next = link->link_room;
	next->prev = current->room;
	next->visited = 1;
	priority_enqueue(hill, next, current->priority + 1);
	dijkstra(hill);
}

void		get_shortest_path(t_ant_hill *hill)
{
	hill->start->visited = 1;
	priority_enqueue(hill, hill->start, 0);
	dijkstra(hill);
	if (!hill->end->prev)
		ft_error("Could not find a path to end");
}
