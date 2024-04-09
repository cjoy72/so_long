/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calvinjoybaroi <calvinjoybaroi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:05:43 by calvinjoyba       #+#    #+#             */
/*   Updated: 2024/04/09 13:05:59 by calvinjoyba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*join_free(char *buffer, char *readbuf)
{
	char	*tmp;
	int		i;

	i = 0;
	if (buffer == NULL)
	{
		tmp = malloc(sizeof(char) * (ft_strlen(readbuf) + 1));
		if (tmp == NULL)
			return (NULL);
		while (readbuf[i])
		{
			tmp[i] = readbuf[i];
			i++;
		}
		tmp[i] = '\0';
		return (tmp);
	}
	tmp = ft_strjoin(buffer, readbuf);
	if (tmp == NULL)
		return (NULL);
	free(buffer);
	buffer = NULL;
	return (tmp);
}

static char	*clean_buf(char *buffer)
{
	char	*tmp;
	int		start;
	int		size;

	start = 0;
	if (buffer == NULL)
		return (NULL);
	while (buffer[start] != '\n' && buffer[start] != '\0')
		start++;
	if (buffer[start] == '\0')
	{
		free (buffer);
		return (NULL);
	}
	size = start + 1;
	while (buffer[size] != '\0')
		size++;
	tmp = ft_calloc(size - start + 1, sizeof(char));
	if (tmp == NULL)
		return (NULL);
	size = 0;
	while (buffer[start + 1] != '\0')
		tmp[size++] = buffer[(start++) + 1];
	free(buffer);
	return (tmp);
}

static char	*extract_line(char *buffer)
{
	char	*line;
	int		start;
	int		i;

	i = 0;
	start = 0;
	if (buffer == NULL || buffer[0] == '\0')
		return (NULL);
	while (buffer[start] != '\n' && buffer[start] != '\0')
		start++;
	line = ft_calloc(start + 1 + (buffer[start] == '\n'), sizeof(char));
	if (line == NULL)
		return (NULL);
	if (buffer[start] == '\n')
		start++;
	while (i < start && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	return (line);
}

static char	*read_line(char *buffer, char *readbuf, int fd)
{
	int	read_check;

	read_check = 1;
	while (read_check > 0)
	{
		read_check = read(fd, readbuf, BUFFER_SIZE);
		if (read_check < 0)
			return (NULL);
		if (read_check == 0)
			break ;
		readbuf[read_check] = '\0';
		buffer = join_free(buffer, readbuf);
		if (ft_strchr(buffer, '\n') != NULL)
			break ;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*readbuf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		if (buffer != NULL)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	readbuf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (readbuf == NULL)
		return (NULL);
	if (ft_strchr(buffer, '\n') == NULL)
		buffer = read_line(buffer, readbuf, fd);
	free (readbuf);
	readbuf = NULL;
	line = extract_line(buffer);
	buffer = clean_buf(buffer);
	return (line);
}