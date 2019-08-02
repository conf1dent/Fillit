/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right_bottom.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 19:44:56 by hvasylie          #+#    #+#             */
/*   Updated: 2019/08/01 22:26:59 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		get_width(t_tetr *tetrimino)
{
	int	i;
	int	len;
	int	size;

	len = ft_strlen(tetrimino->str) - 1;
	i = 0; //we will need to input size through the struct (4 in basic case)
	while (i < tetrimino->size)
	{
		size = tetrimino->size;
		while (size != 0)
		{
			if (tetrimino->str[i] == '#')
				return (1);
			i += tetrimino->size;
			size--;
		}
		i++;
	}
	return (0);
}

static int		check_right(t_tetr *tetrimino)
{
	int i;

	i = tetrimino->size - 1; //we will need to input size through the struct (4 in basic case)
	while (tetrimino->str[i])
	{
		if (tetrimino->str[i] == '#')
			return (1);
		i += tetrimino->size;
	}
	return (0);
}

static int		check_botom(t_tetr *tetrimino)
{
	int len;
	int size;

	size = tetrimino->size; // we'll need to pass input size through the struct (4 in basic case)
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

int				move_right_bottom(t_tetr *tetrimino)
{
	int		width;
	int		len;

	len = ft_strlen(tetrimino->str) - 1;
	width = get_width(tetrimino);
	if (check_right(tetrimino) && check_botom(tetrimino))
		return (1);
	if (check_right(tetrimino))
		while (len >= 0)
		{
			if (tetrimino->str[len] == '#')
				ft_swap(tetrimino->str[len], tetrimino->str[len + width]);
			len--;
		}
	else
		while (len >= 0)
		{
			if (tetrimino->str[len] == '#')
				ft_swap(tetrimino->str[len], tetrimino->str[len + 1]);
			len--;
		}
	return (0);
}
