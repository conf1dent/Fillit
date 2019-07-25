/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 00:02:33 by bbekmama          #+#    #+#             */
/*   Updated: 2019/05/23 13:27:57 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *lnext;

	if (alst != NULL)
	{
		tmp = *alst;
		lnext = *alst;
		while (tmp != NULL)
		{
			(*del)(tmp->content, tmp->content_size);
			tmp = lnext->next;
			free(lnext);
			lnext = tmp;
		}
		*alst = NULL;
	}
}
