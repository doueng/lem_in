/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 23:25:01 by douglas           #+#    #+#             */
/*   Updated: 2017/07/19 23:25:25 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_chars(char *str, char c)
{
	int count;

	count = 0;
	while (*str)
		count += (*str++ == c) ? 1 : 0;
	return (count);
}
