/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 01:06:38 by fserlut           #+#    #+#             */
/*   Updated: 2019/04/25 17:43:16 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *ptr;
	unsigned char *ptr1;

	ptr = (unsigned char*)dst;
	ptr1 = (unsigned char*)src;
	if (ptr > ptr1)
		while (len-- > 0)
			ptr[len] = ptr1[len];
	else
		while (len-- > 0)
			*(ptr++) = *(ptr1++);
	return (dst);
}
