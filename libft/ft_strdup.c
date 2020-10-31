/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harticho <harticho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 19:07:06 by harticho          #+#    #+#             */
/*   Updated: 2020/05/23 19:07:09 by harticho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(*src) * ft_strlen((char *)src) + 1);
	if (str == NULL)
		return (NULL);
	while (src[i] != 0)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	if (ft_strncmp(str, (char *)src, i - 1) != 0)
		return (NULL);
	return (str);
}
