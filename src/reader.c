/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:42:05 by bbekmama          #+#    #+#             */
/*   Updated: 2019/08/07 22:24:46 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr		*new_list(t_tetr *back, int num)
{
	t_tetr	*new;

	new = (t_tetr *)malloc(sizeof(t_tetr));
	new->num = num;
	new->size = 4;
	new->back = back;
	new->str = ft_strnew(16);
	new->next = NULL;
	return (new);
}

void		str_cat(t_tetr *tetrimino, char *buf)
{
	if (ft_strlen(buf) != 4)
		ft_error(1);
	ft_strcat(tetrimino->str, buf);
	ft_strdel(&buf);
}

t_tetr		*reader(int fd)
{
	char	*buf;
	t_tetr	*head;
	t_tetr	*tmp;
	int		line_num;
	int		num;

	line_num = 0;
	num = 0;
	head = new_list(NULL, num);
	tmp = head;
	while (get_next_line(fd, &buf))
	{
		if (line_num++ % 5 == 4)
		{
			tmp->next = new_list(tmp, ++num);
			tmp = tmp->next;
			if (ft_strlen(buf) != 0)
				ft_error(1);
			ft_strdel(&buf);
			continue ;
		}
		str_cat(tmp, buf);
	}
	ft_strdel(&buf);
	return (head);
}
