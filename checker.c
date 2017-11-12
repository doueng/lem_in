/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 16:49:43 by douglas           #+#    #+#             */
/*   Updated: 2017/08/17 15:41:55 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int			contains_link(t_link *link, char *name)
{
	while (link)
	{
		if (ft_strequ(link->link_room->name, name))
			return (1);
		link = link->next;
	}
	return (0);
}

void		check_link(t_room *curr_room, t_room *link_room)
{
	if (!curr_room || !link_room)
		ft_error("Could not find link to room");
}

void		check_duplicate_room(t_room *room, char *name)
{
	while (room)
	{
		if (ft_strequ(room->name, name))
			ft_error("Duplicate room name");
		room = room->next;
	}
}

void		check_duplicate_coords(t_room *room, char *x, char *y)
{
	while (room)
	{
		if (ft_strequ(room->x, x) && ft_strequ(room->y, y))
			ft_error("Duplicate room coords");
		room = room->next;
	}
}

int			check_invalid_cmd(char *line)
{
	if (!line)
		return (0);
	return (line[0] == '#' && line[1] == '#' && line[2] != '#'
		&& ft_strcmp(line, "##start") && ft_strcmp(line, "##end"));
}
