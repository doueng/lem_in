/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdivider.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 13:45:06 by douglas           #+#    #+#             */
/*   Updated: 2017/11/12 17:16:06 by dengstra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strcpytill(char *str, char c)
{
	int		len;
	char	*result;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	result = ft_strnew_e(len);
	ft_strncpy(result, str, len);
	return (result);
}

static int	count_char(char *line, char c)
{
	int count;

	count = 0;
	while (*line)
	{
		if (*line == c)
			count++;
		line++;
	}
	return (count);
}

static void	cpy_to_split(char **split, char *line, char c, int split_len)
{
	int i;

	i = 0;
	while (line && i < split_len)
	{
		split[i++] = strcpytill(line, c);
		line = ft_strchr(line, c);
		line++;
	}
}

char		**ft_strdivider(char *line, char c)
{
	int		count;
	char	**split;

	count = count_char(line, c);
	if (!(split = (char**)ft_memalloc((count + 2) * sizeof(split))))
		return (NULL);
	cpy_to_split(split, line, c, count + 1);
	return (split);
}
