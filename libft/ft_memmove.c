/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harticho <harticho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 09:37:57 by harticho          #+#    #+#             */
/*   Updated: 2020/05/28 20:48:55 by harticho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	signed char	operation;
	size_t		end;
	size_t		curr;

	if ((unsigned char*)dest != (unsigned char*)src)
	{
		if ((unsigned char*)dest < (unsigned char*)src)
		{
			operation = 1;
			curr = 0;
			end = n;
		}
		else
		{
			operation = -1;
			curr = n - 1;
			end = -1;
		}
		while (curr != end)
		{
			*(((unsigned char*)dest) + curr) = *(((unsigned char*)src) + curr);
			curr += operation;
		}
	}
	return (dest);
}
