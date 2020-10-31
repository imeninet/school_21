/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harticho <harticho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 17:29:36 by harticho          #+#    #+#             */
/*   Updated: 2020/05/21 17:29:39 by harticho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	len;

	len = ft_strlen((char*)str);
	while (len != 0 && str[len] != (char)ch)
		len--;
	if ((char)ch == str[len])
		return ((char *)&str[len]);
	return (NULL);
}
