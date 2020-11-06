/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harticho <harticho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 12:38:19 by harticho          #+#    #+#             */
/*   Updated: 2020/08/23 12:38:25 by harticho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_parse(va_list ap, t_sspec spec)
{
	if (spec.specifier == 'c')
		return (ft_printchar(va_arg(ap, int), spec));
	else if (spec.specifier == 's')
		return (ft_printstr(va_arg(ap, char *), spec));
	else if (spec.specifier == 'd' || spec.specifier == 'i')
		return (ft_printnbr(va_arg(ap, int), spec, 1));
	else if (spec.specifier == 'u')
		return (ft_printnbr(va_arg(ap, unsigned int), spec, 0));
	else if (spec.specifier == 'p')
		return (ft_printptr(va_arg(ap, void *), spec));
	else if (spec.specifier == 'x' || spec.specifier == 'X')
		return (ft_printx(va_arg(ap, unsigned int), spec));
	else if (spec.specifier == '%')
		return (ft_printchar('%', spec));
	else
		return (0);
}

int				ft_specifier_pars(char s)
{
	if (s == 'c' || s == 's' || s == 'p' || s == 'd' ||
		s == 'i' || s == 'u' || s == 'x' || s == 'X' ||
		s == '%')
		return (0);
	return (1);
}

static t_sspec	ft_specif(const char **format, va_list ap, t_sspec spec)
{
	(*format)++;
	while (ft_specifier_pars(**format) && **format != '\0')
	{
		if (**format == '-')
			spec.minus = 1;
		else if (**format == '0' && spec.null == 0 && spec.minus == 0)
			spec.null = 1;
		else if (**format == '*' || ft_isdigit(**format))
			spec.width = ft_width_pars(&(*format), ap);
		else if (**format == '.')
		{
			spec.dot = 1;
			spec.precision = ft_prec_pars(&(*format), ap);
		}
		else
			break ;
		(*format)++;
	}
	spec.specifier = **format;
	return (spec);
}

t_sspec			ft_initstruct(void)
{
	t_sspec			spec;

	spec.null = 0;
	spec.minus = 0;
	spec.width = 0;
	spec.dot = 0;
	spec.precision = 0;
	spec.specifier = 0;
	return (spec);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			res;
	int			check;
	t_sspec		spec;

	if (format == NULL)
		return (-1);
	res = 0;
	va_start(ap, format);
	spec = ft_initstruct();
	while (*format != '\0')
	{
		check = res;
		if (*format == '%')
			res += ft_parse(ap, ft_specif(&format, ap, spec));
		else
			res += ft_printchar(*format, spec);
		if (res < check)
			res = -1;
		if (res < 0 || *format == '\0')
			break ;
		format++;
	}
	va_end(ap);
	return (res);
}
