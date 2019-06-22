/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 21:19:43 by fserlut           #+#    #+#             */
/*   Updated: 2019/06/09 21:27:23 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchr_index(int i_start, const char *s, int c)
{
	while (s[i_start])
	{
		if (s[i_start] == c)
			return (i_start);
		i_start++;
	}
	if (s[i_start] == c)
		return (i_start);
	return (-1);
}
