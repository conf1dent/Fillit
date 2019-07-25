/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:02:55 by bbekmama          #+#    #+#             */
/*   Updated: 2019/05/27 20:38:23 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int num;
	int i;
	int flag;

	flag = 0;
	i = 0;
	num = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			flag = 1;
		}
		if (flag == 1)
		{
			num++;
			flag = 0;
		}
	}
	return (num);
}

static int	ft_len(char const *s, char c)
{
	int len;

	len = 0;
	while (*s != c && *s)
	{
		s++;
		len++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		num;
	int		j;
	int		n;

	j = 0;
	if (!s || !c)
		return (NULL);
	num = ft_wordcount(s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * (num + 1))))
		return (NULL);
	while (j < num)
	{
		n = 0;
		while (*s == c && *s)
			s++;
		if (!(arr[j] = (char *)malloc(sizeof(char) * ft_len(s, c) + 1)))
			return (NULL);
		while (*s && *s != c)
			arr[j][n++] = *s++;
		arr[j][n] = '\0';
		j++;
	}
	arr[j] = NULL;
	return (arr);
}
