/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 22:58:02 by bbekmama          #+#    #+#             */
/*   Updated: 2019/06/02 23:06:36 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*new;

	i = 0;
	while (s1[i])
		i++;
	new = (char *)malloc(i + 1);
	if (new == NULL)
		return (NULL);
	while (i >= 0)
	{
		new[i] = s1[i];
		i--;
	}
	return (new);
}
