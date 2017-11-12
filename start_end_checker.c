/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_end_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 19:22:16 by dengstra          #+#    #+#             */
/*   Updated: 2017/08/15 19:30:22 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int				is_start_end(t_list *input)
{
	return (ft_strequ(input->content, "##start")
			|| ft_strequ(input->content, "##end"));
}

int				start_end_checker(char *line, int *start_end, t_ant_hill *hill)
{
	if (ft_strequ(line, "##start"))
	{
		if (hill->start)
			ft_error("Can only have one start room");
		else
			start_end[0] = 1;
		return (1);
	}
	else
		start_end[0] = 0;
	if (ft_strequ(line, "##end"))
	{
		if (hill->end)
			ft_error("Can only have one end room");
		else
			start_end[1] = (1);
		return (1);
	}
	else
		start_end[1] = 0;
	return (0);
}
