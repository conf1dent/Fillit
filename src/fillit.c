/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:08:20 by bbekmama          #+#    #+#             */
/*   Updated: 2019/08/07 22:53:09 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int ac, char **av)
{
	t_tetr	*head;
	int		fd;
	int		size;

	if (ac < 2)
		ft_error(2);
	fd = open(av[1], O_RDONLY, 0);
	head = reader(fd);
	close(fd);
	val(head);
	move_left_top(head);
	size = get_size(head);
	expand_all(head, size);
	backtracking(head);
	ft_print(head);
	return (0);
}
