/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:29:23 by kmoundir          #+#    #+#             */
/*   Updated: 2024/10/25 15:33:46 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_get_line(int fd, char *line)
{
	char	*buffer;
	ssize_t	read_byte;

	read_byte = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(line), line = NULL, NULL);
	buffer[0] = '\0';
	while (!ft_strchr(line, '\n') && read_byte > 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == 0)
			break ;
		if (read_byte > 0)
		{
			buffer[read_byte] = '\0';
			line = ft_strjoin(line, buffer);
		}
	}
	free(buffer);
	buffer = NULL;
	if (read_byte == -1)
		return (free(line), line = NULL, NULL);
	return (line);
}

char	*ft_get_new_line(char *str)
{
	char	*new_line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(str, '\n');
	len = ptr - str + 1;
	new_line = ft_substr(str, 0, len);
	if (!new_line)
		return (NULL);
	return (new_line);
}

char	*ft_get_rest_line(char *str)
{
	char	*rest_line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(str, '\n');
	if (!ptr)
	{
		rest_line = NULL;
		return (free(str), str = NULL, NULL);
	}
	len = ptr - str + 1;
	if (!str[len])
		return (free(str), str = NULL, NULL);
	rest_line = ft_substr(str, len, ft_strlen(str) - len);
	free(str);
	str = NULL;
	if (!rest_line)
		return (NULL);
	return (rest_line);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;	

	if (fd < 0)
		return (NULL);
	rest = ft_get_line(fd, rest);
	if (!rest)
		return (NULL);
	line = ft_get_new_line(rest);
	if (!line)
		return (free(rest), rest = NULL, NULL);
	rest = ft_get_rest_line(rest);
	return (line);
}
/*
#include <stdio.h>
int main(void)
{
	int file = open("file3.txt", O_RDONLY);
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
	close(file);
	return (0);
}*/
