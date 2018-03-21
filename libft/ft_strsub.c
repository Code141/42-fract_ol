/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:29:59 by gelambin          #+#    #+#             */
/*   Updated: 2017/11/13 18:37:11 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	while (start--)
		s++;
	str = (char*)malloc(sizeof(*str) * (len + 1));
	if (str)
	{
		str[len] = '\0';
		while (len--)
			str[len] = s[len];
	}
	return (str);
}
