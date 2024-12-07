/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:52:50 by iel-fouh          #+#    #+#             */
/*   Updated: 2024/12/04 20:35:14 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE  
#define BUFFER_SIZE 24
#endif /* BUFFER_SIZE */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd);
char *ft_line(char **line ,char *buffer);
size_t	ft_strlen(const char *str);
char	*ft_strdup( char *s1);
char	*ft_strjoin(char *s1, char  *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
int check_line(char *buff);
char *ft_read(int fd, char **line,char *buffer);

#endif /* GET_NEXT_LINE_H */