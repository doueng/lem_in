/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp_till.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 23:31:09 by douglas           #+#    #+#             */
/*   Updated: 2017/08/02 14:59:41 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_cmp_till(char *a, char *b, char till)
{
	while (*a && *b && *a != till && *b != till)
	{
		if (*a++ != *b++)
			return (0);
	}
	return ((*a == '\0' || *a == till)
			&& (*b == '\0' || *b == till));
}
