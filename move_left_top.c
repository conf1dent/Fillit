/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:21:22 by hvasylie          #+#    #+#             */
/*   Updated: 2019/08/01 18:00:11 by hvasylie         ###   ########.fr       */
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
	while(i < tetrimino->size)
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

static int		check_left(t_tetr *tetrimino)
{
	int i;

	i = tetrimino->size + 1 - tetrimino->size; //we will need to input size through the struct (4 in basic case)
	while (tetrimino->str[i])
	{
		if (tetrimino->str[i] == '#')
			return (1);
		i += tetrimino->size;
	}
	return (0);
}

static int		check_top(t_tetr *tetrimino)
{
	int len;
	int size;

	size = tetrimino->size; // we'll need to pass input size through the struct (4 in basic case)
	len = 0;
	while(len < size) // because size starts from 1, len from 0
	{
		if (tetrimino->str[len] == '#')
			return (1);
		len++;
	}
	return (0);
}

int				move_left(t_tetr *tetrimino)
{
	int		width;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(tetrimino->str);
	width = get_width(tetrimino);
	if (check_left(tetrimino) && check_top(tetrimino))
		return (1);
	if (check_left(tetrimino))
		while (i < len)
		{
			if (tetrimino->str[i] == '#')
				ft_swap(tetrimino->str[i], tetrimino->str[i - width]);
			i++;
		}
	else
		while (len > i)
		{
			if (tetrimino->str[i] == '#')
				ft_swap(tetrimino->str[i], tetrimino->str[i - 1]);
			i++;
		}
	return (0);
}
