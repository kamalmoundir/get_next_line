/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:04:47 by kmoundir          #+#    #+#             */
/*   Updated: 2024/10/08 13:08:14 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join_s1_s2;
	char	*tmp;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
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
	{
		i++;
	}
	return (i);
}


