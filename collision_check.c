/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:40:22 by hvasylie          #+#    #+#             */
/*   Updated: 2019/07/25 00:21:54 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		collision_check(t_tetr *head, t_tetr *list)
{
	char	*str;
	char	*str2;
	int		i;

	str2 = list->str;
	while (head != list)
	{
		str = head->str;
		i = 0;
		while (str2[i])
		{
			if (str[i] == '#' && str2[i] == '#')
				return (0);
			i++;
		}
		head = head->next;
	}
	return (1);
}
