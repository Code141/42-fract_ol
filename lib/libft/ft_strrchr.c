/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:47:08 by gelambin          #+#    #+#             */
/*   Updated: 2017/11/09 15:13:40 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s1, int c)
{
	size_t i;

	i = 0;
	while (s1[i])
		i++;
	while ((char)c != s1[i] && i)
		i--;
	return (((char)c != s1[i]) ? NULL : (char *)(s1 + i));
}
