/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 00:38:52 by hvasylie          #+#    #+#             */
/*   Updated: 2019/08/07 18:38:41 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr		backtracking(t_tetr *head)
{
	t_tetr *tmp;

	tmp = head;
	while (tmp)
	{
		while (collision_check(head, tmp))
			if (move_forward(tmp))
			{
				while (move_forward(tmp))
				{
					if (tmp->num == 0)
					{
						move_left_top(head);
						expand_all(head, tmp->size + 1);
						break ;
					}
					tmp = tmp->back;
				}
				move_left_top(tmp->next);
			}
		tmp = tmp->next;
	}
	return (*head);
}
