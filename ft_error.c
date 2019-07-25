/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <bbekmama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:25:50 by bbekmama          #+#    #+#             */
/*   Updated: 2019/07/24 17:37:05 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(int code)
{
	if (code == 1)
		ft_putstr("file is corupted\n");
	if (code == 2)
		ft_putstr("tetramino is corupted\n");
	if (code == 3)
		ft_putstr("invalid tetramino\n");
	exit(1); // exits from the whole program
}
