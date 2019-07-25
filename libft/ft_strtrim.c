/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 19:21:26 by bbekmama          #+#    #+#             */
/*   Updated: 2019/05/24 19:11:18 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while ((*s == ' ' || *s == '\n' || *s == '\t') && *s)
		s++;
	while (s[i])
		i++;
	i--;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i > 0)
		i--;
	new = ft_strsub(s, 0, ++i);
	if (new == NULL)
		return (NULL);
	return (new);
}
