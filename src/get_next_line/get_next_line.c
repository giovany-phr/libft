/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:06:20 by gpaupher          #+#    #+#             */
/*   Updated: 2024/01/30 18:23:41 by gpaupher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

char	*read_lines(char *save, int fd)
{
	char	*buff;
	int		byte;

	byte = 1;
	buff = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (!save)
		save = ft_strdup("");
	while (!ft_strchr(save, '\n') && byte != 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[byte] = '\0';
		save = ft_strjoin(save, buff);
		if (save == NULL)
			return (NULL);
	}
	free(buff);
	return (save);
}

char	*fetch_line(char *save)
{
	char	*this_line;
	int		i;

	i = 0;
	if (save[i] == '\0')
		return (NULL);
	while (save[i] != '\n' && save[i])
		i++;
	this_line = (char *) malloc(sizeof(char) * (i + 2));
	if (!this_line)
		return (NULL);
	i = 0;
	while (save[i] != '\n' && save[i])
	{
		this_line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		this_line[i++] = '\n';
	this_line[i] = '\0';
	return (this_line);
}

char	*next_line(char *save)
{
	char	*next_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	next_line = (char *) malloc((sizeof(char) * ft_strlen(save) - i + 1));
	if (!next_line)
		return (NULL);
	i++;
	while (save[i])
		next_line[j++] = save[i++];
	next_line[j] = '\0';
	free(save);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	save = read_lines(save, fd);
	if (!save)
		return (NULL);
	line = fetch_line(save);
	save = next_line(save);
	return (line);
}
