/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 19:24:27 by fserlut           #+#    #+#             */
/*   Updated: 2019/05/17 00:13:03 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int					ft_strichr(const char *s, int c)
{
	int				i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

char				*ft_strcut(char *str, int c)
{
	int				i;
	int				i_c;
	char			*s_new;

	i = 0;
	i_c = ft_strichr(str, c);
	if (!(s_new = ft_strsub(str, i, i_c - i)))
		return(NULL);
	return (s_new);
}

int     			get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static	int		i_next;
	static	int		i_start;
	static	char	*p_next_line;
	static	int		c_use;

	if (read(fd, buff, BUFF_SIZE) < 0)
	{
		printf("%s\n", "Read error");
		return (-1);
	}
	else
	{
		if (c_use == 0)
		{
			i_next = ft_strichr(buff, '\n');
			p_next_line = ft_strchr(buff, '\n') + 1;
			*line = ft_strcut(buff, '\n');
			c_use++;
			//printf("Next Line in get_next_line: %s\n", *p_next_line);
			printf("Line in get_next_line: %s\n", *line);
		}
		else
		{
			ft_memdel((void*)line);
			*line = ft_strcut(p_next_line, '\n');
			printf("Line in get_next_line: %s\n", *line);
			p_next_line = ft_strchr(p_next_line, '\n') + 1;
		}
	}
	return (1);
}

int					main()
{
	int				fd;
	char			*line;

	fd = open("test", O_RDWR);
	get_next_line(fd, &line);
	printf("%s\n", line); //Hello, World!1
	get_next_line(fd, &line);
	printf("%s\n", line); //Hello, World!2
	return (0);
}
