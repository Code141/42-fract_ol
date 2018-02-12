/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 03:50:08 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/12 03:50:42 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxyz.h>
#include <fractol.h>

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


