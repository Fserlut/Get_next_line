/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 19:20:42 by fserlut           #+#    #+#             */
/*   Updated: 2019/05/08 01:17:12 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count_word(char *s, char l)
{
	int		i;
	int		c_word;

	c_word = 0;
	i = 0;
	while (s[i])
	{
		if ((ft_isalpha(s[i])) && ((s[i - 1] == l) || (i == 0)))
		{
			c_word++;
			i++;
		}
		else
			i++;
	}
	return (c_word + 1);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	size_t	lenstr;

	if (!s)
		return (NULL);
	while (*s == c)
		++s;
	if (!(tab = (char**)malloc(ft_count_word((char*)s, c) * sizeof(char*))))
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		lenstr = 0;
		while (*s != c && *s != '\0' && ++s)
			++lenstr;
		if (!(tab[i] = ft_strnew(lenstr)))
			return (NULL);
		ft_strncpy(tab[i++], s - lenstr, lenstr);
		while (*s == c)
			++s;
	}
	tab[i] = 0;
	return (tab);
}
