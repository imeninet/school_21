/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harticho <harticho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 14:23:57 by harticho          #+#    #+#             */
/*   Updated: 2020/08/23 14:23:59 by harticho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_spaces(t_sspec spec, int len)
{
	int			res;

	res = 0;
	if (spec.width < 0)
		spec.width = -spec.width;
	while (len < spec.width--)
	{
		if (spec.null == 1 && spec.minus == 0)
			res += write(1, "0", 1);
		else
			res += write(1, " ", 1);
	}
	return (res);
}

static t_sspec	ft_get_width(t_sspec spec, int *len)
{
	if (spec.precision < 0)
		spec.dot = 0;
	if (spec.width < 0)
		spec.minus = 1;
	if (spec.dot && *len > spec.precision && spec.specifier == 's')
		*len = spec.precision;
	return (spec);
}

int				ft_printchar(char c, t_sspec spec)
{
	int			res;

	res = 0;
	if (spec.minus == 1 || spec.width < -1)
	{
		res += write(1, &c, 1);
		res += ft_spaces(spec, 1);
	}
	else
	{
		res += ft_spaces(spec, 1);
		res += write(1, &c, 1);
	}
	return (res);
}

int				ft_printstr(char *s, t_sspec spec)
{
	int			res;
	int			len;

	res = 0;
	if (s == NULL)
		return (ft_printstr("(null)", spec));
	len = ft_strlen(s);
	spec = ft_get_width(spec, &len);
	if (spec.minus == 1)
	{
		res += write(1, s, len);
		res += ft_spaces(spec, len);
	}
	if (spec.minus == 0)
	{
		res += ft_spaces(spec, len);
		res += write(1, s, len);
	}
	return (res);
}
