/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:37:39 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/17 08:15:38 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <mlxyz.h>
#include <fractol.h>
#include <devices_events.h>

int		loop(t_mlxyz *mlxyz)
{
	t_fractol	*app;
	t_opencl	*opencl;

	app = mlxyz->app;
	opencl = app->opencl;

	refresh_input_devices(mlxyz, mlxyz->app);
	refresh_stats(mlxyz->stats);
	ft_bzero(mlxyz->screen->canevas->data,
		mlxyz->screen->canevas->width * mlxyz->screen->canevas->height * 4);

	fractol(mlxyz, mlxyz->app);

	//	render(mlxyz);

	loop_opencl(mlxyz, opencl);

	draw_hud(mlxyz);
	mlx_put_image_to_window(mlxyz->mlx,
		mlxyz->screen->win, mlxyz->screen->canevas->id, 0, 0);
	return (1);
}
