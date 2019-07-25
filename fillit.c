/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <bbekmama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:08:20 by bbekmama          #+#    #+#             */
/*   Updated: 2019/07/24 16:15:43 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int ac, char **av)
{
	t_tetr *head;
	int fd;

	fd = open(av[1], O_RDONLY, 0); //open file to read
	head = reader(fd);
	close(fd);
	
	
	
	
	ft_print(head);
	return (0);
}
