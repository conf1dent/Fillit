/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:08:20 by bbekmama          #+#    #+#             */
/*   Updated: 2019/08/05 22:50:46 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_tetr	*head;
	t_tetr	*tmp;
	int		fd;
	int		size;

	if (ac < 2)
		ft_error(2);
	fd = open(av[1], O_RDONLY, 0);
	head = reader(fd);
	close(fd);
	val(head);
	size = get_size(head);
	expand_all(head, size);
	move_left_top(head);
	tmp = head;
	while (tmp)
	{
		while (collision_check(head, tmp))
			if (move_forward(tmp))
			{
				while (move_forward(tmp))
				{
					if (tmp->num == 0)
					{
						expand_all(head, tmp->size + 1);
						move_left_top(head);
						break ;
					}
					tmp = tmp->back;
				}
				move_left_top(tmp->next);
			}
		tmp = tmp->next;
	}
	ft_print(head);
	return (0);
}
