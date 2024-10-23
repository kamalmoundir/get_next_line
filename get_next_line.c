/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:29:23 by kmoundir          #+#    #+#             */
/*   Updated: 2024/10/23 17:18:40 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *free_mem(char **ptr)
{
    if (ptr && *ptr)
    {
        free(*ptr);
        *ptr = NULL;
    }
	return (NULL);
}
char	*ft_get_line(int fd, char *line)
{
	char	*buffer;
	ssize_t	read_byte;
	
	read_byte = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free_mem(&line),NULL);
	buffer[0] = '\0';
	
	while (!ft_strchr(line, '\n') && read_byte > 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		
		if(read_byte > 0)
			{
				buffer[read_byte] = '\0';
				line = ft_strjoin(line, buffer);
			}
	}
	free_mem(&buffer);
	if (read_byte == -1)
			return (free(line), line = NULL, NULL);
	
	return (line);
}

char	*ft_get_new_line(char *str)
{
	char	*new_line;
	char 	*ptr;
	int		len;

	ptr = ft_strchr(str, '\n');
	len = ptr - str + 1;	
	new_line = ft_substr(str, 0, len);
	if(!new_line)
		return (NULL);	
	return (new_line);	
}

char	*ft_get_rest_line(char *str)
{
	char	*rest_line;
	char	*ptr;
	int		len;
	
	ptr =ft_strchr(str, '\n');
	if (!ptr)
		{
			rest_line = NULL;
			return (free_mem(&str));
		}	
	len = ptr - str + 1;
	if(!str[len])
		return (free_mem(&str));
	rest_line = ft_substr(str, len, ft_strlen(str) - len);
	free_mem(&str);
	if(!rest_line)
		return (NULL);
	return (rest_line);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd < 0 )
		return (NULL);
	rest = ft_get_line(fd, rest);
	if (!rest)
		return (NULL);
	line = ft_get_new_line(rest);
	if(!line)
		return (free_mem(&rest));	
	rest = ft_get_rest_line(rest);
	return (line);
}

/*
int main(void)
{
	int file = open("1char.txt", O_RDONLY);
	if (file < 0)
	{
		perror("Error opening file");
		return (1);
	}
	char *line;
	while ((line = get_next_line(file)) != NULL)
	{ 
		printf("%s", line);
		
		free(line);
	}
	if(line == NULL)
	{
		printf("%s", line);
		free(line);
	}	
	close(file);
	return (0);
}*/