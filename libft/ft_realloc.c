/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 20:32:44 by douglas           #+#    #+#             */
/*   Updated: 2017/07/15 20:40:13 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *old, size_t size)
{
	unsigned char	*new;
	void			*old_start;

	if (!old)
		return (ft_strnew(size));
	old = (unsigned char*)old;
	new = (unsigned char*)ft_strnew(size);
	while (size--)
		*new++ = *old++;
	return ((void*)new);
}
