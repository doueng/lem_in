/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 19:41:58 by douglas           #+#    #+#             */
/*   Updated: 2017/08/17 14:14:22 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static void	reverse_lst(t_room **begin_list)
{
	t_room *prev;
	t_room *current;
	t_room *next;

	prev = NULL;
	current = (*begin_list);
	while (current)
	{
		next = current->prev;
		current->prev = prev;
		prev = current;
		current = next;
	}
	*begin_list = prev;
}

static void	turn_printer(int ant, t_room *room, t_ant_hill *hill, int last_ant)
{
	if (ant == 0 || !room)
		return ;
	turn_printer(ant - 1, room->prev, hill, last_ant);
	if (ant <= last_ant)
	{
		if (ant > 1 && room->prev)
			ft_putchar(' ');
		ft_printf("L%d-%s", ant, room->name);
	}
	if (room->end)
		hill->num_ants--;
}

void		print_ants(t_ant_hill *hill)
{
	int		ant;
	int		last_ant;
	t_room	*room;

	reverse_lst(&hill->end);
	hill->start = hill->start->prev;
	ant = 1;
	last_ant = hill->num_ants;
	while (hill->num_ants)
	{
		room = hill->start;
		turn_printer(ant, room, hill, last_ant);
		ft_putstr("\n");
		ant++;
	}
}

void		print_input(t_list *line)
{
	t_list *tmp;

	while (line)
	{
		ft_printf("%s\n", line->content);
		tmp = line->next;
		free(line->content);
		free(line);
		line = tmp;
	}
	ft_putstr("\n");
}
