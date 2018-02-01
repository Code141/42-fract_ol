/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:43:33 by gelambin          #+#    #+#             */
/*   Updated: 2017/11/16 12:19:28 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	size_t i;

	i = 0;
	if (!*s)
		return (0);
	if (*s != c)
		i++;
	while (*s++)
		if (*(s - 1) == c && *s != c && *s)
			i++;
	return (i);
}

static int	ft_word_len(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	nb_words;
	size_t	word_len;
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	word_len = 0;
	nb_words = ft_count_words(s, c);
	if (!(tab = (char**)malloc(sizeof(*tab) * (nb_words + 1))))
		return (NULL);
	while (nb_words--)
	{
		while (*s == c)
			s++;
		word_len = ft_word_len(s, c);
		if (!(tab[i] = ft_strnew(word_len + 1)))
			return (NULL);
		ft_strncpy(tab[i], s, word_len + 1);
		tab[i++][word_len] = '\0';
		s += word_len;
	}
	tab[i] = 0;
	return (tab);
}
