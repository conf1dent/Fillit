/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 20:36:24 by bbekmama          #+#    #+#             */
/*   Updated: 2019/05/18 22:09:04 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
	{
		if (*((unsigned char*)s1) != *((unsigned char*)s2))
			return (*((unsigned char*)s1) - *((unsigned char*)s2));
		s1++;
		s2++;
	}
	return (0);
}
