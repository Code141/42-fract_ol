/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:37:39 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/08 06:15:46 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"
#include <fractol.h>
#include <math.h>

void	refresh_keyboard(t_mlxyz *mlxyz, t_fractol *fractol)
{
	if (mlxyz->keyboard->key[53])
		close_fractol(mlxyz);
}

void	refresh_mouse(t_mlxyz *mlxyz, t_fractol *fractol)
{
	double	delta_x;
	double	delta_y;

	if (mlxyz->mouse->button[4])
	{
		fractol->zoom *= 2;
		fractol->x += (mlxyz->mouse->x - mlxyz->screen->width / 2) / fractol->zoom;
		fractol->y += (mlxyz->mouse->y - mlxyz->screen->height / 2) / fractol->zoom;
		mlxyz->mouse->button[4] = 0;
	}
	if (mlxyz->mouse->button[5])
	{
		fractol->x -= (mlxyz->mouse->x - mlxyz->screen->width / 2) / fractol->zoom;
		fractol->y -= (mlxyz->mouse->y - mlxyz->screen->height / 2) / fractol->zoom;
		fractol->zoom /= 2;
		mlxyz->mouse->button[5] = 0;
	}
	if (mlxyz->mouse->button[1])
	{
		delta_x = mlxyz->mouse->last_x - mlxyz->mouse->x;
		delta_y = mlxyz->mouse->last_y - mlxyz->mouse->y;
		fractol->x += delta_x / fractol->zoom;
		fractol->y += delta_y / fractol->zoom;
		mlxyz->mouse->last_x = mlxyz->mouse->x;
		mlxyz->mouse->last_y = mlxyz->mouse->y;
	}
}

void	refresh_input_devices(t_mlxyz *mlxyz, t_fractol *fractol)
{
	refresh_keyboard(mlxyz, fractol);
	refresh_mouse(mlxyz, fractol);
}

void	fractol(t_mlxyz *mlxyz, t_img *canevas)
{
	double	pos_x;
	double	pos_y;
	double	image_x;
	double	image_y;
	double	iterations;

	pos_x = -((mlxyz->screen->width / 2) / ((t_fractol*)(mlxyz->app))->zoom) + ((t_fractol*)(mlxyz->app))->x;
	pos_y = -((mlxyz->screen->height / 2) / ((t_fractol*)(mlxyz->app))->zoom) + ((t_fractol*)(mlxyz->app))->y;

	image_x = mlxyz->screen->width;
	image_y = mlxyz->screen->height;
	iterations = 60;

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


	
	unsigned int color;
	x = 0;
	y = 0;
	while (x < image_x)
	{
		y = 0;
		while (y < image_y)
		{
			c_r = x / ((t_fractol*)(mlxyz->app))->zoom + pos_x;
			c_i = y / ((t_fractol*)(mlxyz->app))->zoom + pos_y;
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
			}
			if (i == iterations)
				color = 0x000000; 
			else
				color = i / iterations * 255;//(unsigned int)(255 * cos((float)mlxyz->stats->timestamp_m * 360/ 1000 * 3.141 /180));
			((unsigned int*)canevas->data)[(y * canevas->width) + x] = color;
			y++;
		}
		x++;
	}
}

int		loop(t_mlxyz *mlxyz)
{
	refresh_input_devices(mlxyz, mlxyz->app);
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
