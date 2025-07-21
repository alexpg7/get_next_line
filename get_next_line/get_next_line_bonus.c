/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:54:04 by alpascua          #+#    #+#             */
/*   Updated: 2025/02/03 11:24:45 by alpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

void	*ft_reloc(char **str)
{
	char	*aux;
	size_t	start;

	start = ft_strchr(*str, '\n') - *str;
	aux = *str;
	*str = ft_substr(aux, start + 1, ft_strlen(aux) - start + 1);
	if (!(*str))
		return (ft_free(&aux, NULL));
	ft_free(&aux, NULL);
	return (*str);
}

static void	ft_bzero(void *s, size_t n, int *r)
{
	size_t	i;
	char	*str;

	if (r)
		*r = 1;
	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_read(char **str, int fd)
{
	char	*buff;
	int		r;
	char	*aux;

	buff = (char *)malloc(sizeof(char) *(BUFFER_SIZE + 1));
	if (!buff)
		return (ft_free(str, NULL));
	ft_bzero(buff, BUFFER_SIZE + 1, &r);
	while (r > 0 && !ft_strchr(buff, '\n'))
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r > 0)
		{
			buff[r] = '\0';
			aux = *str;
			*str = ft_strjoin(aux, buff);
			if (!(*str))
				return (ft_free(&aux, &buff));
			free(aux);
		}
	}
	free(buff);
	if (r < 0)
		return (ft_free(str, NULL));
	return (*str);
}

void	*ft_free(char **str, char **buff)
{
	free(*str);
	*str = NULL;
	if (buff != NULL)
		free(*buff);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*str[MAX_FD];
	char		*ptr;
	size_t		len;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if ((str[fd] && !ft_strchr(str[fd], '\n')) || !str[fd])
		if (!ft_read(&str[fd], fd))
			return (ft_free(&str[fd], NULL));
	if (str[fd] && !(*str[fd]))
		return (ft_free(&(str[fd]), NULL));
	if (ft_strchr(str[fd], '\n'))
		len = ft_strchr(str[fd], '\n') - str[fd] + 1;
	else
		len = ft_strlen(str[fd]);
	ptr = ft_substr(str[fd], 0, len);
	if (!ptr)
		return (ft_free(&str[fd], NULL));
	if (!ft_reloc(&str[fd]))
		return (ft_free(&ptr, NULL));
	return (ptr);
}
