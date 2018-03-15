/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 12:49:13 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/15 23:21:09 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxyz.h>
#include <fractol.h>

void		unload_files(char **files, int i)
{
	while (i >= 0)
		if (files[i])
			free(files[i--]);
		else
			i--;
}

void		load_files(char **files_to_load)
{
	char	*name;
	int		i;

	i = 0;
	while (files_to_load[i])
	{
		name = files_to_load[i];
		ft_putstr("Loading : ");
		ft_putstr(name);
		ft_putstr("\n");
		files_to_load[i] = ft_get_file(files_to_load[i]);
		if (!files_to_load[i])
		{
			unload_files(files_to_load, i);
			files_to_load = NULL;
			ft_putstr("Can't load file \"");
			ft_putstr(name);
			ft_putstr("\"\n");
			crash_fractol(" Loading File Error");
		}
		i++;
	}
}

int			param_gl(t_opencl *opencl, int x, int y)
{
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

int			set_kernel(t_opencl *opencl, int x, int y)
{
	char	*source_str[12];

	source_str[0] = "./srcs/fractals/julia.c";
	source_str[1] = "./srcs/fractals/mandelbrot.c";
	source_str[2] = "./srcs/fractals/burning_ship.c";
	source_str[3] = "./srcs/fractals/tricorn.c";
	source_str[4] = "./srcs/fractals/bullet.c";
	source_str[5] = "./srcs/fractals/julia_fun.c";
	source_str[6] = "./srcs/fractals/sierpinski_carpet.c";
	source_str[7] = "./srcs/fractals/zappa.c";
	source_str[8] = "./lib/mlxyz/srcs/color/rgba.c";
	source_str[9] = "./srcs/common.c";
	source_str[10] = "./srcs/kernel.cl";
	source_str[11] = NULL;
	load_files(source_str);
	if (!load_kernel(opencl, source_str, 11))
	{
		unload_files(source_str, 11);
		return (0);
	}
	unload_files(source_str, 11);
	if (!param_gl(opencl, x, y))
		return (0);
	return (1);
}
