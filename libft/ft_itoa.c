/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harticho <harticho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 15:34:23 by harticho          #+#    #+#             */
/*   Updated: 2020/05/25 15:34:24 by harticho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		numlen(int n)
{
	int		lennum;

	lennum = (n > 0) ? 1 : 2;
	while (n)
	{
		n = n / 10;
		lennum++;
	}
	return (lennum);
}

char	*ft_itoa(int n)
{
	char	*out;
	int		len;
	int		num;
	int		z;

	len = numlen(n);
	num = (n < 0) ? n * -1 : n;
	z = (n < 0) ? -1 : 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(out = malloc(sizeof(char) * (len))))
		return (NULL);
	out[--len] = '\0';
	while (len)
	{
		out[--len] = (num % 10) + '0';
		num = num / 10;
	}
	if (z < 0)
		out[len] = '-';
	return (out);
}
