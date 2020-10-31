/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harticho <harticho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 15:59:45 by harticho          #+#    #+#             */
/*   Updated: 2020/08/23 15:59:48 by harticho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_len_p(unsigned long int n, int prec)
{
	int					len;

	len = 1;
	while (n / 16 != 0)
	{
		n /= 16;
		len++;
	}
	if (prec > 2147483644)
		prec = 2147483644;
	if (prec > len)
		len = prec;
	len += 2;
	return (len);
}

char			*ft_itoa_p(void *p, int prec)
{
	unsigned long int	n;
	int					i;
	int					len;
	char				*arr;
	char				*array;

	array = "0123456789abcdef";
	n = (unsigned long int)p;
	len = ft_len_p(n, prec);
	if (!(arr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
		arr[i++] = '0';
	arr[1] = 'x';
	arr[len] = '\0';
	while (n / 16 != 0)
	{
		arr[--len] = array[n % 16];
		n /= 16;
	}
	arr[--len] = array[n % 16];
	return (arr);
}

int				ft_printptr(void *p, t_sspec spec)
{
	char				*arr;
	int					res;
	int					prec;

	res = 0;
	prec = spec.precision;
	if (spec.null && (spec.dot || spec.width < 0 || spec.minus))
		spec.null = 0;
	if (spec.null)
	{
		prec = spec.width - 2;
		spec.width = 0;
	}
	if (spec.dot && prec == 0 && p == NULL)
		arr = ft_strdup("0x");
	else
		arr = ft_itoa_p(p, prec);
	if (arr == NULL)
		return (-1);
	res += ft_printstr(arr, spec);
	free(arr);
	return (res);
}
