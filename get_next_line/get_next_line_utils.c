/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:43:19 by alpascua          #+#    #+#             */
/*   Updated: 2025/01/13 19:51:42 by alpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	cont;

	cont = 0;
	if (str == NULL)
		return (0);
	while (str[cont])
		cont++;
	return (cont);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size <= 0)
		return (ft_strlen(src));
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < (size_t)start)
	{
		len = 0;
		start = 0;
	}
	else if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s + start, len + 1);
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		len;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	while (s1 && s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	len = i;
	i = 0;
	while (s2 && s2[i])
	{
		ptr[len + i] = s2[i];
		i++;
	}
	ptr[i + len] = '\0';
	return (ptr);
}

char	*ft_strchr(char *s, int c)
{
	char	*dest;

	if (!s)
		return (NULL);
	dest = (char *)s;
	while (*dest)
	{
		if (*dest == (unsigned char)c)
			return (dest);
		dest++;
	}
	if (c == '\0')
		return ((char *)dest);
	return (NULL);
}
