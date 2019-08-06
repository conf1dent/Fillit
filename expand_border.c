/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_border.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:37:12 by hvasylie          #+#    #+#             */
/*   Updated: 2019/08/05 22:58:34 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		fill_dot(char *str, int size)
{
	int i;

	i = 0;
	while (i < size)
		str[i++] = '.';
}

void			expand_border(t_tetr *tetrimino, int size)
{
	int		i;
	int		j;
	int		dot_add;
	char	*str;

	i = 0;
	j = 0;
	dot_add = size - tetrimino->size;
	str = ft_strnew(size * size - 1);
	fill_dot(str, size * size);
	while (tetrimino->str[i])
	{
		if (tetrimino->str[i] == '#')
			str[j] = '#';
		if (i % tetrimino->size == tetrimino->size - 1)
			j += dot_add;
		i++;
		j++;
	}
	//free(tetrimino->str);
	tetrimino->str = str;
}

void	expand_all(t_tetr *head, int size)
{
	t_tetr *tmp;

	tmp = head;
	if (head->size == size)
		return ;
	while (tmp)
	{
		expand_border(tmp, size);
		tmp = tmp->next;
	}
	put_size_in_tetr(head, size);
}

// int main()
// {
// 	t_tetr new;

// 	new.str = ft_strdup("...#...#...#...#");
// 	//new.str = ft_strdup("####............");
// 	new.size = 4;
// 	expand_border(&new, 7);
// 	int i;
// 	while (new.str[i])
// 	{
// 		if (i % 7 == 0)
// 			ft_putchar('\n');
// 		ft_putchar(new.str[i]);
// 		i++;
// 	}
// }
