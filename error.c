/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 20:57:35 by douglas           #+#    #+#             */
/*   Updated: 2017/08/01 15:56:04 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	ft_error(char *message)
{
	ft_putstr(RED_COLOR);
	ft_printf("ERROR: %s\n", message);
	ft_putstr(NORMAL_COLOR);
	exit(-1);
}
