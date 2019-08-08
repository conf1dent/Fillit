/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:21:22 by hvasylie          #+#    #+#             */
/*   Updated: 2019/08/07 21:23:21 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_left(t_tetr *tetrimino)
{
	int i;
	int size;

	size = tetrimino->size * tetrimino->size;
	i = 0;
	while (i < size)
	{
		if (tetrimino->str[i] == '#')
			return (1);
		i += tetrimino->size;
	}
	return (0);
}

static int		check_top(t_tetr *tetrimino)
{
	int i;

	i = 0;
	while (i < tetrimino->size)
	{
		if (tetrimino->str[i] == '#')
			return (1);
		i++;
	}
	return (0);
}

int				move_left(t_tetr *tetrimino)
{
	int		len;
	int		i;
	char	*str;

	i = 0;
	len = ft_strlen(tetrimino->str);
	str = tetrimino->str;
	if (check_left(tetrimino) && check_top(tetrimino))
		return (1);
	if (check_left(tetrimino))
		while (i < len)
		{
			if (tetrimino->str[i] == '#')
				ft_swap_char(&str[i], &str[i - tetrimino->size]);
			i++;
		}
	else
		while (len > i)
		{
			if (tetrimino->str[i] == '#')
				ft_swap_char(&tetrimino->str[i], &tetrimino->str[i - 1]);
			i++;
		}
	return (0);
}

void			move_left_top(t_tetr *head)
{
	while (head)
	{
		while (!move_left(head))
			;
		head = head->next;
	}
}
