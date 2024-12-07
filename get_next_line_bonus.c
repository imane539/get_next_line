/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:51:10 by iel-fouh          #+#    #+#             */
/*   Updated: 2024/12/04 20:58:48 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

char *ft_stop(char **buf)
{
    int i;
    char *new;
    char *tmp ;
    i = 0;
    while (((*buf)[i]))
    {
        
        if ((*buf)[i] == '\n')
        {
            new = ft_substr(*buf, 0, i + 1);
            tmp = ft_substr(*buf, i + 1, ft_strlen(*buf) - i);
            free(*buf);
            *buf=tmp;
            return new;
        }
        i++;
    }
    return NULL;
}
char *ft_line(char **line ,char *buffer)
{
    char *tmp;
    char *new;
    if (check_line(buffer))
    {
            new = ft_stop(&buffer);
            tmp = ft_strjoin(*line, new);
            free(*line);
            free(new);
            *line = tmp;
    }
    else
    {
        new = ft_strjoin(*line, buffer);
         free(*line);
        *line = new;
        free(buffer);
        buffer = NULL;
    }
    return buffer;
}
char *ft_read(int fd, char **line, char *buffer)
{
    int r;
    
    r = 1;
    while (!check_line(*line) && r > 0)
    {
        if(ft_strlen(buffer) > 0)
            buffer = ft_line(line,buffer);
        if(ft_strlen(buffer) == 0)
        {
            free(buffer);
            buffer = malloc((size_t)(BUFFER_SIZE + 1));
            if(!buffer)
                return NULL;
            r = read(fd, buffer, BUFFER_SIZE);
            if (r <= 0)
            {
                free(buffer);
                buffer=NULL;
                return buffer;
            }
            buffer[r] = '\0';
            
        }
        if(!check_line(*line))
            buffer = ft_line(line,buffer);
    }
    return (buffer);
}
char *get_next_line(int fd)
{
    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    static char *buffer[1024];
    char *line = NULL;
    buffer[fd] = ft_read(fd, &line, buffer[fd]);
    // printf("buffer[%d]:%s\n",fd,buffer[fd]);
    // printf("line:%s\n",line);

    // if(!buffer)
    // {
    //     free(buffer);
    //     buffer=NULL;
    // }
    return line;
}
// int main()
// {
//     int fd = open("file.txt", O_RDONLY);
//     int fd2 = open("file2.txt", O_RDONLY);

//     char *line;
//     char *line2;

//     // int i = 0;
//     line = get_next_line(fd);
//     line2 = get_next_line(fd2);
//     printf("line1:%s", line); 
//     printf("line2:%s", line2); 
//     free(line);
//     free(line2);
//  line = get_next_line(fd);
//     line2 = get_next_line(fd2);
//        printf("line1:%s", line); 
//     printf("line2:%s", line2); 
//        free(line);
//     free(line2);
// }