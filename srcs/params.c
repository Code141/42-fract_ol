/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:00:08 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/21 08:53:22 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <fractol.h>

void	show_usage(void)
{
	ft_putstr("usage: fractol");
	ft_putstr(" [fractal-name]\n");
	ft_putstr("Fractales :\n");
	ft_putstr("	Julia\n");
	ft_putstr("	Mandelbrot\n");
	ft_putstr("	Burning_ship\n");
	ft_putstr("	Tricorn\n");
	exit(0);
}

void	set_fractal_type(char *fractal_name, t_fractol *fractol)
{

	if (!ft_strcmp(fractal_name, "Julia\0"))
		fractol->fractal = 0;
	else if (!ft_strcmp(fractal_name, "Mandelbrot\0"))
		fractol->fractal = 1;
	else if (!ft_strcmp(fractal_name, "Burning_ship\0"))
		fractol->fractal = 2;
	else if (!ft_strcmp(fractal_name, "Tricorn\0"))
		fractol->fractal = 3;
	else
		show_usage();
}
