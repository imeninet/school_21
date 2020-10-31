/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harticho <harticho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 19:22:44 by harticho          #+#    #+#             */
/*   Updated: 2020/05/18 19:22:53 by harticho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t	a;
	char	*dest_1;

	a = 0;
	dest_1 = dest;
	while (a < n)
	{
		dest_1[a] = c;
		a++;
	}
	return (dest);
}
