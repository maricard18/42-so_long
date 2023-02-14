/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 08:45:34 by maricard          #+#    #+#             */
/*   Updated: 2023/02/14 10:53:00 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int	validate_map(int fd, char *str, char *line)
{
	int	i;
	int	l;

	i = 0;
	l = line_counter(fd, str);
	if (l < 2)
		return (0);
	return (l);
}

int	line_counter(int fd, char *str)
{
	int		i;
	char	*buf;

	i = 0;
	buf = malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (!buf)
		return (0);
	read(fd, buf, BUFFER_SIZE);
	while (buf)
	{
		if (buf == '\n')
			i++;
		buf++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		l;

	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	l = line_counter(fd, argv[1]) + 1;	// +1 for the new line
	while (l > 0)
	{
		validate_map(fd, argv[1], line);
		l--;
	}
	if (1)
		ft_printf("Valid Map!");
	else
		ft_printf("Error :(");
}
