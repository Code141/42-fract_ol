/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:09:24 by gelambin          #+#    #+#             */
/*   Updated: 2017/11/17 20:00:42 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = ((unsigned char*)s);
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void*)(str + i));
		i++;
	}
	if (i < n)
		return ((void*)(str + i));
	return (NULL);
}
