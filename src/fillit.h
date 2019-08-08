/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:06:38 by bbekmama          #+#    #+#             */
/*   Updated: 2019/08/07 21:40:17 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct		s_tetr
{
	int				size;
	int				num;
	char			*str;
	struct s_tetr	*next;
	struct s_tetr	*back;
}					t_tetr;

t_tetr				backtracking(t_tetr *head);
void				ft_error(int code);
t_tetr				*reader(int fd);
void				ft_print(t_tetr *head);
void				val(t_tetr *head);
int					collision_check(t_tetr *head, t_tetr *list);
int					move_forward(t_tetr *tetrimino);
void				move_left_top(t_tetr *head);
void				ft_swap_char(char *a, char *b);
int					get_size(t_tetr *tetrimino);
void				expand_all(t_tetr *head, int size);
int					check_b(t_tetr *tetrimino);
int					check_r(t_tetr *tetrimino);
int					check_of_2(t_tetr *list);
void				ft_clear(t_tetr *head);

#endif
