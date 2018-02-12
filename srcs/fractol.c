/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 03:59:59 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/12 04:07:31 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxyz.h>
#include <fractol.h>
#include <fractals/mandelbrot.h>

void	fractol_color(t_mlxyz *mlxyz, t_fractol *fractol, int x, int y, int i)
{
	unsigned int	color;
	t_img			*canevas;

	canevas = mlxyz->screen->canevas;
	if (i == 0)
		color = 0xffffff; 
	else if (i == fractol->max_iter)
		color = 0x000000; 
	else
		color = 255 - (i * 255 / fractol->max_iter);
//	(unsigned int)(255 * cos((float)mlxyz->stats->timestamp_m * 360/ 1000 * 3.141 /180));
	((unsigned int*)canevas->data)[(y * canevas->width) + x] = color;
}

void	fractol(t_mlxyz *mlxyz, t_fractol *fractol)
{
	double	c_r;
	double	c_i;
	int		x;
	int 	y;
	int 	i;

	x = -(mlxyz->screen->width / 2);
	while (x < mlxyz->screen->width)
	{
		c_r =  (-(mlxyz->screen->width / 2) + x) / fractol->zoom + fractol->x;
		y = 0;
		while (y < mlxyz->screen->height)
		{
			c_i = (-(mlxyz->screen->height / 2) + y) / fractol->zoom + fractol->y;
			i = mandelbrot(c_r, c_i, fractol->max_iter);
			fractol_color(mlxyz, fractol, x, y, i);
			y++;
		}
		x++;
	}
}
