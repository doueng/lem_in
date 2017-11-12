/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 23:26:16 by douglas           #+#    #+#             */
/*   Updated: 2017/07/19 23:26:42 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc_e(size_t size)
{
	void	*mem;

	if (!(mem = malloc(size)))
		ft_error("malloc failed");
	return (mem);
}
