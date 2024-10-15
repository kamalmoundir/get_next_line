/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:29:23 by kmoundir          #+#    #+#             */
/*   Updated: 2024/10/15 20:31:26 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(int fd, char *line)
{
	char	*buffer;
	ssize_t	read_byte;
	char	*tmp;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_byte = 1;
	while (!ft_strchr(line, '\n') && read_byte > 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
			return (free(buffer), NULL);
		if (read_byte == 0)
			break ;
		buffer[read_byte] = '\0';
		tmp = line;
		line = ft_strjoin(line, buffer);
		if (!line || *line == '\0')
			return (free(tmp), free(buffer), NULL);
		free(tmp);
	}
	free(buffer);
	return (line);
}

char	*ft_get_new_line(char *str)
{
	char	*new_line;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	new_line = (char *)malloc((i + 2) * sizeof(char));
	if (!new_line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new_line[i] = str[i];
		i ++;
	}
	if (str[i] == '\n')
		new_line[i++] = '\n';
	new_line[i] = '\0';
	return (new_line);
}

char	*ft_get_rest_line(char *str)
{
	char	*rest_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	rest_line = (char *)malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!rest_line)
		return (NULL);
	i ++;
	while (str[i])
		rest_line[j++] = str[i++];
	rest_line[j] = '\0';
	free(str);
	return (rest_line);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(rest), rest = NULL, NULL);
	rest = ft_get_line(fd, rest);
	if (!rest || *rest == '\0')
	{
		if (rest)
			free(rest);
		return (NULL);
	}
	line = ft_get_new_line(rest);
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
        printf("test");
      
		printf("%s", line);
		free(line);
	}
    line = get_next_line(file);
    //if(line != NULL)
      //  printf("%s", line);
        //free(line);
	close(file);
	return (0);
}*/