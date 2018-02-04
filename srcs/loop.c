/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:37:39 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/04 18:15:52 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	refresh_keyboard(t_mlxyz *mlxyz)
{
	if (mlxyz->keyboard->key[53])
		close_fdf(mlxyz);
}

void	refresh_mouse(t_mlxyz *mlxyz)
{
	int			delta_x;
	int			delta_y;

	if (mlxyz->mouse->button[4])
	{
		mlxyz->mouse->button[4] = 0;
	}
	if (mlxyz->mouse->button[5])
	{
		mlxyz->mouse->button[5] = 0;
	}
	if (mlxyz->mouse->button[1])
	{
		delta_x = mlxyz->mouse->last_x - mlxyz->mouse->x;
		delta_y = mlxyz->mouse->last_y - mlxyz->mouse->y;
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

int		loop(t_mlxyz *mlxyz)
{
	refresh_stats(mlxyz->stats);
	ft_bzero(mlxyz->screen->canevas->data,
			mlxyz->screen->canevas->width * mlxyz->screen->canevas->height * 4);
	refresh_input_devices(mlxyz);

	//	render(mlxyz);

	draw_hud(mlxyz);
	mlx_put_image_to_window(mlxyz->mlx,
			mlxyz->screen->win, mlxyz->screen->canevas->id, 0, 0);
	return (1);
}
