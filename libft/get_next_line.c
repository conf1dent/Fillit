/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 16:35:29 by bbekmama          #+#    #+#             */
/*   Updated: 2019/08/05 23:22:15 by hvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*paste_rest(char **line, char *rest)
{
	char *ptr;

	*line = ft_strnew(BUFF_SIZE);
	if ((ptr = ft_strchr(rest, '\n')))
	{
		*ptr = '\0';
		ft_strcpy(*line, rest);
		ft_strcpy(rest, ++ptr);
	}
	else
	{
		ft_strcpy(*line, rest);
		ft_strclr(rest);
	}
	return (ptr);
}

static int		get_next_line2(const int fd, char **line, char *rest)
{
	char		*tmp;
	int			i;
	char		buf[BUFF_SIZE + 1];
	char		*ptr;

	ptr = paste_rest(line, rest);
	while (!ptr && (i = read(fd, buf, BUFF_SIZE)))
	{
		buf[i] = '\0';
		if ((ptr = ft_strchr(buf, '\n')))
		{
			*ptr = '\0';
			ft_strcpy(rest, ++ptr);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buf)) || i == -1)
			return (-1);
		ft_strdel(&tmp);
	}
	return ((ft_strlen(*line) || ft_strlen(rest) || i) ? 1 : 0);
}

static t_listok	*new_list(int fd)
{
	t_listok	*new;

	if (!(new = (t_listok*)malloc(sizeof(t_listok))))
		return (NULL);
	new->fd = fd;
	new->rest = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	return (new);
}

int				get_next_line(const int fd, char **line)
{
	static t_listok	*start_list;
	t_listok		*tmp_list;
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	if (!start_list)
		start_list = new_list(fd);
	tmp_list = start_list;
	while (tmp_list->fd != fd)
	{
		if (tmp_list->next == NULL)
			tmp_list->next = new_list(fd);
		tmp_list = tmp_list->next;
	}
	ret = get_next_line2(fd, line, tmp_list->rest);
	return (ret);
}
