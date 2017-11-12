/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 23:21:10 by douglas           #+#    #+#             */
/*   Updated: 2017/07/19 23:21:50 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup_e(char *src)
{
	char *duped;

	if (!(duped = ft_strdup(src)))
		ft_error("malloc failed strupd");
	return (duped);
}
