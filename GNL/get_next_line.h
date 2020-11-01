/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harticho <harticho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:10:19 by harticho          #+#    #+#             */
/*   Updated: 2020/08/08 20:10:21 by harticho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

int		get_next_line(int fd, char **line);
int		split_line(char **line, char **remainder, char *p_n);
char	*write_from_file(int fd, char *remainder, char *buf);
char	*ft_strdup(const char *src);
char	*ft_strchr_n(char *str, char ch);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif
