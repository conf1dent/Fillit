/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <bbekmama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 21:30:04 by bbekmama          #+#    #+#             */
/*   Updated: 2019/07/03 21:12:46 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct	s_listok
{
	char			*rest;
	struct s_listok	*next;
	int				fd;
}				t_listok;

int				get_next_line(const int fd, char **line);

#endif
