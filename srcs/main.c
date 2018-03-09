/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:44:58 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/08 19:48:28 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxyz.h>
#include <libft.h>
#include <fractol.h>
#include <devices_events.h>
#include <cl.h>

t_fractol	*init_fractol(char *fractal_name)
{
	t_fractol	*fractol;

	fractol = (t_fractol*)malloc(sizeof(t_fractol));
	if (!fractol)
		crash_fractol("Malloc into init_fractol");
	ft_bzero(fractol, sizeof(t_fractol));
	set_fractal_type(fractal_name, fractol);
	fractol->render = 1;
	fractol->lock = 1;
	fractol->max_iter = 50;
	fractol->zoom = 180;
	fractol->x = 0;
	fractol->y = 0;
	return (fractol);
}

int			main(int argc, char **argv)
{
	t_fractol	*fractol;
	t_mlxyz		*mlxyz;
	int			win_width;
	int			win_height;

	win_width = 1800;
	win_height = 1000;

	argc--;
	argv++;
	if (argc == 0)
		show_usage();
	mlxyz = mlxyz_init(win_width, win_height);
	fractol = init_fractol(*argv);
	if (set_kernel(mlxyz->opencl, mlxyz->screen->width, mlxyz->screen->height))
		fractol->render = 1;
	fractol->win_width = win_width;
	fractol->win_height= win_height;

	mlxyz->app = fractol;
	mlxyz->keyboard->key_press = &key_press;
	mlxyz_run_loop(mlxyz, &loop);
	return (0);
}
