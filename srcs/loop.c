/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:37:39 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/14 19:38:53 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <math.h>
#include <mlxyz.h>
#include <fractol.h>
#include <common.h>
#include <devices_events.h>
#include <txt.h>

void	loop_cpu(t_mlxyz *mlxyz, t_fractol *fractol)
{
	t_pixel	pixel;

	pixel.max_iter = fractol->max_iter;
	pixel.cr_custom = fractol->cr_custom;
	pixel.ci_custom = fractol->ci_custom;
	pixel.x = 0;
	while (pixel.x < fractol->w_w)
	{
		pixel.cr = (-(fractol->w_w / 2) + pixel.x) / fractol->zoom + fractol->x;
		pixel.y = 0;
		while (pixel.y < fractol->w_h)
		{
			pixel.ci = (-(fractol->w_h / 2) + pixel.y)
				/ fractol->zoom + fractol->y;
			pixel.index = pixel.x + fractol->w_p_x +
				((pixel.y + fractol->w_p_y) * fractol->win_width);
			pixel.max_iter = fractol->max_iter;
			iterations(fractol->fractal, &pixel);
			pixel.pos = ((double)(pixel.iterations) / fractol->max_iter);
			((unsigned int*)mlxyz->screen->canevas->data)[pixel.index] =
				color(&pixel, fractol->color_indice);
			pixel.y++;
		}
		pixel.x++;
	}
}

void	loop_opencl(t_mlxyz *mlxyz, t_fractol *fractol)
{
	t_opencl	*opencl;

	opencl = mlxyz->opencl;
	mlxyz->opencl->global_work_size[0] = fractol->w_w;
	mlxyz->opencl->global_work_size[1] = fractol->w_h;
	opencl->ret = clEnqueueWriteBuffer(opencl->command_queue, opencl->mem[0],
		CL_TRUE, 0, sizeof(t_fractol), (void*)fractol, 0, NULL, NULL);
	clEnqueueNDRangeKernel(opencl->command_queue, opencl->kernel, 2, NULL,
		opencl->global_work_size, NULL, 0, NULL, NULL);
	opencl->ret = clEnqueueReadBuffer(opencl->command_queue, opencl->mem[1],
		CL_TRUE, 0, mlxyz->screen->width * mlxyz->screen->height * sizeof(int),
		(void*)mlxyz->screen->canevas->data, 0, NULL, NULL);
}

void	render_main(t_mlxyz *mlxyz, t_fractol *fractol)
{
	fractol->w_w = mlxyz->screen->width;
	fractol->w_h = mlxyz->screen->height;
	if (fractol->render % 2)
		loop_opencl(mlxyz, fractol);
	else
		loop_cpu(mlxyz, fractol);
}

void	render_aux(t_mlxyz *mlxyz, t_fractol fractol)
{
	t_vector2	v1;
	t_vector2	v2;

	fractol.w_p_x = 0;
	fractol.w_p_y = 70;
	fractol.w_w = 200;
	fractol.w_h = 200;

	v1.x = 0;
	v1.y = 70;
	v2.x = 199;
	v2.y = 269;

	fractol.zoom = 40;
	fractol.x = 0;
	fractol.y = 0;
	if (fractol.render % 2)
		loop_opencl(mlxyz, &fractol);
	else
		loop_cpu(mlxyz, &fractol);

	square(mlxyz->screen->canevas, v1, v2, 0xff0000);
}

void		loop(t_mlxyz *mlxyz)
{
	t_fractol	*fractol;

	fractol = mlxyz->app;
	refresh_input_devices(mlxyz, fractol);
	if (fractol->max_iter < 1)
		fractol->max_iter = 1;
	fractol->color_indice = ((double)(mlxyz->stats->now % 100000) / 100000);
	if (fractol->lock % 2)
	{
		fractol->cr_custom = (-(mlxyz->screen->width / 2) + mlxyz->mouse->x)
			/ fractol->zoom + fractol->x;
		fractol->ci_custom = (-(mlxyz->screen->height / 2) + mlxyz->mouse->y)
			/ fractol->zoom + fractol->y;
	}
	if (!(fractol->render % 2))
		ft_bzero(mlxyz->screen->canevas->data,
			mlxyz->screen->width * mlxyz->screen->height);
	render_main(mlxyz, fractol);
	render_aux(mlxyz, *fractol);
	draw_hud(mlxyz);
	mlx_put_image_to_window(mlxyz->mlx,
		mlxyz->screen->win, mlxyz->screen->canevas->id, 0, 0);
	txt_1(mlxyz, fractol);
	txt_2(mlxyz, fractol);
	txt_3(mlxyz, fractol);
}
