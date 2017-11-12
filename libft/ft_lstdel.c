/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douglas <douglas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:11:08 by dengstra          #+#    #+#             */
/*   Updated: 2017/07/19 19:17:14 by douglas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list *alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	while (alst)
	{
		tmp = alst->next;
		del(alst->content, alst->content_size);
		free(alst);
		alst = tmp;
	}
}
