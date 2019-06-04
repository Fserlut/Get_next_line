/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 21:18:39 by fserlut           #+#    #+#             */
/*   Updated: 2019/06/04 21:24:18 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strcut(char *str, int c)
{
	int				i;
	int				i_c;
	char			*s_new;

	i = 0;
	i_c = ft_strchr_index(str, c);
	if (!(s_new = ft_strsub(str, i, i_c - i)))
		return (NULL);
	return (s_new);
}
