/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 20:16:21 by gelambin          #+#    #+#             */
/*   Updated: 2017/11/16 11:44:52 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-'
					|| base[i] < 32 || base[i] == 127)
				return (-1);
			j++;
		}
		i++;
	}
	return (i);
}

static	void	ft_putnbr_base_long(long int nbr, char *base)
{
	int			size;

	size = ft_check_base(base);
	if (size < 2)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= size)
		ft_putnbr_base_long(nbr / size, base);
	ft_putchar(base[nbr % size]);
}

void			ft_putnbr_base(int nbr, char *base)
{
	int			size;

	size = ft_check_base(base);
	if (size < 2)
		return ;
	ft_putnbr_base_long(nbr, base);
}
