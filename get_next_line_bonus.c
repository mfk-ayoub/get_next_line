/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:13:04 by ayel-mou          #+#    #+#             */
/*   Updated: 2023/12/06 00:42:37 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	read_line_fd(char **stash, int fd)
{
	char	*holder;
	int		read_count;

	holder = NULL;
	while (!ft_strchr(*stash, '\n'))
	{
		holder = malloc(BUFFER_SIZE + 1);
		if (holder == NULL)
			return ;
		read_count = read(fd, holder, BUFFER_SIZE);
		if (read_count <= 0)
		{
			free(holder);
			return ;
		}
		holder[read_count] = '\0';
		*stash = ft_strjoin(*stash, holder);
		free(holder);
	}
}

char	*extract_line(char *stash)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] && stash[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (line == NULL)
		return (NULL);
	i = -1;
	while (stash[++i] && stash[i] != '\n')
		line[i] = stash[i];
	if (stash[i] && stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*clean_stash(char *stash)
{
	char	*holder;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] && stash[i] == '\n')
		i++;
	holder = malloc((ft_strlen(stash) - i) + 1);
	if (holder == NULL)
		return (NULL);
	while (stash[i])
	{
		holder[j] = stash[i];
		j++;
		i++;
	}
	holder[j] = '\0';
	free (stash);
	return (holder);
}

char	*get_next_line(int fd)
{
	static char	*array_of_stash[1024];
	char		*stash;
	char		*line;

	stash = array_of_stash[fd];
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) == -1)
		return (NULL);
	read_line_fd(&stash, fd);
	if (stash == NULL)
		return (NULL);
	line = extract_line(stash);
	if (line[0] == '\0')
	{
		free(stash);
		free(line);
		return (NULL);
	}
	stash = clean_stash(stash);
	array_of_stash[fd] = stash;
	return (line);
}
