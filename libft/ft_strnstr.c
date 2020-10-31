/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harticho <harticho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 15:00:27 by harticho          #+#    #+#             */
/*   Updated: 2020/05/23 15:00:29 by harticho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, const char *to_find, size_t len)
{
	size_t		num;
	size_t		a;

	num = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[num] != '\0' && num < len)
	{
		if (str[num] == to_find[0])
		{
			a = 1;
			while (to_find[a] != '\0' && str[num + a] == to_find[a] &&
				num + a < len)
				a++;
			if (to_find[a] == '\0')
				return (&str[num]);
		}
		num++;
	}
	return (NULL);
}
