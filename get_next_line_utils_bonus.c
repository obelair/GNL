/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 18:14:22 by obelair           #+#    #+#             */
/*   Updated: 2020/12/30 19:04:11 by obelair          ###   ########lyon.fr   */
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

char    *ft_strjoin(char *s1, const char *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*cat;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	i = -1;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!(cat = malloc(sizeof(char) * (lens1 + lens2) + 1)))
		return (NULL);
	while (s1 && s1[++i])
		cat[i] = s1[i];
	i = -1;
	while (s2 && s2[++i])
		cat[i + lens1] = s2[i];
	cat[lens1 + i] = '\0';
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