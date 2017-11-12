/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree_e.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 23:22:21 by douglas           #+#    #+#             */
/*   Updated: 2017/07/19 23:22:44 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinfree_e(int free_a, char *a, int free_b, char *b)
{
	char *joined;

	if (!(joined = ft_strjoinfree(free_a, a, free_b, b)))
		ft_error("malloc failed join free");
	return (joined);
}
