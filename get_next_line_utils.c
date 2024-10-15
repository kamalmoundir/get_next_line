/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:04:47 by kmoundir          #+#    #+#             */
/*   Updated: 2024/10/15 20:51:47 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join_s1_s2;
	char	*tmp;
	size_t	len;	

	len = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	join_s1_s2 = (char *)malloc((len + 1) * sizeof(char));
	if (!join_s1_s2)
		return (NULL);
	tmp = join_s1_s2;
	while (*s1)
		*(tmp++) = *(s1++);
	while (*s2)
		*(tmp++) = *(s2++);
	*tmp = '\0';
	return (join_s1_s2);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*tmp;
	size_t	len;

	len = ft_strlen(s);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	tmp = str;
	while (*s)
		*(tmp++) = *(s++);
	*tmp = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	if (c >= 256)
		c = c % 256;
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
