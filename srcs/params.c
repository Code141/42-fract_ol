/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:00:08 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/15 15:07:40 by gelambin         ###   ########.fr       */
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
	ft_putstr("	julia\n");
	ft_putstr("	mandelbrot\n");
	ft_putstr("	burning_ship\n");
	ft_putstr("	tricorn\n");
	ft_putstr("	bullet\n");
	ft_putstr("	julia_fun\n");
	ft_putstr("	sierpinski_carpet\n");
	ft_putstr("	zappa\n");
	exit(0);
}

void	set_fractal_type(char *fractal_name, t_fractol *fractol)
{
	if (!ft_strcmp(fractal_name, "julia\0"))
		fractol->fractal = 0;
	else if (!ft_strcmp(fractal_name, "mandelbrot\0"))
		fractol->fractal = 1;
	else if (!ft_strcmp(fractal_name, "burning_ship\0"))
		fractol->fractal = 2;
	else if (!ft_strcmp(fractal_name, "tricorn\0"))
		fractol->fractal = 3;
	else if (!ft_strcmp(fractal_name, "bullet\0"))
		fractol->fractal = 4;
	else if (!ft_strcmp(fractal_name, "julia_fun\0"))
		fractol->fractal = 5;
	else if (!ft_strcmp(fractal_name, "sierpinski_carpet\0"))
		fractol->fractal = 6;
	else if (!ft_strcmp(fractal_name, "zappa\0"))
		fractol->fractal = 7;
	else
		show_usage();
}
