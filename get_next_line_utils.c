/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 18:14:22 by obelair           #+#    #+#             */
/*   Updated: 2020/12/30 16:14:31 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int		ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (i);
	return (-1);
}

static void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*strdst;
	unsigned char	*strsrc;

	if (!dst && !src)
		return (0);
	strdst = (unsigned char *)dst;
	strsrc = (unsigned char *)src;
	if (dst < src)
	{
		i = -1;
		while (++i < len)
			strdst[i] = strsrc[i];
	}
	else
	{
		i = len;
		while (0 < i--)
			strdst[i] = strsrc[i];
	}
	return (dst);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*cat;

	if (!s1 && !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!(cat = malloc(sizeof(char) * (lens1 + lens2 + 1))))
		return (NULL);
	ft_memmove(cat, s1, lens1);
	ft_memmove(cat + lens1, s2, lens2);
	cat[lens1 + lens2 + 1] = '\0';
	free(s1); 
	return (cat);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (!(sub = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	if (ft_strlen(s) > (size_t)start)
		while (i < len && s[start + i])
		{
			sub[i] = s[start + i];
			i++;
		}
	sub[i] = '\0';
	return (sub);
}