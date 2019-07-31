/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:23:04 by bbekmama          #+#    #+#             */
/*   Updated: 2019/07/24 23:16:32 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define STR list->str

static int	hashcheck(char *str, int i)
{
	int n;

	n = 0;
	if (!(i % 4 == 0)) //ne prover -1
		n += (str[i - 1] == '#') ? 1 : 0;
	if (!(i % 4 == 3)) // ne prover +1
		n += (str[i + 1] == '#') ? 1 : 0;
	if (!(i < 4)) // ne prover nazad
		n += (str[i - 4] == '#') ? 1 : 0;
	if (!(i > 11)) // ne prover vpered
		n += (str[i + 4] == '#') ? 1 : 0;
	return (n);	
}

void		validate(t_tetr *list) //head is 1 tetramino which is written as a single string
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
		} // in order to keep index of the string we write (STR, i)
		i++;
	}
	if (!(total == 6 || total == 8) || z != 4)
	{
		ft_putstr("invalid tetramino is #");
		ft_putnbr(list->num);
		ft_putstr("\n");
		ft_error(3);
	}
}

void		val(t_tetr *head)
{
	while (head != NULL)
	{
		validate(head);
		head = head->next; //iterating linked lists (head->next->next->next->NULL (until NULL))
	}
}
