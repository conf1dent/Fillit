/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:20:52 by bbekmama          #+#    #+#             */
/*   Updated: 2019/05/22 14:34:29 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_list;

	if (lst && f)
	{
		new_list = (*f)(lst);
		if (lst->next && new_list)
			new_list->next = ft_lstmap(lst->next, f);
		return (new_list);
	}
	return (NULL);
}
