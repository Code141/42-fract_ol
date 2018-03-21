/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:58:00 by gelambin          #+#    #+#             */
/*   Updated: 2017/11/09 16:05:16 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;

	i = 0;
	while (haystack[i] == needle[i] && i < len && haystack[i])
		i++;
	if (!needle[i])
		return ((char*)haystack);
	if (!haystack[i] || i >= len)
		return (NULL);
	return (ft_strnstr(haystack + 1, needle, len - 1));
}
