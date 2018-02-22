/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 08:00:38 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/22 15:12:18 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlxyz.h>
#include <fractol.h>

int		burning_ship(double c_r, double c_i, int iterations)
{
	double z_r;
	double z_i;
	double z_r_c;
	double z_i_c;

	z_r_c = z_r * z_r;
	z_i_c = z_i * z_i;
	z_i = fabs(2 * z_r * z_i + c_i);
	z_r = fabs(z_r_c - z_i_c + c_r);
	while (z_r_c + z_i_c <= 4 && iterations)
	{
		z_r_c = z_r * z_r;
		z_i_c = z_i * z_i;
		z_i = fabs(2 * z_r * z_i + c_i);
		z_r = fabs(z_r_c - z_i_c + c_r);
		iterations--;
	}
	return (iterations);
}

void	burning_ship_loop(t_mlxyz *mlxyz, t_fractol *fractol)
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
			c_i = (-(mlxyz->screen->height / 2) + y)
				/ fractol->zoom + fractol->y;
			i = burning_ship(c_r, c_i, fractol->max_iter);
			fractol_color(mlxyz, x, y, i);
			y++;
		}
		x++;
	}
}
