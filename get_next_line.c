/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 19:24:27 by fserlut           #+#    #+#             */
/*   Updated: 2019/06/04 22:07:54 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

//char				*strjoin() //funct help if BUFF_SIZE < \n

char				*get_next_line_second_use(int i_start)
{
	return (NULL);	
}
int					get_next_line(const int fd, char **line)
{
	char			*buff;
	static	int		i_line_end; //index end line
	static	int		i_next_line; //index next line start
	static	int		c_use; //count open gnl


	buff = ft_strnew(BUFF_SIZE);
	if (read(fd, buff, BUFF_SIZE) < 0)
		return (-1);
	else
	{
		if (c_use == 0)
		{
			i_line_end = ft_strchr_index(buff, '\n');
			*line = ft_strcut(buff, '\n');
			c_use++;
			return (1);
		}
		else
		{
			i_next_line = i_line_end + 1;
			//i_next = ;
			//Need write to *line next line started with i_next
		}
	}
	return (0);
}

int					main(void)
{
	int				fd;
	char			*line;

	fd = open("test", O_RDWR);
	get_next_line(fd, &line);
	ft_putstr(line); //1 line
	ft_putstr("\n");
	//get_next_line(fd, &line);
	//printf("%s\n", line); //Hello, World!2
	return (0);
}
