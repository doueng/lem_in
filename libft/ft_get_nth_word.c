/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nth_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 14:40:22 by douglas           #+#    #+#             */
/*   Updated: 2017/07/15 15:14:13 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*skip_whitespace(char *str)
{
	while (*str && !ft_isalnum(*str))
		str++;
	return (str);
}

static char	*skip_alnum(char *str)
{
	while (*str && ft_isalnum(*str))
		str++;
	return (str);
}

char		*ft_get_nth_word(char *str, int count)
{
	str = skip_whitespace(str);
	while (*str)
	{
		str = skip_whitespace(str);
		if (count-- == 0)
			return (str);
		str = skip_alnum(str);
	}
	return (str);
}
