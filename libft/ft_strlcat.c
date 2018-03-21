/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:11:42 by gelambin          #+#    #+#             */
/*   Updated: 2017/11/20 12:44:14 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i_dst_len;
	size_t i_src_len;
	size_t i;
	size_t j;

	i_dst_len = 0;
	i_src_len = 0;
	i = 0;
	j = 0;
	while (src[i_src_len])
		i_src_len++;
	while (dst[i_dst_len])
		if (i_dst_len > size)
			return (i_src_len + size);
		else
			i_dst_len++;
	if (i_dst_len > size)
		return (i_src_len + size);
	i = i_dst_len;
	while (i < size - 1 && src[j] && size)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (i_src_len + i_dst_len);
}
