/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainbonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:06:03 by alpascua          #+#    #+#             */
/*   Updated: 2025/02/03 11:25:08 by alpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	int		i = 0;
	char	*ptr1;
	char	*ptr2;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	while (i < 3)
	{
		ptr1 = get_next_line(fd1);
		ptr2 = get_next_line(fd2);
		printf("%s%s", ptr1, ptr2);
		free(ptr1);
		free(ptr2);
		i++;
	}
	close(fd1);
	close(fd2);
	return (0);
}
