/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:59:52 by gelambin          #+#    #+#             */
/*   Updated: 2017/11/09 15:58:28 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;

	i = 0;
	while (haystack[i] == needle[i] && haystack[i])
		i++;
	if (!needle[i])
		return ((char*)haystack);
	if (!haystack[i])
		return (NULL);
	return (ft_strstr(haystack + 1, needle));
}
