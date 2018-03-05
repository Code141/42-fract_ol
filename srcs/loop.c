/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:37:39 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/05 23:09:59 by gelambin         ###   ########.fr       */
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
	if (fractol->fractal == 4)
		bullet_loop(mlxyz, fractol);
}

void	loop_opencl(t_mlxyz *mlxyz, t_fractol *fractol, t_opencl *opencl)
{
	opencl->ret = clEnqueueWriteBuffer(opencl->command_queue, opencl->mem[0],
		CL_TRUE, 0, sizeof(t_fractol), (void*)fractol, 0, NULL, NULL);
	clEnqueueNDRangeKernel(opencl->command_queue, opencl->kernel, 2, NULL,
		opencl->global_work_size, NULL, 0, NULL, NULL);
	opencl->ret = clEnqueueReadBuffer(opencl->command_queue, opencl->mem[1],
		CL_TRUE, 0, mlxyz->screen->width * mlxyz->screen->height * sizeof(int),
		(void*)mlxyz->screen->canevas->data, 0, NULL, NULL);
}

int		loop(t_mlxyz *mlxyz)
{
	t_fractol	*fractol;

	fractol = mlxyz->app;

	refresh_input_devices(mlxyz, fractol);
	refresh_stats(mlxyz->stats);

	fractol->color_indice = ((double)(mlxyz->stats->now % 100000) / 100000);
	if (!fractol->lock % 2)
	{
		fractol->cr = (-(mlxyz->screen->width / 2) + mlxyz->mouse->x)
			/ fractol->zoom;
		fractol->ci = (-(mlxyz->screen->height / 2) + mlxyz->mouse->y)
			/ fractol->zoom;
	}
	if (fractol->render % 2)
		loop_opencl(mlxyz, fractol, mlxyz->opencl);
	else
		loop_cpu(mlxyz, fractol);

	draw_hud(mlxyz);
	mlx_put_image_to_window(mlxyz->mlx,
		mlxyz->screen->win, mlxyz->screen->canevas->id, 0, 0);
	return (1);
}
