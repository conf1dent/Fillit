/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 19:30:48 by bbekmama          #+#    #+#             */
/*   Updated: 2019/06/13 21:54:09 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *new;

	new = (char*)malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	while (size > 0)
	{
		new[size] = '\0';
		size--;
	}
	new[0] = '\0';
	return (new);
}
