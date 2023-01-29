/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <laherwpayotmaciel@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:57:33 by lwencesl          #+#    #+#             */
/*   Updated: 2023/01/21 20:20:05 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			i;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		i = 0;
		if (!fd)
			return (NULL);
		while (buffer[fd][i])
			buffer[fd][i++] = '\0';
		return (NULL);
	}
	line = NULL;
	while ((buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE) > 0))
	{
		line = ft_strjoin(line, buffer[fd]);
		if (clean (0, 0, 0, buffer[fd]) == 1)
			break ;
	}
	return (line);
}
