/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:08:20 by bbekmama          #+#    #+#             */
/*   Updated: 2019/07/25 00:21:47 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_tetr *head;
	t_tetr *tmp;
	int fd;

	fd = open(av[1], O_RDONLY, 0); //open file to read
	head = reader(fd);
	close(fd);
	val(head);
	ft_print(head);
	// tmp = head;
	// while (!collision_check(head, tmp))
	// 	if (move_next(tmp))
	// 	{
	// 		tmp = tmp->back;
	// 		continue ;
	// 	}
	// tmp = tmp->next;
	// printf("%d\n", collision_check(head, head->next->next));
	return (0);
	ft_error(1);
}