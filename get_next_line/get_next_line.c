/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <laherwpayotmaciel@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:41:35 by lwencesl          #+#    #+#             */
/*   Updated: 2023/01/21 19:54:09 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	if (read(fd, 0, 0) || BUFFER_SIZE <= 0)
	{
		i = 0;
		while (buffer[i])
			buffer[i++] = '\0';
		return (NULL);
	}
	line = NULL;
	while ((buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0))
	{
		line = ft_strjoin(line, buffer);
		if (clean (0, 0, 0, buffer) == 1)
			break ;
	}
	return (line);
}
