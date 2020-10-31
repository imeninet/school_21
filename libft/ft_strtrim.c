/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harticho <harticho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 14:39:41 by harticho          #+#    #+#             */
/*   Updated: 2020/05/24 14:39:42 by harticho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	a;
	char	*out;

	if (!s1 || !set)
		return (NULL);
	while (*s1 != 0 && ft_strchr(set, *s1))
		s1++;
	a = ft_strlen((char*)s1);
	while (a > 0 && ft_strchr(set, s1[a]))
		a--;
	out = ft_substr((char*)s1, 0, a + 1);
	return (out);
}
