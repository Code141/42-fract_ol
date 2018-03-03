/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 20:49:12 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/03 22:04:51 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlxyz.h>
#include <fractol.h>

int		bullet(double c_r, double c_i, int iterations, t_fractol *fractol)
{
	double z_r;
	double z_i;
	double z_r_c;
	double z_i_c;

	z_r = 0;
	z_i = 0;
	z_r_c = c_r * c_r;
	z_i_c = c_i * c_i;
	z_i = (c_i + c_i) * c_r + c_i;
	z_r = z_r_c - z_i_c + c_r;
	while (z_r_c + z_i_c <= 4 && iterations)
	{
		z_r_c = z_r * (z_r / fractol->cr) + -(fractol->cr);
		z_i_c = z_i * z_i - z_r;
		z_i = (z_i + z_i) * z_r;
		z_r = z_r_c - z_i_c + c_r;
		iterations--;
	}
	return (iterations);
}

void	bullet_loop(t_mlxyz *mlxyz, t_fractol *fractol)
{
	double	c_r;
	double	c_i;
	int		x;
	int		y;
	int		i;

	fractol->cr = -(fabs(fractol->x + (-(mlxyz->screen->width / 2) +
					mlxyz->mouse->x) / fractol->zoom));
	x = -(mlxyz->screen->width / 2);
	while (x < mlxyz->screen->width)
	{
		c_r = (-(mlxyz->screen->width / 2) + x) / fractol->zoom + fractol->x;
		y = 0;
		while (y < mlxyz->screen->height)
		{
			c_i = (-(mlxyz->screen->height / 2) + y)
				/ fractol->zoom + fractol->y;
			i = bullet(c_r, c_i, fractol->max_iter, fractol);
			fractol_color(mlxyz, x, y, i);
			y++;
		}
		x++;
	}
}
