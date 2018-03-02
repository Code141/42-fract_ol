/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:44:58 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/02 20:45:08 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxyz.h>
#include <libft.h>
#include <fractol.h>
#include <opencl.h>

t_fractol	*init_fractol(char *fractal_name)
{
	t_fractol	*fractol;

	fractol = (t_fractol*)malloc(sizeof(t_fractol));
	if (!fractol)
		crash_fractol("Malloc");
	ft_bzero(fractol, sizeof(t_fractol));
	set_fractal_type(fractal_name, fractol);
	fractol->render = 0;
	fractol->max_iter = 100;
	fractol->zoom = 180;
	fractol->x = 0;
	fractol->y = 0;
	return (fractol);
}

int			main(int argc, char **argv)
{
	t_fractol	*fractol;
	t_mlxyz		*mlxyz;
	t_opencl	*opencl;

	argc--;
	argv++;
	if (argc == 0)
		show_usage();
	mlxyz = mlxyz_init();
	fractol = init_fractol(*argv);
	opencl = init_opencl();
	if (set_kernel(opencl, mlxyz, fractol->fractal_name))
		fractol->render = 1;
	fractol->opencl = opencl;
	mlxyz->app = fractol;
	mlx_loop(mlxyz->mlx);
	return (0);
}
