/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasa <zyasa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:04:41 by zyasa             #+#    #+#             */
/*   Updated: 2023/02/10 14:46:33 by zyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_next_line(char *buff, int fd)
{
	char	*buffer;
	int		rd;

	rd = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (is_n_gnl(buff) == 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == 0)
			break ;
		if (rd == -1)
		{
			free(buff);
			free(buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		buff = ft_strjoin_gnl(buff, buffer);
	}
	free(buffer);
	return (buff);
}

static char	*get_line_gnl(char *str)
{
	char	*line;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (str[0] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	while (j <= i)
	{
		line[j] = str[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*next_line_gnl(char *buff)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	else
	{
		free(buff);
		return (NULL);
	}
	str = malloc((ft_strlen_gnl(buff) - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	j = ft_strcpy_gnl(str, buff + i);
	str[j] = '\0';
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = read_next_line(buff, fd);
	if (buff == NULL)
		return (NULL);
	line = get_line_gnl(buff);
	buff = next_line_gnl(buff);
	return (line);
}
