/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:37:39 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/07 09:22:14 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"
#include <fractol.h>

void	refresh_keyboard(t_mlxyz *mlxyz)
{
	if (mlxyz->keyboard->key[53])
		close_fractol(mlxyz);
}

void	refresh_mouse(t_mlxyz *mlxyz)
{
	int			delta_x;
	int			delta_y;

	if (mlxyz->mouse->button[4])
	{
		ft_putstr("+\n");
		((t_fractol*)(mlxyz->app))->zoom += 1;
		mlxyz->mouse->button[4] = 0;
	}
	if (mlxyz->mouse->button[5])
	{
		ft_putstr("-\n");
		((t_fractol*)(mlxyz->app))->zoom -= 1;
		mlxyz->mouse->button[5] = 0;
	}
	if (mlxyz->mouse->button[1])
	{
		delta_x = mlxyz->mouse->last_x - mlxyz->mouse->x;
		delta_y = mlxyz->mouse->last_y - mlxyz->mouse->y;
		((t_fractol*)(mlxyz->app))->zoom -= delta_x/2;
		// Get u'r delta here
		mlxyz->mouse->last_x = mlxyz->mouse->x;
		mlxyz->mouse->last_y = mlxyz->mouse->y;
	}
}

void	refresh_input_devices(t_mlxyz *mlxyz)
{
	refresh_keyboard(mlxyz);
	refresh_mouse(mlxyz);
}

int		mandelbrot(int x, int y, int iterations)
{

	return (1);
	return (0);
}

void	fractol(t_mlxyz *mlxyz, t_img *canevas)
{
	double	x1;
	double	y1;
	double	image_x;
	double	image_y;
	double	iterations;

	x1 = -2.1;
	y1 = -2.2;

	image_x = 810;
	image_y = 720;
	iterations = 50;

	int x;
	int y;

	double c_r;
	double c_i;
	double z_r;
	double z_i;
	double z_r_c;
	double z_i_c;
	double i;
	double old_z_r;

	x = 0;
	y = 0;
	while (x < image_x)
	{
		y = 0;
		while (y < image_y)
		{
			c_r = x / ((t_fractol*)(mlxyz->app))->zoom + x1;
			c_i = y / ((t_fractol*)(mlxyz->app))->zoom + y1;
			z_r = 0;
			z_i = 0;
			z_r_c = 0; 
			z_i_c = 0;
			i = 0;
			i++;	
			while (z_r_c + z_i_c < 4 && i < iterations)
			{
				old_z_r = z_r;
				z_r_c = z_r * z_r;
				z_i_c = z_i * z_i;
				z_r = z_r_c - z_i_c + c_r;
				z_i = 2 * z_i * old_z_r + c_i;
				i++;
((unsigned int*)canevas->data)[(y * canevas->width) + x] += 10;
			}
			if (i == iterations)
				((unsigned int*)canevas->data)[(y * canevas->width) + x] = 0xff0000;
			y++;
		}
		x++;
	}
}

int		loop(t_mlxyz *mlxyz)
{
	refresh_input_devices(mlxyz);
	refresh_stats(mlxyz->stats);

	ft_bzero(mlxyz->screen->canevas->data,
			mlxyz->screen->canevas->width * mlxyz->screen->canevas->height * 4);

	fractol(mlxyz, mlxyz->screen->canevas);

	//	render(mlxyz);

	draw_hud(mlxyz);
	mlx_put_image_to_window(mlxyz->mlx,
			mlxyz->screen->win, mlxyz->screen->canevas->id, 0, 0);
	return (1);
}
