/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 20:51:09 by douglas           #+#    #+#             */
/*   Updated: 2017/11/12 17:15:23 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static void		add_start_end(t_ant_hill *hill, t_room *curr_room,
								int *start_end)
{
	if (start_end[0] && !hill->start)
	{
		curr_room->start = 1;
		hill->start = curr_room;
	}
	if (start_end[1] && !hill->end)
	{
		curr_room->end = 1;
		hill->end = curr_room;
	}
}

static t_room	*add_room(t_ant_hill *hill, t_room *room, char *line,
							int *start_end)
{
	t_room	*new_room;
	int		split_len;
	char	**split;

	if (!(split = ft_strdivider(line, ' ')))
		ft_error("strdivider failed");
	split_len = ft_split_len(split);
	if (split_len != 3 || !ft_is_int(split[1]) || !ft_is_int(split[2]))
		ft_error("Room is wrongly formatted, name x y");
	if (split[0][0] == 'L')
		ft_error("Room cannot start with the letter L");
	check_duplicate_room(room, split[0]);
	check_duplicate_coords(room, split[1], split[2]);
	new_room = create_room();
	new_room->name = ft_strdup_e(split[0]);
	new_room->x = ft_strdup_e(split[1]);
	new_room->y = ft_strdup_e(split[2]);
	new_room->next = room;
	hill->first = new_room;
	add_start_end(hill, new_room, start_end);
	hill->num_rooms++;
	ft_free_split(split);
	return (new_room);
}

static void		add_link(t_room *room, char *buffer)
{
	char	**split;
	t_link	*link;
	t_room	*link_room;
	t_room	*curr_room;

	if (!(split = ft_strdivider(buffer, '-')))
		ft_error("strdivider failed");
	if (ft_split_len(split) != 2 || ft_strequ(split[0], split[1]))
		ft_error("Room links to itself");
	link_room = NULL;
	curr_room = NULL;
	while (room)
	{
		if (ft_strequ(split[0], room->name))
			curr_room = room;
		if (ft_strequ(split[1], room->name))
			link_room = room;
		room = room->next;
	}
	check_link(curr_room, link_room);
	ft_free_split(split);
	link = create_link(link_room, curr_room->link);
	curr_room->link = link;
	if (!contains_link(link_room->link, curr_room->name))
		link_room->link = create_link(curr_room, link_room->link);
}

t_list			*get_input(void)
{
	t_list	*first_line;
	char	*buffer;

	first_line = NULL;
	while (0 < get_next_line(0, &buffer))
	{
		if (!check_invalid_cmd(buffer))
			ft_lstadd_rev(&first_line, ft_lstnew(buffer,
				ft_strlen(buffer) + 1));
		free(buffer);
	}
	free(buffer);
	if (!first_line)
		ft_error("Empty input");
	return (first_line);
}

void			parse_input(t_ant_hill *hill, t_list *first_line)
{
	t_list	*current;
	char	*line;
	t_room	*curr_room;
	int		start_end[2];

	start_end[0] = 0;
	start_end[1] = 0;
	current = check_input(first_line, hill);
	curr_room = NULL;
	while (current->next)
	{
		current = current->next;
		line = (char*)current->content;
		if (is_comment(current))
			continue ;
		else if (is_start_end(current))
		{
			start_end[0] = (ft_strequ(line, "##start")) ? 1 : 0;
			start_end[1] = (ft_strequ(line, "##end")) ? 1 : 0;
		}
		else if (!ft_strchr(line, '-'))
			curr_room = add_room(hill, curr_room, line, start_end);
		else if (ft_strchr(line, '-'))
			add_link(curr_room, line);
	}
}
