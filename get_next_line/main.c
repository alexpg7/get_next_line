/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:06:03 by alpascua          #+#    #+#             */
/*   Updated: 2025/02/03 11:35:41 by alpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	int	i = 0;
	char *ptr;

	fd = open("test.txt", O_RDONLY);
	while (i < 4)
	{
		ptr = get_next_line(fd);
		printf("%s", ptr);
		free(ptr);
		i++;
	}
	close(fd);
	return (0);
}
