/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harticho <harticho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 12:49:29 by harticho          #+#    #+#             */
/*   Updated: 2020/08/23 12:49:38 by harticho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef	struct	s_spec
{
	int			null;
	int			minus;
	int			width;
	int			dot;
	int			precision;
	char		specifier;
}				t_sspec;

int				ft_printf(const char *format, ...);
t_sspec			ft_defflags(t_sspec spec, int *prec, int negnum);
int				ft_specifier_pars(char s);
t_sspec			ft_initstruct(void);
int				ft_width_pars(const char **format, va_list ap);
int				ft_prec_pars(const char **format, va_list ap);
t_sspec			ft_defflags(t_sspec spec, int *prec, int neg);
char			*ft_arr(unsigned int nbr, int base, int prec);
int				ft_printchar(char c, t_sspec spec);
int				ft_printstr(char *s, t_sspec spec);
char			*ft_itoa_new(int nbr, int prec);
int				ft_printnbr(int nbr, t_sspec spec, int flag);
char			*ft_itoa_p(void *p, int prec);
int				ft_printptr(void *p, t_sspec spec);
int				ft_printx(unsigned int n, t_sspec spec);

#endif
