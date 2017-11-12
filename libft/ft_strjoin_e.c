/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_e.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 23:20:22 by douglas           #+#    #+#             */
/*   Updated: 2017/07/19 23:21:06 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_e(char *a, char *b)
{
	char *joined;

	if (!(joined = ft_strjoin(a, b)))
		ft_error("malloc failed join e");
	return (joined);
}
