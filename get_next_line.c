/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:49:13 by fserlut           #+#    #+#             */
/*   Updated: 2019/06/22 10:36:35 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*get_next_line_cut()
{
    return (NULL);
}

int				get_next_line(const int fd, char **line)
{
	static char	*fd_save[1000];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			read_b;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((read_b = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[read_b] = '\0';
		if (fd_save[fd] == NULL)
			fd_save[fd] = ft_strnew(1);
		tmp = ft_strjoin(fd_save[fd], buff);
		ft_strdel(&fd_save[fd]);
		fd_save[fd] = ft_strdup(tmp);
		if (ft_strchr(buff, '\n'))
			break;
	}
	return (0);
}
