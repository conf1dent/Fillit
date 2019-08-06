/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 21:05:38 by hvasylie          #+#    #+#             */
/*   Updated: 2019/08/05 23:23:23 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	tetrimino_count(t_tetr *tetrimino)
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

int			get_size(t_tetr *tetrimino)
{
	int size;
	int len;

	size = 2; // !!!need to correct!!!
	len = tetrimino_count(tetrimino);
	while ((size * size) < (len * 4))
	{
		size++;
	}
	return (size);
}
