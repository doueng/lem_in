/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:40:19 by dengstra          #+#    #+#             */
/*   Updated: 2017/07/16 13:37:04 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	char	*tmp;
	int		len;

	if (!src)
		return (ft_strnew(0));
	len = ft_strlen(src);
	if (!(str = (char*)ft_strnew(len)))
		return (NULL);
	tmp = str;
	while (len--)
		*tmp++ = *src++;
	return (str);
}
