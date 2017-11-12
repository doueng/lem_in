/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:51:04 by dengstra          #+#    #+#             */
/*   Updated: 2017/07/18 13:29:36 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *str)
{
	int strlen;

	if (!str)
		return (0);
	strlen = 0;
	while (*str != '\0')
	{
		++strlen;
		++str;
	}
	return (strlen);
}
