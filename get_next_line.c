/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelair <obelair@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:34:28 by obelair           #+#    #+#             */
/*   Updated: 2020/12/30 18:30:15 by obelair          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *str)
{
	int		i;
	char	*tmp;

	if (!str)
		return (NULL);
	if ((i = ft_strchr(str, '\n')) == -1)
		tmp = ft_substr(str, 0, ft_strlen(str));
	else
		tmp = ft_substr(str, 0, i);
	return (tmp);
}

char	*get_keep_save(char *save)
{
	char	*keep;
	size_t	lenstr;
	int 	i;

	i = ft_strchr(save, '\n');
	if (i == -1)
	{
		free(save);
		return (NULL);
	}
	lenstr = ft_strlen(save);
	keep = ft_substr(save, i + 1, lenstr - i);
	free(save);
	return (keep);
}

int		get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*save;
	int			rd;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	rd = 1;
	while (ft_strchr(save, '\n') == -1 && rd)
	{
		if ((rd = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[rd] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	*line = get_line(save);
	save = get_keep_save(save);
	if (!rd)
		return (0);
	return (1);
}