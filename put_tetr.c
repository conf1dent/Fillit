/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tetr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 23:00:08 by hvasylie          #+#    #+#             */
/*   Updated: 2019/08/05 23:04:46 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		put_tetr(t_tetr *head)
{
	int i;

	while (head != NULL)
	{
		i = 0;
		while ((head->str[i]))
		{
			if (head->str[i] == '#')
				head->str[i] = 'A' + head->num;
			i++;
		}
		head = head->next;
	}
}

static void		fill_haed(t_tetr *head)
{
	t_tetr *tmp;
	int i;

	tmp = head->next;
	put_tetr(head);
	while (tmp != NULL)
	{
		i = 0;
		while ((tmp->str[i]))
		{
			if (tmp->str[i] != '.')
				head->str[i] = tmp->str[i];
			i++;
		}
		tmp = tmp->next;
	}
}
