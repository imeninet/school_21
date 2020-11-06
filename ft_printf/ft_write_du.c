/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_du.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harticho <harticho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 15:01:17 by harticho          #+#    #+#             */
/*   Updated: 2020/08/23 15:01:20 by harticho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_signint(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int		ft_nbrlen(int n, int prec)
{
	int			len;

	len = 1;
	while ((n /= 10) != 0)
		len++;
	if (prec > 2147483645)
		prec = 2147483645;
	if (prec > len)
		len = prec;
	return (len);
}

char			*ft_itoa_new(int nbr, int prec)
{
	int			i;
	char		*arr;
	int			len;

	len = ft_nbrlen(nbr, prec);
	if (nbr < 0)
		len++;
	if (!(arr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
		arr[i++] = '0';
	if (nbr < 0)
		arr[0] = '-';
	arr[len] = '\0';
	while (nbr / 10 != 0)
	{
		arr[--len] = ft_signint(nbr % 10) + '0';
		nbr /= 10;
	}
	arr[--len] = ft_signint(nbr % 10) + '0';
	return (arr);
}

int				ft_printnbr(int nbr, t_sspec spec, int flag)
{
	char		*arr;
	int			res;
	int			precision;

	arr = NULL;
	res = 0;
	precision = spec.precision;
	if (flag)
		spec = ft_defflags(spec, &precision, nbr < 0);
	else
		spec = ft_defflags(spec, &precision, 0);
	if (spec.dot && precision == 0 && nbr == 0 && spec.null == 0)
		arr = ft_strdup("");
	else
	{
		if (flag)
			arr = ft_itoa_new(nbr, precision);
		else
			arr = ft_arr(nbr, 10, precision);
	}
	if (arr == NULL)
		return (-1);
	res = ft_printstr(arr, spec);
	free(arr);
	return (res);
}
