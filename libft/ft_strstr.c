/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <bbekmama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 15:28:31 by bbekmama          #+#    #+#             */
/*   Updated: 2019/05/24 14:19:19 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return ((char*)&haystack[j]);
	while (haystack[j])
	{
		i = 0;
		while (needle[i] == haystack[i + j])
		{
			if (needle[i + 1] == '\0')
				return ((char*)&haystack[j]);
			i++;
		}
		j++;
	}
	return (NULL);
}
