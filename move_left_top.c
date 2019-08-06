/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:21:22 by hvasylie          #+#    #+#             */
/*   Updated: 2019/08/05 22:43:27 by hvasylie         ###   ########.fr       */
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

	i = 0;
	len = ft_strlen(tetrimino->str);
	if (check_left(tetrimino) && check_top(tetrimino))
		return (1);
	if (check_left(tetrimino))
		while (i < len)
		{
			if (tetrimino->str[i] == '#')
				ft_swap_char(&tetrimino->str[i], &tetrimino->str[i - tetrimino->size]);
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

void		move_left_top(t_tetr *head)
{
	while (head)
	{
		while (!move_left(head))
			;
		head = head->next;
	}
}

// int main()
// {
// 	t_tetr new;

// 	new.str = ft_strdup(".......#...#..##");
// 	new.size = 4;
// 	new.next = NULL;
// 	// ft_putnbr(check_top(&new));
// 	// ft_putnbr(check_left(&new));
// 	move_left_top(&new);
// 	ft_print(&new);
// }
