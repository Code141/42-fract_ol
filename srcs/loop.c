/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:37:39 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/11 08:54:02 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlxyz.h>
#include <fractol.h>
#include <fractals/mandelbrot.h>
#include <closing.h>

void	fractol_move(t_mlxyz *mlxyz, t_fractol *fractol, int x, int y)
{
	fractol->x += x / fractol->zoom;
	fractol->y += y / fractol->zoom;
}

void	fractol_zoom_in(t_mlxyz *mlxyz, t_fractol *fractol)
{
	fractol->zoom *= 2;
	fractol_move(
			mlxyz,
			fractol,
			mlxyz->mouse->x - mlxyz->screen->width / 2,
			mlxyz->mouse->y - mlxyz->screen->height / 2
			);
}

void	fractol_zoom_out(t_mlxyz *mlxyz, t_fractol *fractol)
{
	if (fractol->zoom > 16)
	{
		fractol_move(
				mlxyz,
				fractol,
				-(mlxyz->mouse->x - mlxyz->screen->width / 2),
				-(mlxyz->mouse->y - mlxyz->screen->height / 2)
				);
		fractol->zoom /= 2;
	}
}

void	refresh_keyboard(t_mlxyz *mlxyz, t_fractol *fractol)
{
	if (mlxyz->keyboard->key[69])
		fractol_zoom_in(mlxyz, fractol);
	if (mlxyz->keyboard->key[78])
		fractol_zoom_out(mlxyz, fractol);
	if (mlxyz->keyboard->key[123])
		fractol_move(mlxyz,	fractol, -10, 0);
	if (mlxyz->keyboard->key[124])
		fractol_move(mlxyz,	fractol, 10, 0);
	if (mlxyz->keyboard->key[125])
		fractol_move(mlxyz,	fractol, 0, 10);
	if (mlxyz->keyboard->key[126])
		fractol_move(mlxyz,	fractol, 0, -10);
	if (mlxyz->keyboard->key[53])
		close_fractol(mlxyz);
}

void	refresh_mouse(t_mlxyz *mlxyz, t_fractol *fractol)
{
	double	delta_x;
	double	delta_y;

	if (mlxyz->mouse->button[4])
		fractol_zoom_in(mlxyz, fractol);
	if (mlxyz->mouse->button[5])
		fractol_zoom_out(mlxyz, fractol);
	if (mlxyz->mouse->button[1])
	{
		delta_x = mlxyz->mouse->last_x - mlxyz->mouse->x;
		delta_y = mlxyz->mouse->last_y - mlxyz->mouse->y;
		fractol_move(mlxyz, fractol, delta_x, delta_y);
		mlxyz->mouse->last_x = mlxyz->mouse->x;
		mlxyz->mouse->last_y = mlxyz->mouse->y;
	}
}

void	refresh_input_devices(t_mlxyz *mlxyz, t_fractol *fractol)
{
	refresh_keyboard(mlxyz, fractol);
	refresh_mouse(mlxyz, fractol);
}

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

int		loop(t_mlxyz *mlxyz)
{
	refresh_input_devices(mlxyz, mlxyz->app);
	refresh_stats(mlxyz->stats);
	ft_bzero(mlxyz->screen->canevas->data,
		mlxyz->screen->canevas->width * mlxyz->screen->canevas->height * 4);

	fractol(mlxyz, mlxyz->app);

	//	render(mlxyz);

	draw_hud(mlxyz);

	mlx_put_image_to_window(mlxyz->mlx,
		mlxyz->screen->win, mlxyz->screen->canevas->id, 0, 0);
	return (1);
}
