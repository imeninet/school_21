/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harticho <harticho@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 15:47:42 by harticho          #+#    #+#             */
/*   Updated: 2020/05/24 15:47:45 by harticho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*append_word(char const *s, char c)
{
	int		size;
	char	*word;

	size = 0;
	word = 0;
	while (s[size] && s[size] != c)
		size++;
	if (!(word = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_strlcpy(word, s, size + 1);
	return (word);
}

int		count_words(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			j++;
		while (s[i] != c && s[i])
			i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	int		i;
	int		count;

	i = -1;
	if (!s)
		return (NULL);
	count = count_words(s, c);
	if (!(out = malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	while (++i < count)
	{
		while (s[0] == c)
			s++;
		if (!(out[i] = append_word(s, c)))
		{
			while (i > 0)
				free(out[i--]);
			free(out);
			return (NULL);
		}
		s = &s[ft_strlen(out[i])];
	}
	out[i] = 0;
	return (out);
}
