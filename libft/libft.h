/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harticho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:52:54 by harticho          #+#    #+#             */
/*   Updated: 2020/05/28 20:33:11 by harticho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int ch);
int		ft_isalpha(int ch);
int		ft_isascii(int ch);
int		ft_isdigit(int ch);
int		ft_isprint(int ch);
void	*ft_memccpy(void *str_dest, const void *str_src, int c, size_t n);
void	*ft_memchr(const void *arr, int c, size_t n);
int		ft_memcmp(const void *arr1, const void *arr2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *str, int ch);
char	*ft_strrchr(const char *str, int ch);
char	*ft_strdup(const char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_tolower(int ch);
int		ft_toupper(int ch);
void	*ft_memset(void *dest, int c, size_t n);
size_t	ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strnstr(char *str, const char *to_find, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

#endif
