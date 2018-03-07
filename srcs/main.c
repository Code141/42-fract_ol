/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:44:58 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/06 18:46:45 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxyz.h>
#include <libft.h>
#include <fractol.h>

int			set_kernel(t_opencl *opencl, int x, int y, char *fractale_name)
{
	char	*path;
	char	*tmp;
	char	*source_str[9];

	tmp = ft_strjoin("./srcs/fractals/", fractale_name);
	path = ft_strjoin(tmp, ".c");
	free(tmp);
	source_str[0] = ft_get_file("./srcs/fractals/julia.c");
	source_str[1] = ft_get_file("./srcs/fractals/mandelbrot.c");
	source_str[2] = ft_get_file("./srcs/fractals/burning_ship.c");
	source_str[3] = ft_get_file("./srcs/fractals/tricorn.c");
	source_str[4] = ft_get_file("./srcs/fractals/bullet.c");
	source_str[5] = ft_get_file("./srcs/fractals/julia_fun.c");
	source_str[6] = ft_get_file("./lib/mlxyz/srcs/color/rgba.c");
	source_str[7] = ft_get_file("./srcs/common.c");
	source_str[8] = ft_get_file("./srcs/kernel.cl");
	free(path);
	if (!source_str[0] || !source_str[1])
		return (0);
	if (!load_kernel(opencl, source_str, 9))
		return (0);
	free(source_str[0]);
	free(source_str[1]);
	free(source_str[2]);
	free(source_str[3]);
	free(source_str[4]);
	free(source_str[5]);
	free(source_str[6]);

	opencl->global_work_size[0] = x;
	opencl->global_work_size[1] = y;
	opencl->global_work_size[2] = 1;
	opencl->mem[0] = clCreateBuffer(opencl->context, CL_MEM_READ_WRITE,
		sizeof(t_fractol), NULL, &opencl->ret);
	opencl->mem[1] = clCreateBuffer(opencl->context, CL_MEM_READ_WRITE,
		x * y * sizeof(int), NULL, &opencl->ret);
	opencl->ret = clSetKernelArg(opencl->kernel,
		0, sizeof(cl_mem), (void*)&opencl->mem[0]);
	opencl->ret = clSetKernelArg(opencl->kernel,
			1, sizeof(cl_mem), (void*)&opencl->mem[1]);
	return (1);
}

t_fractol	*init_fractol(char *fractal_name)
{
	t_fractol	*fractol;

	fractol = (t_fractol*)malloc(sizeof(t_fractol));
	if (!fractol)
		crash_fractol("Malloc into init_fractol");
	ft_bzero(fractol, sizeof(t_fractol));
	set_fractal_type(fractal_name, fractol);
	fractol->render = 1;
	fractol->lock = 0;
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

	argc--;
	argv++;
	if (argc == 0)
		show_usage();
	mlxyz = mlxyz_init(1024, 786);
	fractol = init_fractol(*argv);
	if (set_kernel(
				mlxyz->opencl,
				mlxyz->screen->width,
				mlxyz->screen->height,
				fractol->fractal_name))
		fractol->render = 1;
	mlxyz->app = fractol;
	mlx_loop(mlxyz->mlx);
	return (0);
}
