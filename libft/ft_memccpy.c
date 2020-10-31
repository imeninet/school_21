/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harticho <harticho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 18:06:00 by harticho          #+#    #+#             */
/*   Updated: 2020/05/19 18:06:02 by harticho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *str_dest, const void *str_src, int c, size_t n)
{
	unsigned int	i;
	char			*dest;
	char			*src;
	char			*ptr;

	dest = (char *)str_dest;
	src = (char *)str_src;
	i = 0;
	ptr = 0;
	while (i < n && ptr == 0)
	{
		dest[i] = src[i];
		if (src[i] == ((char)c))
			ptr = dest + i + 1;
		i++;
	}
	return (ptr);
}
