/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:13:53 by gelambin          #+#    #+#             */
/*   Updated: 2017/11/13 11:51:40 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	while (s1[i])
		i++;
	s2 = (char*)malloc(sizeof(*s1) * (i + 1));
	if (!s2)
		return (s2);
	while (i >= 0)
	{
		s2[i] = s1[i];
		i--;
	}
	return (s2);
}
