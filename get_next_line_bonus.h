/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:12:55 by ayel-mou          #+#    #+#             */
/*   Updated: 2023/12/09 13:32:46 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
void	get_stash(char **stash, int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *left_str, char *buff);
size_t	ft_strlen(const char *s);
char	*get_one__line(char *stash);
char	*clean_stash(char *stash);

#endif
