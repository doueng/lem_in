/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_e.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 23:21:56 by douglas           #+#    #+#             */
/*   Updated: 2017/07/19 23:22:17 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit_e(char *src, char c)
{
	char **split;

	if (!(split = ft_strsplit(src, c)))
		ft_error("malloc failed split");
	return (split);
}
