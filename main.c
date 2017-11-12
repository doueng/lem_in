/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 18:15:48 by douglas           #+#    #+#             */
/*   Updated: 2017/08/17 14:17:51 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static void	free_rooms(t_room *room)
{
	t_room	*tmp;
	t_link	*lnk;
	t_link	*tmp_lnk;

	while (room)
	{
		tmp = room->next;
		lnk = room->link;
		while (lnk)
		{
			tmp_lnk = lnk->next;
			free(lnk);
			lnk = tmp_lnk;
		}
		free(room->name);
		free(room->x);
		free(room->y);
		free(room);
		room = tmp;
	}
}

int			main(int argc, char *argv[])
{
	t_ant_hill	*hill;
	t_list		*first_line;

	(void)argv;
	if (argc > 1)
		return (ft_printf("Usage: ./lem-in < map\n"));
	hill = create_ant_hill();
	first_line = get_input();
	parse_input(hill, first_line);
	hill->priority_queue = (t_priority*)
			ft_malloc_e(sizeof(t_priority) * (hill->num_rooms + 1));
	get_shortest_path(hill);
	print_input(first_line);
	print_ants(hill);
	free_rooms(hill->first);
	free(hill->priority_queue);
	free(hill);
	return (0);
}
