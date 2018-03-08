/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 03:50:08 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/08 19:49:33 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxyz.h>
#include <fractol.h>

void	fractol_move(t_fractol *fractol, int x, int y)
{
	fractol->x += x / fractol->zoom;
	fractol->y += y / fractol->zoom;
}

void	fractol_zoom_in(t_mlxyz *mlxyz, t_fractol *fractol)
{
	double	speed;

	speed = 8;
	fractol->zoom *= 1 + (double)(1 / speed);
	fractol_move(
		fractol,
		(double)(mlxyz->mouse->x - (mlxyz->screen->width) / 2) / speed,
		(double)(mlxyz->mouse->y - (mlxyz->screen->height) / 2) / speed);
}

void	fractol_zoom_out(t_mlxyz *mlxyz, t_fractol *fractol)
{
	double	speed;

	speed = 8;
	if (fractol->zoom < 180)
		return ;
	fractol_move(
		fractol,
		-(mlxyz->mouse->x - (mlxyz->screen->width) / 2) / speed,
		-(mlxyz->mouse->y - (mlxyz->screen->height) / 2) / speed);
	fractol->zoom /= 1 + (double)(1 / speed);
}
