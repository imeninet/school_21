/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harticho <harticho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 19:23:21 by harticho          #+#    #+#             */
/*   Updated: 2020/05/19 19:23:23 by harticho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	size_t			i;
	unsigned char	*carr;

	i = 0;
	carr = (unsigned char*)arr;
	while (i < n)
	{
		if (carr[0] == (unsigned char)c)
			return (carr);
		carr++;
		i++;
	}
	return (NULL);
}
