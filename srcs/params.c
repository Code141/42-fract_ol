/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:00:08 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/20 12:07:24 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void	show_usage(void)
{
	ft_putstr("usage: fractol");
	ft_putstr(" [fractal-name]\n");
	ft_putstr("Fractales :\n");
	ft_putstr("	Julia\n");
	ft_putstr("	Mandelbrot\n");
	exit(0);
}

void	params(int ac, char **av)
{

	if (ac == 0)
		show_usage();
	if (!ft_strcmp(*av, "Mandelbrot\0"))
		ft_putstr(*av);
	else if (!ft_strcmp(*av, "Julia\0"))
		ft_putstr(*av);
	else
		show_usage();

}
