/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 03:50:08 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/22 15:08:49 by gelambin         ###   ########.fr       */
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
	fractol->zoom *= 1.0625;
	fractol_move(
		fractol,
		(double)(mlxyz->mouse->x - mlxyz->screen->width / 2) * 0.0625,
		(double)(mlxyz->mouse->y - mlxyz->screen->height / 2) * 0.0625);
}

void	fractol_zoom_out(t_mlxyz *mlxyz, t_fractol *fractol)
{
	if (fractol->zoom < 180)
		return ;
	fractol_move(
		fractol,
		-(mlxyz->mouse->x - mlxyz->screen->width / 2) / 16,
		-(mlxyz->mouse->y - mlxyz->screen->height / 2) / 16);
	fractol->zoom /= 1.0625;
}
