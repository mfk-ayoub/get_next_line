/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:13:24 by ayel-mou          #+#    #+#             */
/*   Updated: 2023/12/05 11:13:25 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char *get_next_line(int fd);
void read_line_fd(char **stash, int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *left_str, char *buff);
size_t	ft_strlen(const char *s);
char *extract_line(char *stash);
char *clean_stash (char *stash);

#endif