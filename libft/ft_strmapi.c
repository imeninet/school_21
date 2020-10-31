/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harticho <harticho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:45:13 by harticho          #+#    #+#             */
/*   Updated: 2020/05/25 18:45:18 by harticho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*out;
	unsigned int	iter;
	size_t			len;

	iter = 0;
	if (s && f)
	{
		len = ft_strlen((char*)s);
		if (!(out = (char*)malloc((len + 1) * sizeof(char))))
			return (NULL);
		while (s[iter] != 0)
		{
			out[iter] = f(iter, s[iter]);
			iter++;
		}
		out[iter] = '\0';
		return (out);
	}
	return (NULL);
}
