/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:37:02 by bbekmama          #+#    #+#             */
/*   Updated: 2019/08/07 22:08:04 by hvasylie         ###   ########.fr       */
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
	t_tetr	*tmp;
	int		i;

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

void			ft_print(t_tetr *head)
{
	int i;

	i = 0;
	fill_haed(head);
	while ((head->str[i]))
	{
		ft_putchar(head->str[i]);
		if (i % head->size == head->size - 1)
			ft_putstr("\n");
		i++;
	}
}
