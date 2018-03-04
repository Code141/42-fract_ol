/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:44:58 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/04 19:52:33 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxyz.h>
#include <libft.h>
#include <fractol.h>

int			set_kernel(t_opencl *opencl, int x, int y, char *fractale_name)
{
	char	*path;
	char	*tmp;
	char	*source_str[3];

	tmp = ft_strjoin("./srcs/kernel/", fractale_name);
	path = ft_strjoin(tmp, ".cl");
	free(tmp);

	source_str[0] = ft_get_file("./includes/fractol_struct.h");
	source_str[1] = ft_get_file(path);
	source_str[2] = ft_get_file("./srcs/kernel/main.cl");

	free(path);
	if (!source_str[0] || !source_str[1])
		return (0);

	if (!load_kernel(opencl, source_str, 3))
		return (0);
	free(source_str[0]);
	free(source_str[1]);
	free(source_str[2]);

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
		crash_fractol("Malloc");
	ft_bzero(fractol, sizeof(t_fractol));
	set_fractal_type(fractal_name, fractol);
	fractol->render = 1;
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

	argc--;
	argv++;
	if (argc == 0)
		show_usage();
	mlxyz = mlxyz_init();
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
