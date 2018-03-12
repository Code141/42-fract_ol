/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:37:39 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/08 20:04:56 by gelambin         ###   ########.fr       */
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
	fractol->w_w = 1400;
	fractol->w_h = 1000;
	fractol->w_p_x = 200;
	fractol->w_p_y = 0;
	if (fractol->render % 2)
		loop_opencl(mlxyz, fractol);
	else
		loop_cpu(mlxyz, fractol);
}

void	render_aux(t_mlxyz *mlxyz, t_fractol fractol)
{
	t_vector2	v1;
	t_vector2	v2;

	fractol.w_p_y = 0;
	fractol.w_w = 200;
	fractol.w_h = 200;
	fractol.w_p_x = fractol.win_width - fractol.w_w;

	v1.x = fractol.win_width - fractol.w_w;
	v1.y = 0;
	v2.x = fractol.win_width - fractol.w_w + 199;
	v2.y = 200;


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
	int			i;
	
	fractol = mlxyz->app;
	refresh_input_devices(mlxyz, fractol);
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

/*----------------------------------------------------------------------------*/

	char *str;
	str = ft_itoa(mlxyz->stats->fps[0]);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 6, 1, 0x000000, str);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 31, 1, 0x000000, "Fps");
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 5, 0, 0xffffff, str);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 30, 0, 0xffffff, "Fps");
	free(str);
/**/
	str = ft_itoa(mlxyz->stats->ms[0]);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 101, 1, 0x000000, str);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 126, 1, 0x000000, "Ms");
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 100, 0, 0xffffff, str);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 125, 0, 0xffffff, "Ms");
	free(str);
/**/
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 5, 80, 0xffffff, "Iterations :");

	str = ft_itoa(fractol->max_iter);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 130, 80, 0xffffff, str);
	free(str);
/**/
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 5, 100, 0xffffff, "Render :");
 	if (fractol->render % 2)
		mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 90, 100, 0x00ff00, "GPU");
	else
		mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 90, 100, 0x00ff0000, "CPU");
/**/
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 5, 120, 0xfffffff, "Lock :");
 	if (fractol->lock % 2)
		mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 70, 120, 0x00ff00, "On");
	else
		mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 70, 120, 0xffff00, "Off");
/**/
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 5, 140, 0xfffffff, "Zoom :");
	str = ft_itoa(fractol->zoom);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 70, 140, 0xffffff, str);
	free(str);
/**/





	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 5, 160, 0xfffffff, "Cr :");
	if (fractol->cr_custom < 0)
		mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 50, 160, 0xffffff, "-");
	str = ft_itoa(fabs(fractol->cr_custom));
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 65, 160, 0xffffff, str);
	free(str);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 75, 160, 0xffffff, ".");
	str = ft_itoa(fabs((fractol->cr_custom - ((int)fractol->cr_custom))) * 100000);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 85, 160, 0xffffff, str);
	free(str);


	
	
	
	
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 5, 180, 0xfffffff, "Ci :");
	if (fractol->ci_custom > 0)
		mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 50, 180, 0xffffff, "-");
	str = ft_itoa(fabs(fractol->ci_custom));
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 65, 180, 0xffffff, str);
	free(str);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 75, 180, 0xffffff, ".");
	str = ft_itoa(fabs((fractol->ci_custom - ((int)fractol->ci_custom))) * 100000);
	mlx_string_put(mlxyz->mlx, mlxyz->screen->win, 85, 180, 0xffffff, str);
	free(str);


	
}
