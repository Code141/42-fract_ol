/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 03:35:02 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/14 20:00:09 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxyz.h>
#include <fractol.h>
#include <move.h>
#include <closing.h>

void	reset_fractol(t_fractol *fractol)
{

	fractol->lock = 0;
	fractol->max_iter = 10;
	fractol->zoom = 180;
	fractol->x = 0;
	fractol->y = 0;
	fractol->cr_custom = 0;
	fractol->ci_custom = 0;
}

void	key_press(void *ptr, int keycode)
{
	t_mlxyz		*mlxyz;
	t_fractol	*fractol;

	mlxyz = (t_mlxyz*)ptr;
	fractol = (t_fractol*)mlxyz->app;
	if (mlxyz->keyboard->key[125])
		fractol->max_iter--;
	if (mlxyz->keyboard->key[126])
		fractol->max_iter++;
	if (keycode == 18)
		fractol->fractal = 0;
	if (keycode == 19)
		fractol->fractal = 1;
	if (keycode == 20)
		fractol->fractal = 2;
	if (keycode == 21)
		fractol->fractal = 3;
	if (keycode == 22)
		fractol->fractal = 4;
	if (keycode == 23)
		fractol->fractal = 5;
	if (keycode == 26)
		fractol->fractal = 6;
	if (keycode == 36)
		fractol->render += 1;
	if (keycode == 49)
		fractol->lock += 1;
	if (keycode == 82)
		reset_fractol(fractol);
	if (keycode == 53)
		close_fractol(mlxyz);
}

void	refresh_keyboard(t_mlxyz *mlxyz, t_fractol *fractol)
{
	if (mlxyz->keyboard->key[69])
		fractol_zoom_in(mlxyz, fractol);
	if (mlxyz->keyboard->key[78])
		fractol_zoom_out(mlxyz, fractol);
	if (mlxyz->keyboard->key[0])
		fractol_move(fractol, -10, 0);
	if (mlxyz->keyboard->key[2])
		fractol_move(fractol, 10, 0);
	if (mlxyz->keyboard->key[1])
		fractol_move(fractol, 0, 10);
	if (mlxyz->keyboard->key[13])
		fractol_move(fractol, 0, -10);
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
		fractol_move(fractol, delta_x, delta_y);
		mlxyz->mouse->last_x = mlxyz->mouse->x;
		mlxyz->mouse->last_y = mlxyz->mouse->y;
	}
	mlxyz->mouse->button[4] = 0;
	mlxyz->mouse->button[5] = 0;
}

void	refresh_input_devices(t_mlxyz *mlxyz, t_fractol *fractol)
{
	refresh_keyboard(mlxyz, fractol);
	refresh_mouse(mlxyz, fractol);
}
