/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 18:21:13 by douglas           #+#    #+#             */
/*   Updated: 2017/08/17 14:44:26 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H

# include "libft/libft.h"

typedef struct		s_room
{
	char			*name;
	char			*x;
	char			*y;
	int				visited;
	int				start;
	int				end;
	int				priority;
	int				ant;
	struct s_link	*link;
	struct s_room	*next;
	struct s_room	*prev;
}					t_room;

typedef struct		s_link
{
	struct s_link	*next;
	t_room			*link_room;
}					t_link;

typedef struct		s_priority
{
	t_room			*room;
	int				priority;
}					t_priority;

typedef struct		s_ant_hill
{
	t_room			*start;
	t_room			*end;
	t_room			*first;
	t_priority		*priority_queue;
	int				priority_len;
	int				num_rooms;
	int				num_ants;
}					t_ant_hill;

t_room				*create_room(void);
t_link				*create_link(t_room *link_room, t_link *next);
t_ant_hill			*create_ant_hill(void);
void				parse_input(t_ant_hill *hill, t_list *first_line);
void				ft_error(char *message);
void				priority_dequeue(t_ant_hill *hill);
void				priority_enqueue(t_ant_hill *hill,
								t_room *room, int priority);
void				get_shortest_path(t_ant_hill *hill);
void				print_ants(t_ant_hill *hill);
void				print_input(t_list *line);
t_list				*check_input(t_list *input, t_ant_hill *hill);
int					is_comment(t_list *input);
int					is_start_end(t_list *input);
t_list				*get_input(void);
int					check_invalid_cmd(char *line);
void				check_duplicate_coords(t_room *room, char *x, char *y);
void				check_duplicate_room(t_room *room, char *name);
void				check_link(t_room *curr_room, t_room *link_room);
int					contains_link(t_link *link, char *name);

#endif
