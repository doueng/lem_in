/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 13:54:41 by douglas           #+#    #+#             */
/*   Updated: 2017/08/17 15:42:07 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int				is_comment(t_list *input)
{
	char *line;

	line = (char*)input->content;
	return (line[0] == '#' && !ft_strequ(line, "##start")
						&& !ft_strequ(line, "##end"));
}

int				is_start_end(t_list *input)
{
	return (ft_strequ(input->content, "##start")
			|| ft_strequ(input->content, "##end"));
}

static int		valid_room(t_list *input)
{
	input = input->next;
	while (input->next && (is_comment(input)))
		input = input->next;
	if (!ft_strchr(input->content, ' '))
		ft_error("There needs to be a room after ##start and ##end");
	return (1);
}

static void		check_start_end(t_list *input)
{
	int starts;
	int ends;

	starts = 0;
	ends = 0;
	while (input->next)
	{
		if (ft_strequ("##start", input->content))
			starts += valid_room(input);
		if (ft_strequ("##end", input->content))
			ends += valid_room(input);
		input = input->next;
		if (ft_strchr(input->content, '-'))
			break ;
	}
	if (starts != 1 || ends != 1)
		ft_error("There needs to be one start room and one end room");
}

t_list			*check_input(t_list *input, t_ant_hill *hill)
{
	while (is_comment(input))
		input = input->next;
	if (ft_is_int(input->content))
		hill->num_ants = ft_atoi(input->content);
	else
		ft_error("The number of ants has to be an int");
	if (hill->num_ants < 1)
		ft_error("There needs to be at least 1 ant");
	check_start_end(input);
	return (input);
}
