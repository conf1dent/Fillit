/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:57:48 by hvasylie          #+#    #+#             */
/*   Updated: 2019/08/01 22:42:05 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
int		backtrack_check(t_tetr *tetrimino)
{
	int i;
	t_back back;
	back = tetrimino->back;

	i = 0;
	while(tetrimino->str[i])
	{
		if (back->str[i] == '#' tetrimino->str[i] == '#')
			return (0);
	}
	return (1);
}

int		backtrack_str(t_tetr *tetrimino) 
{
	int i;
	int len;
	t_back back;

	len = ft_strlen(tetrimino->str);
	i = 0;
	while(tetrimino->str[i] && back->num > 0)
	{
		if(tetrimino->back >= 0)
			back = tetrimino->back;
			while(!(move_right_bottom(tetrimino)) // meaning doesm't return 1;
			{
				if (!(collision_check(back, tetrimino))) //??
					move_right_bottom(tetrimino); //grey??
			}
		else
			i++;
	}
}


int 	backtrack(t_tetr *tetrimino)
{
	int i;
	int len;
	int tetr_sp;
	t_next next;
	t_back back;

	len = ft_strlen(tetrimino->str);
	tetr_sp = tetrimino->num;
	i = 0;
	while(tetrimino->num != NULL)
	{
		backtrack_str(tetrimino);
		tetrimino = tetrimino->next;
		if (tetrimino->size * tetrimino->size < (tetrimino->num * 4))
			tetrimino->size++;
		i = 0;
	}
	while(!(backtrack_check(tetrimino)) // meaning return 0;
	{
		tetrimino = tetrimino->back; //??
		backtrack_str(tetrimino); //??
	}
}
	

	/* while(tetrimino->num != NULL)
	{
		next = tetrimino->next;
		back = tetrimino->back;
		while(tetrimino->str[i] < len)
		{
			if (tetrimino->str[i] == next->str[i])
			i++;
		}
	}*/
}