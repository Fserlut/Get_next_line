/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 19:24:27 by fserlut           #+#    #+#             */
/*   Updated: 2019/06/05 23:16:31 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*ft_help(char *buff, int fd) //funct help if BUFF_SIZE < \n
{
	int				new_buff_size;
	char			*new_buff;
	int				i_line_end;

	new_buff_size = BUFF_SIZE;
	new_buff = ft_strnew(0);
	ft_strcpy(new_buff, buff);
	while (!(i_line_end = ft_strchr_index(new_buff, '\n') > 0))
	{
		new_buff_size++;
		read(fd, buff, new_buff_size);
		new_buff = ft_strjoin(new_buff, buff);
		if ((i_line_end = ft_strchr_index(new_buff, '\n') > 0))
			return (new_buff);
	}
	return (new_buff);
}

char				*gnl(int i_start)
{
	return (NULL);	
}
int					get_next_line(const int fd, char **line)
{
	char			*buff;
	static	int		i_line_end;
	static	int		i_next_line;
	static	int		c_use; //count open gnl

	if (BUFF_SIZE <= 0)
		return (0);
	buff = ft_strnew(BUFF_SIZE);
	if (read(fd, buff, BUFF_SIZE) < 0)
		return (-1);
	else
	{
		if (c_use == 0)
		{
			i_line_end = ft_strchr_index(buff, '\n');
			if ((i_line_end > 0)) // if BUFF_SIZE < '\n'
			{
				*line = ft_strcut(buff, '\n'); //cut string and adds '\0'
				c_use++;
				return (1);
			}
			else
			{
				*line = ft_help(buff, fd);
				*line = ft_strcut(*line, '\n'); //cut string and adds '\0'
				c_use++;
				return (1);
			}
			
		}
		else
		{
			i_next_line = i_line_end + 1;
			gnl(i_next_line);
			//i_next = ;
			//Need write to *line next line started with i_next
		}
	}
	return (0);
}
