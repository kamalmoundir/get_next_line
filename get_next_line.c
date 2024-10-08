/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:29:23 by kmoundir          #+#    #+#             */
/*   Updated: 2024/10/08 17:58:35 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"


char *get_next_line(int fd)
{
	char *buffer;

	buffer = malloc((20)* sizeof(char));
	
	ssize_t n_byte;
	
	n_byte = read(fd,buffer,20);

	while(*buffer && *buffer != '\n' && n_byte > 0)
	{
		buffer ++;	
	}
	return (buffer);
}
  
int main(void)
{
	int file = open("test.txt",O_RDONLY);
	printf("%s",get_next_line(file));
	return (0);
}
