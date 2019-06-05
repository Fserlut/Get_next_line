/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 23:02:57 by fserlut           #+#    #+#             */
/*   Updated: 2019/06/05 12:28:41 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int					main(void)
{
	int				fd;
	char			*line;

	fd = open("test", O_RDWR);
	ft_putnbr(get_next_line(fd, &line));
	ft_putstr(" <- get_next_line out.\n");
	ft_putstr(line); //1 line
	ft_putstr("\n");
	//get_next_line(fd, &line);
	//printf("%s\n", line); //Hello, World!2
	return (0);
}
