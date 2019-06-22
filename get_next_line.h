/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 19:28:13 by fserlut           #+#    #+#             */
/*   Updated: 2019/06/20 15:01:37 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# define BUFF_SIZE 1
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft/libft.h"

int     get_next_line(const int fd, char **line);

#endif
