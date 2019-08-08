/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 17:15:58 by hvasylie          #+#    #+#             */
/*   Updated: 2019/08/07 18:00:12 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_r(t_tetr *tetrimino)
{
	int i;

	i = tetrimino->size - 1;
	while (tetrimino->str[i])
	{
		if (tetrimino->str[i] == '#')
			return (1);
		i += tetrimino->size;
	}
	return (0);
}

int		check_b(t_tetr *tetrimino)
{
	int len;
	int size;

	size = tetrimino->size;
	len = ft_strlen(tetrimino->str) - 1;
	while (size != 0)
	{
		if (tetrimino->str[len] == '#')
			return (1);
		size--;
		len--;
	}
	return (0);
}
