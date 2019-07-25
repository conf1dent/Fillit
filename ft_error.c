/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <bbekmama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:25:50 by bbekmama          #+#    #+#             */
/*   Updated: 2019/07/24 15:27:57 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(int code)
{
	if (code == 1)
		ft_putstr("file is corupted\n");
	if (code == 2)
		ft_putstr("tetramino is corupted\n");
	exit(1); // exits from the whole program
}
