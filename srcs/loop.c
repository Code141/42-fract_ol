/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:37:39 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/20 12:11:47 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <mlxyz.h>
#include <fractol.h>
#include <devices_events.h>

int		loop_opencl(t_mlxyz *mlxyz, t_fractol *fractol, t_opencl *opencl)
{
	double params[4];

	params[0] = fractol->max_iter;
	params[1] = fractol->zoom;
	params[2] = fractol->x;
	params[3] = fractol->y;

	opencl->ret = clEnqueueWriteBuffer(opencl->command_queue, opencl->mem[0], CL_TRUE, 0, 4 * sizeof(double), (void*)params, 0, NULL, NULL);

	clEnqueueNDRangeKernel(opencl->command_queue, opencl->kernel, 2, NULL,
			opencl->global_work_size, NULL, 0, NULL, NULL);

	opencl->ret = clEnqueueReadBuffer(opencl->command_queue, opencl->mem[1], CL_TRUE, 0, mlxyz->screen->width * mlxyz->screen->height*sizeof(int), (void*)mlxyz->screen->canevas->data, 0, NULL, NULL);
	return (1);
}

int		loop(t_mlxyz *mlxyz)
{
	t_fractol	*app;
	t_opencl	*opencl;

	app = mlxyz->app;
	opencl = app->opencl;

	refresh_input_devices(mlxyz, app);
	refresh_stats(mlxyz->stats);
//	ft_bzero(mlxyz->screen->canevas->data,
//		mlxyz->screen->canevas->width * mlxyz->screen->canevas->height * 4);

	//	render(mlxyz);

	if (app->render % 2)
		loop_opencl(mlxyz, app, opencl);
	else
		fractol(mlxyz, app);

	draw_hud(mlxyz);
	mlx_put_image_to_window(mlxyz->mlx,
		mlxyz->screen->win, mlxyz->screen->canevas->id, 0, 0);

	return (1);
}
