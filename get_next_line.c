/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:13:21 by ayel-mou          #+#    #+#             */
/*   Updated: 2023/12/09 13:30:33 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	get_stash(char **stash, int fd)
{
	char	*buffer;
	int		bytes_read;

	while (!ft_strchr(*stash, '\n'))
	{
		buffer = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
		if (buffer == NULL)
			return ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
		{
			free(buffer);
			return ;
		}
		if (bytes_read == -1)
		{
			free(buffer);
			free(*stash);
			*stash = NULL;
			return ;
		}
		buffer[bytes_read] = '\0';
		*stash = ft_strjoin(*stash, buffer);
		free(buffer);
	}
}

char	*get_one__line(char *stash)
{
	char	*line;
	int		index;

	line = NULL;
	index = 0;
	if (!stash || !ft_strlen(stash))
		return (NULL);
	while (stash[index] && stash[index] != '\n')
		index++;
	if (stash[index] && stash[index] == '\n')
		index++;
	line = malloc((index + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	index = -1;
	while (stash[++index] && stash[index] != '\n')
		line[index] = stash[index];
	if (stash[index] && stash[index] == '\n')
	{
		line[index] = '\n';
		index++;
	}
	line[index] = '\0';
	return (line);
}

char	*clean_stash(char *stash)
{
	char	*buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] && stash[i] == '\n')
		i++;
	buffer = malloc(((ft_strlen(stash) - i) + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	while (stash[i])
	{
		buffer[j] = stash[i];
		j++;
		i++;
	}
	buffer[j] = '\0';
	free(stash);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	get_stash(&stash, fd);
	if (stash == NULL)
		return (NULL);
	line = get_one__line(stash);
	if (line == NULL)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = clean_stash(stash);
	return (line);
}
