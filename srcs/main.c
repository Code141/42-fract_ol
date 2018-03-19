/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:44:58 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/19 18:59:41 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxyz.h>
#include <libft.h>
#include <fractol.h>
#include <devices_events.h>
#include <cl.h>
#include <fractol_loop.h>

void		reset_fractol(t_fractol *fractol)
{
	fractol->lock = 0;
	fractol->max_iter = 50;
	fractol->zoom = 180;
	fractol->x = 0;
	fractol->y = 0;
	fractol->cr_custom = 0;
	fractol->ci_custom = 0;
	fractol->color = 1;
}

t_fractol	*init_fractol(char *fractal_name)
{
	t_fractol	*fractol;

	fractol = (t_fractol*)malloc(sizeof(t_fractol));
	if (!fractol)
		crash_fractol("Malloc into init_fractol");
	ft_bzero(fractol, sizeof(t_fractol));
	set_fractal_type(fractal_name, fractol);
	fractol->render = 0;
	reset_fractol(fractol);
	return (fractol);
}

t_mlxyz		*init_mlxyz(int win_width, int win_height)
{
	t_mlxyz		*mlxyz;

	mlxyz = mlxyz_init(win_width, win_height);
	mlxyz->screen = new_screen(mlxyz->mlx, win_width, win_height, "Fractol");
	mlxyz->stats = new_stats();
	mlxyz->hud = new_hud();
	mlxyz->hud->graphs[0] = new_graph(95, 60, mlxyz->stats->fps);
	mlxyz->hud->graphs[0]->x = 2;
	mlxyz->hud->graphs[0]->y = 2;
	mlxyz->hud->graphs[1] = new_graph(98, 60, mlxyz->stats->ms);
	mlxyz->hud->graphs[1]->color_min.hex = 0x00ffff;
	mlxyz->hud->graphs[1]->color_max.hex = 0xff0000;
	mlxyz->hud->graphs[1]->x = 99;
	mlxyz->hud->graphs[1]->y = 2;
	mlxyz->opencl = init_opencl();
	hooks(mlxyz);
	return (mlxyz);
}

int			main(int argc, char **argv)
{
	t_fractol	*fractol;
	t_mlxyz		*mlxyz;
	int			win_width;
	int			win_height;

	win_width = 1024;
	win_height = 786;
	argc--;
	argv++;
	if (argc == 0)
		show_usage();
	mlxyz = init_mlxyz(win_width, win_height);
	fractol = init_fractol(*argv);
	set_kernel(mlxyz->opencl, win_width, win_height);
	fractol->win_width = win_width;
	fractol->win_height = win_height;
	mlxyz->app = fractol;
	mlxyz->keyboard->key_press = &key_press;
	mlxyz_run_loop(mlxyz, &loop);
	return (0);
}
