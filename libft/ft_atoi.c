/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harticho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:14:39 by harticho          #+#    #+#             */
/*   Updated: 2020/02/10 17:57:41 by harticho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int				n;
	long long int	out;
	int				in;

	n = 0;
	out = 0;
	in = -1;
	while (*str != '\0' && (*str == ' ' || *str == '\t' ||
		*str == '\n' || *str == '\r' || *str == '\v' || *str == '\f'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			in = 1;
		str++;
	}
	while (str[n] >= '0' && str[n] <= '9')
	{
		out = out * 10 + (str[n] - 48);
		n++;
	}
	if (n > 18)
		return ((in < 0) ? -1 : 0);
	return (out * in * -1);
}
