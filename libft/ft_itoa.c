/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:39:45 by bbekmama          #+#    #+#             */
/*   Updated: 2019/05/23 15:07:34 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		size(int i)
{
	int		size;

	size = 1;
	if (i == 0)
		return (2);
	while (i < 0)
	{
		i = i * (-1);
		size++;
	}
	while (i > 0)
	{
		i = i / 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 0;
	len = size(n);
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	if ((str = (char *)malloc(len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (--len >= sign)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
