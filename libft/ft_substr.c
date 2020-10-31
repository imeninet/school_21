/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harticho <harticho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 20:00:50 by harticho          #+#    #+#             */
/*   Updated: 2020/05/23 20:00:53 by harticho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	num;
	char	*new;

	num = 0;
	new = malloc(sizeof(char) * len + 1);
	if (!s || !new)
		return (NULL);
	while (num < len && start < ft_strlen((char*)s))
	{
		new[num] = s[start];
		num++;
		start++;
	}
	new[num] = '\0';
	return (new);
}
