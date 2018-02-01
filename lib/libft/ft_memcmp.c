/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:23:26 by gelambin          #+#    #+#             */
/*   Updated: 2017/11/16 14:10:45 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (((unsigned char*)s1)[i] == ((unsigned char*)s2)[i] && --n > 0)
		i++;
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
