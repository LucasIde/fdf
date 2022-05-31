/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:08:24 by lide              #+#    #+#             */
/*   Updated: 2022/05/26 15:25:47 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strjoin(char *s1, char *s2, int i, int j)
{
	char	*s3;

	if (!s1)
	{
		s3 = malloc(sizeof(char) * (ft_strlen(s2) + 1));
		if (!s3)
			return (NULL);
		while (s2[++i])
			s3[i] = s2[i];
	}
	else
	{
		s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!s3)
			free(s1);
		if (!s3)
			return (NULL);
		while (s1[++i])
			s3[i] = s1[i];
		while (s2[++j])
			s3[i++] = s2[j];
		free(s1);
	}
	s3[i] = 0;
	return (s3);
}

char	*free_error(char *str, char *save)
{
	if (save)
		free(save);
	free(str);
	write(2, "Error : gnl/ft_read\n", 20);
	return (NULL);
}

char	*ft_read(int fd, char *save)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (2));
	if (!str)
	{
		if (save)
			free(save);
		write(2, "Error : gnl/ft_read\n", 20);
		return (NULL);
	}
	i = 1;
	while (backspace(save) && i)
	{
		i = read(fd, str, 1);
		if (i == -1 || (!save && i == 0))
			return (free_error(str, save));
		str[i] = 0;
		save = ft_strjoin(save, str, -1, -1);
		if (!save)
			return (free_error(str, save));
	}
	free(str);
	return (save);
}

int	check_fd(int fd, char *save)
{
	if (fd == -2)
		free(save);
	if (fd == -1)
		write(2, "Error : wrong fd (probably nothing to read)\n", 44);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	int			len;

	if (fd < 0)
		return (check_fd(fd, save));
	save = ft_read(fd, save);
	if (!save)
		return (-1);
	if (!*save)
	{
		free(save);
		return (0);
	}
	len = ft_find(save);
	*line = ft_line(save, len);
	if (!*line)
		return (-1);
	save = ft_save(save, len);
	if (!save)
	{
		free(*line);
		return (-1);
	}
	return (1);
}
