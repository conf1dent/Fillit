/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <bbekmama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:37:02 by bbekmama          #+#    #+#             */
/*   Updated: 2019/07/24 16:13:58 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print(t_tetr *head)
{
	int line;
	int i;

	line = 0;
	while (head != NULL)
	{
		i = 0;
		while ((head->str[i]))
		{
			ft_putchar(head->str[i]);
			if (i % 4 == 3)
				ft_putstr("\n");
			i++;
		}
		ft_putstr("\n");
		head = head->next;
	}
}
