/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:42:05 by bbekmama          #+#    #+#             */
/*   Updated: 2019/07/24 21:07:38 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr		*new_list(t_tetr *back, int num)
{
	t_tetr	*new;

	new =(t_tetr *)malloc(sizeof(t_tetr)); // malloc for the struct
	new->num = num;
	new->back = back; //we put *back (from prototype) to back in the struct
	new->str = ft_strnew(16); // the same as: new->str = (char *)malloc(sizeof(char) * 17);
	new->next = NULL; // if a new tetramino has next == NULL it is the last one
	return (new);
}

t_tetr		*reader(int fd)
{
	char	*buf;
	t_tetr	*head;
	t_tetr	*tmp;
	int		line_num;
	int		num;

	line_num = 0;
	num = 0;
	head = new_list(NULL, num); // num is for counting and differentiating tetraminos
	tmp = head;
	while (get_next_line(fd, &buf))
	{
		if (line_num++ % 5 == 4) // check existence of empty lne
		{
			tmp->next = new_list(tmp, ++num); //malloc for new tetramino, we put tmp for back
			tmp = tmp->next; //switch to the new tetramino
			if (ft_strlen(buf) != 0)
				ft_error(1);
			continue ; //does not go down
		}
		if (ft_strlen(buf) != 4)
			ft_error(1);
		ft_strcat(tmp->str, buf); //add rows of tetramino
		ft_strdel(&buf); //delete buffer before reading a new row		
	}
	return (head);
}


