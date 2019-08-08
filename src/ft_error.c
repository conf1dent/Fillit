/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:25:50 by bbekmama          #+#    #+#             */
/*   Updated: 2019/08/07 21:22:03 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(int code)
{
	if (code == 1)
		ft_putstr("error\n");
	if (code == 2)
		ft_putstr("usage: fillit file.txt\n");
	if (code == 3)
		ft_putstr("error\n");
	exit(1);
}
