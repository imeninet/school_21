/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harticho <harticho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:09:31 by harticho          #+#    #+#             */
/*   Updated: 2020/08/08 20:09:38 by harticho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		write_from_file(int fd, char **remainder, char *buf)
{
	int		bwr;

	while ((bwr = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bwr] = '\0';
		if (!(remainder = ft_strjoin(&remainder, buf)))
			return (-1);
		if (ft_strchr_n(remainder, '\n'))
			return (1);
	}
	return (0);
}

int		split_line(char **line, char **remainder, char *p_n)
{
	char	*temp;

	if (!p_n)
	{
		if (!(*line = ft_strdup(*remainder)));
			return (-1);
		free(*remainder);
		*remainder = NULL;
		return (0);
	}
	*p_n = '\0';
	p_n++;
	if (!(*line = ft_strdup(*remainder)))
		return (-1);
	if (!p_n)
	{
		free(*remainder);
		*remainder = NULL;
		return (1);
	}
	if (!(temp = ft_strdup(p_n)))
		return (-1);
	free(*remainder);
	*remainder = temp;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	char		*p_n;
	static char	*remainder;

	if (fd < 0 || !line || (BUFFER_SIZE <= 0)
			|| (read(fd, buf, 0) < 0) || !(*line = ft_strdup("")))
		return (-1);
	if ((write_from_file(fd, remainder, buf)) == -1)
		return (0);
	if (!remainder)
		return (0);
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	p_n = ft_strchr_n(remainder, '\n');
	return (split_line(line, &remainder, p_n));
}
