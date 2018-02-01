/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:24:16 by gelambin          #+#    #+#             */
/*   Updated: 2017/11/20 13:31:42 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (s[i])
		i++;
	while (i > 1 && (s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t'))
		i--;
	str = (char*)malloc(sizeof(*str) * (i + 1));
	if (!str)
		return (str);
	while (j < i)
		str[j++] = *s++;
	str[j] = '\0';
	return (str);
}
