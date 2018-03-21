/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:33:37 by gelambin          #+#    #+#             */
/*   Updated: 2017/11/13 13:03:26 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static	int	ft_count_int_char(int n)
{
	int mem;

	mem = 1;
	if (n < 0)
		mem++;
	while (n /= 10)
		mem++;
	return (mem);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		size;

	size = ft_count_int_char(n);
	if (!(str = (char*)malloc(sizeof(*str) * (size + 1))))
		return (str);
	if (!n)
		str[0] = '0';
	str[size] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		if (n == -2147483648)
		{
			str[1] = '2';
			n = -147483648;
		}
		n = -n;
	}
	while (size-- && n)
	{
		str[size] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
