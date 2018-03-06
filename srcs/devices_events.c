/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 03:35:02 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/06 15:34:26 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxyz.h>
#include <fractol.h>
#include <move.h>
#include <closing.h>

void	refresh_keyboard(t_mlxyz *mlxyz, t_fractol *fractol)
{
	if (mlxyz->keyboard->key[36])
		fractol->render += 1;
	if (mlxyz->keyboard->key[69])
		fractol_zoom_in(mlxyz, fractol);
	if (mlxyz->keyboard->key[78])
		fractol_zoom_out(mlxyz, fractol);
	if (mlxyz->keyboard->key[123])
		fractol_move(fractol, -10, 0);
	if (mlxyz->keyboard->key[124])
		fractol_move(fractol, 10, 0);
	if (mlxyz->keyboard->key[125])
		fractol_move(fractol, 0, 10);
	if (mlxyz->keyboard->key[126])
		fractol_move(fractol, 0, -10);
	if (mlxyz->keyboard->key[49])
		fractol->lock += 1;



	if (mlxyz->keyboard->key[18])
		fractol->fractal = 0;
	if (mlxyz->keyboard->key[19])
		fractol->fractal = 1;
	if (mlxyz->keyboard->key[20])
		fractol->fractal = 2;
	if (mlxyz->keyboard->key[21])
		fractol->fractal = 3;




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
		fractol_move(fractol, delta_x, delta_y);
		mlxyz->mouse->last_x = mlxyz->mouse->x;
		mlxyz->mouse->last_y = mlxyz->mouse->y;
	}
}

void	refresh_input_devices(t_mlxyz *mlxyz, t_fractol *fractol)
{
	refresh_keyboard(mlxyz, fractol);
	refresh_mouse(mlxyz, fractol);
}
