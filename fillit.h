/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:06:38 by bbekmama          #+#    #+#             */
/*   Updated: 2019/08/05 23:15:05 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdio.h>
# include <sys/stat.h> //for RDONLY?
# include <fcntl.h> //for OPEN
# include "libft/libft.h"

typedef struct		s_tetr
{
	int				size;
	int				num; // number of a tetramino
	char			*str;
	struct s_tetr	*next;
	struct s_tetr	*back;
}					t_tetr;

void		ft_error(int code);
t_tetr		*reader(int fd);
void		ft_print(t_tetr *head);
void		val(t_tetr *head);
int 		collision_check(t_tetr *head, t_tetr *list);
int			move_forward(t_tetr *tetrimino);
void		move_left_top(t_tetr *head);
void		ft_swap_char(char *a, char *b);
void		put_size_in_tetr(t_tetr *head, int size);
int			get_size(t_tetr *tetrimino);
void		expand_all(t_tetr *head, int size);

#endif