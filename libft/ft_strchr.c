/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harticho <harticho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 17:22:02 by harticho          #+#    #+#             */
/*   Updated: 2020/05/21 17:22:05 by harticho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	while (str[0] != '\0')
	{
		if (str[0] == (char)ch)
			return ((char*)str);
		str++;
	}
	if ((char)ch == '\0')
		return ((char*)str);
	return (NULL);
}
