/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelfind.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 23:34:20 by douglas           #+#    #+#             */
/*   Updated: 2017/07/16 00:01:33 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdelfind(t_list *alst, void (*del)(void*, size_t),
							int (*cmp)(void*, void*), void *item)
{
	t_list *tmp;

	if (!alst)
		return (NULL);
	if (cmp(alst->content, item) == 0)
	{
		tmp = alst->next;
		ft_lstdelone(&alst, del);
		alst = tmp;
		return (tmp);
	}
	alst->next = ft_lstdelfind(alst->next, del, cmp, item);
	return (alst);
}
