/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 19:12:16 by bbekmama          #+#    #+#             */
/*   Updated: 2019/05/23 16:18:49 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*temp;

	temp = (void *)malloc(size);
	if (temp == NULL)
		return (NULL);
	ft_memset(temp, 0, size);
	return (temp);
}
