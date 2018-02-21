/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 03:59:59 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/21 12:23:21 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxyz.h>
#include <fractol.h>
#include <math.h>
#include <fractals/mandelbrot.h>

void	fractol_color(t_mlxyz *mlxyz, t_fractol *fractol, int x, int y, int i)
{
	unsigned int	color;
	t_img			*canevas;
	float			pos;

	pos = (float)i / (float)fractol->max_iter;
	canevas = mlxyz->screen->canevas;
	color = 0x00000;
	if (i == 0)
		color = 0xffffff; 
	else
	{
		color += (unsigned int)(255 * ((sin(pos * PI + PI * 2) + 1) / 2)) << 16;
		color += (unsigned int)(255 * ((sin(pos * PI) + 1) / 2)) << 8;
		color += 0x0000ff * (1 - ((sin(pos*PI) + 1) / 2));
	}
	

	((unsigned int*)canevas->data)[(y * canevas->width) + x] = color;
}

void	fractol(t_mlxyz *mlxyz, t_fractol *fractol)
{
	if (fractol->fractal == 0)
		julia_loop(mlxyz, fractol);
	if (fractol->fractal == 1)
		mandelbrot_loop(mlxyz, fractol);
	if (fractol->fractal == 2)
		burning_ship_loop(mlxyz, fractol);
	if (fractol->fractal == 3)
		tricorn_loop(mlxyz, fractol);
}
