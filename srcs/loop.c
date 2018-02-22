/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:37:39 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/22 12:54:42 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <mlxyz.h>
#include <fractol.h>
#include <devices_events.h>
#include <math.h>

void	loop_cpu(t_mlxyz *mlxyz, t_fractol *fractol)
{
	if (fractol->fractal == 0)
		julia_loop(mlxyz, fractol);
	if (fractol->fractal == 1)
		mandelbrot_loop(mlxyz, fractol);
	if (fractol->fractal == 2)
		burning_ship_loop(mlxyz, fractol);
	if (fractol->fractal == 3)
		tricorn_loop(mlxyz, fractol);
}

int		loop_opencl(t_mlxyz *mlxyz, t_fractol *fractol, t_opencl *opencl)
{
	double params[7];

	params[0] = fractol->max_iter;
	params[1] = fractol->zoom;
	params[2] = fractol->x;
	params[3] = fractol->y;
	params[4] = fractol->color_indice;
	params[5] = fractol->x + (-(mlxyz->screen->width / 2) + mlxyz->mouse->x)
		/ fractol->zoom;
	params[6] = fractol->y + (-(mlxyz->screen->height / 2) + mlxyz->mouse->y)
		/ fractol->zoom;
	opencl->ret = clEnqueueWriteBuffer(opencl->command_queue, opencl->mem[0],
		CL_TRUE, 0, 7 * sizeof(double), (void*)params, 0, NULL, NULL);
	clEnqueueNDRangeKernel(opencl->command_queue, opencl->kernel, 2, NULL,
		opencl->global_work_size, NULL, 0, NULL, NULL);
	opencl->ret = clEnqueueReadBuffer(opencl->command_queue, opencl->mem[1],
		CL_TRUE, 0, mlxyz->screen->width * mlxyz->screen->height * sizeof(int),
		(void*)mlxyz->screen->canevas->data, 0, NULL, NULL);
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
	app->color_indice = ((double)(mlxyz->stats->now % 100000) / 100000);
	if (app->render % 2)
		loop_opencl(mlxyz, app, opencl);
	else
		loop_cpu(mlxyz, app);
	draw_hud(mlxyz);
	mlx_put_image_to_window(mlxyz->mlx,
		mlxyz->screen->win, mlxyz->screen->canevas->id, 0, 0);
	return (1);
}
