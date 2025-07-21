/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:06:45 by alpascua          #+#    #+#             */
/*   Updated: 2025/01/22 14:59:02 by alpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define MAX_FD 1024
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

size_t	ft_strlen(char *str);

size_t	ft_strlcpy(char *dst, char *src, size_t size);

char	*ft_substr(char *s, unsigned int start, size_t len);

char	*ft_strjoin(char *s1, char *s2);

char	*ft_strchr(char *s, int c);

void	*ft_free(char **str, char **buff);

char	*ft_newstr(char **str);

void	*ft_read(char **str, int fd);

char	*get_next_line(int fd);

#endif
