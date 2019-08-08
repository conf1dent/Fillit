/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 21:05:38 by hvasylie          #+#    #+#             */
/*   Updated: 2019/08/07 20:29:47 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define STR tetrimino->str

static int		tetrimino_count(t_tetr *tetrimino)
{
	int i;

	i = 0;
	while (tetrimino != NULL)
	{
		tetrimino = tetrimino->next;
		i++;
	}
	return (i);
}

int				get_size(t_tetr *tetrimino)
{
	int size;
	int len;

	size = 2;
	len = tetrimino_count(tetrimino);
	while ((size * size) < (len * 4))
	{
		size++;
	}
	if (size < 4)
	{
		if (size == 3)
		{
			while (tetrimino != NULL)
			{
				if (check_b(tetrimino) || check_r(tetrimino))
					return (4);
				tetrimino = tetrimino->next;
			}
		}
		else if (len == 1 && check_of_2(tetrimino) == 8)
			return (2);
	}
	return (size);
}
