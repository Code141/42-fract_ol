/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:37:39 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/06 16:28:36 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <math.h>
#include <mlxyz.h>
#include <fractol.h>
#include <common.h>
#include <devices_events.h>


void	loop_cpu(t_mlxyz *mlxyz, t_fractol *fractol)
{
	t_pixel	pixel;

	pixel.max_iter = fractol->max_iter;
	pixel.width = mlxyz->screen->width;
	pixel.height = mlxyz->screen->height;
	pixel.cr_custom = fractol->cr_custom;
	pixel.ci_custom = fractol->ci_custom;
	pixel.x = -(mlxyz->screen->width / 2);

	while (pixel.x < pixel.width)
	{
		pixel.cr = (-(pixel.width / 2) + pixel.x)
			/ fractol->zoom + fractol->x;
		pixel.y = 0;
		while (pixel.y < pixel.height)
		{
			pixel.ci = (-(pixel.height / 2) + pixel.y)
				/ fractol->zoom + fractol->y;
			pixel.index = pixel.x + (pixel.y * pixel.width);
			pixel.max_iter = fractol->max_iter;

			julia(&pixel);
			iterations(fractol->fractal, &pixel);

			pixel.pos = ((float)(pixel.iterations) / fractol->max_iter);

((unsigned int*)mlxyz->screen->canevas->data)[pixel.index] = color(&pixel, fractol->color_indice);
			pixel.y++;
		}
		pixel.x++;
	}
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
		fractol->cr_custom = (-(mlxyz->screen->width / 2) + mlxyz->mouse->x)
			/ fractol->zoom;
		fractol->ci_custom = (-(mlxyz->screen->height / 2) + mlxyz->mouse->y)
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
