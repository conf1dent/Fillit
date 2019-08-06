/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_size_in_tetr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:07:51 by hvasylie          #+#    #+#             */
/*   Updated: 2019/08/05 18:09:01 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		put_size_in_tetr(t_tetr *head, int size)
{
	while (head)
	{
		head->size = size;
		head = head->next;
	}
}
