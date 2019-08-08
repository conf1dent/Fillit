/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 19:44:56 by hvasylie          #+#    #+#             */
/*   Updated: 2019/08/06 00:02:17 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		get_width(t_tetr *tetrimino)
{
	int	i;
	int	size;
	int width;
	int index;

	width = 0;
	i = 0;
	while (i < tetrimino->size)
	{
		size = tetrimino->size;
		index = i;
		while (size != 0)
		{
			if (tetrimino->str[index] == '#')
			{
				width++;
				break ;
			}
			index += tetrimino->size;
			size--;
		}
		i++;
	}
	return (width);
}

static int		check_right(t_tetr *tetrimino)
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

static int		check_botom(t_tetr *tetrimino)
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

int				move_forward(t_tetr *tetrimino)
{
	int		width;
	int		len;
	char	*str;

	len = ft_strlen(tetrimino->str) - 1;
	width = get_width(tetrimino);
	str = tetrimino->str;
	if (check_right(tetrimino) && check_botom(tetrimino))
		return (1);
	if (check_right(tetrimino))
		while (len >= 0)
		{
			if (tetrimino->str[len] == '#')
				ft_swap_char(&str[len], &str[len + width]);
			len--;
		}
	else
		while (len >= 0)
		{
			if (tetrimino->str[len] == '#')
				ft_swap_char(&tetrimino->str[len], &tetrimino->str[len + 1]);
			len--;
		}
	return (0);
}
