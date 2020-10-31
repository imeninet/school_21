/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harticho <harticho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 12:49:50 by harticho          #+#    #+#             */
/*   Updated: 2020/05/24 12:49:52 by harticho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	char	*new;
	char	*duble;

	i = 0;
	duble = (char*)s1;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	if (!(new = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		if (*duble == '\0')
			duble = (char*)s2;
		new[i++] = *duble++;
	}
	new[i] = '\0';
	return (new);
}
