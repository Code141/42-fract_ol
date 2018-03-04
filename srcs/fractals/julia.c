/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 12:18:25 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/04 20:51:00 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxyz.h>
#include <fractol.h>

int		julia(double c_r, double c_i, int iterations, t_mlxyz *mlxyz)
{
	double z_r;
	double z_i;
	double z_r_c;
	double z_i_c;

	z_r_c = c_r * c_r;
	z_i_c = c_i * c_i;
	z_i = (c_i + c_i) * c_r + ((t_fractol*)mlxyz->app)->ci;
	z_r = z_r_c - z_i_c + ((t_fractol*)mlxyz->app)->cr;
	while (z_r_c + z_i_c <= 4 && iterations)
	{
		z_r_c = z_r * z_r;
		z_i_c = z_i * z_i;
		z_i = (z_i + z_i) * z_r + ((t_fractol*)mlxyz->app)->ci;
		z_r = z_r_c - z_i_c + ((t_fractol*)mlxyz->app)->cr;
		iterations--;
	}
	return (iterations);
}

void	julia_loop(t_mlxyz *mlxyz, t_fractol *fractol)
{
	double	c_r;
	double	c_i;
	int		x;
	int		y;
	int		i;

	x = -(mlxyz->screen->width / 2);
	while (x < mlxyz->screen->width)
	{
		c_r = (-(mlxyz->screen->width / 2) + x) / fractol->zoom + fractol->x;
		y = 0;
		while (y < mlxyz->screen->height)
		{
			c_i = (-(mlxyz->screen->height / 2) + y) / fractol->zoom
				+ fractol->y;
			i = julia(c_r, c_i, fractol->max_iter, mlxyz);
			fractol_color(mlxyz, x, y, i);
			y++;
		}
		x++;
	}
}
