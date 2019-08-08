/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:23:04 by bbekmama          #+#    #+#             */
/*   Updated: 2019/08/07 21:23:47 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define STR list->str

static int	hashcheck(char *str, int i)
{
	int n;

	n = 0;
	if (!(i % 4 == 0))
		n += (str[i - 1] == '#') ? 1 : 0;
	if (!(i % 4 == 3))
		n += (str[i + 1] == '#') ? 1 : 0;
	if (!(i < 4))
		n += (str[i - 4] == '#') ? 1 : 0;
	if (!(i > 11))
		n += (str[i + 4] == '#') ? 1 : 0;
	return (n);
}

void		validate(t_tetr *list)
{
	int i;
	int z;
	int total;

	i = 0;
	z = 0;
	total = 0;
	while (STR[i] != '\0')
	{
		if (STR[i] != '.' && STR[i] != '#')
			ft_error(3);
		if (STR[i] == '#')
		{
			total += hashcheck(STR, i);
			z++;
		}
		i++;
	}
	if (!(total == 6 || total == 8) || z != 4)
		ft_error(3);
}

int			check_of_2(t_tetr *list)
{
	int i;
	int z;
	int total;

	i = 0;
	z = 0;
	total = 0;
	while (STR[i] != '\0')
	{
		if (STR[i] != '.' && STR[i] != '#')
			ft_error(3);
		if (STR[i] == '#')
		{
			total += hashcheck(STR, i);
			z++;
		}
		i++;
	}
	return (total);
}

void		val(t_tetr *head)
{
	while (head != NULL)
	{
		validate(head);
		head = head->next;
	}
}
