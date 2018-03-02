/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:57:39 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/02 17:30:18 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <OpenCL/cl.h>
#include <opencl.h>
#include <libft.h>
#include <mlxyz.h>
#include <fractol.h>

int			get_platforms(t_opencl *opencl)
{
	opencl->platforms_count = 0;
	clGetPlatformIDs(0, NULL, &opencl->platforms_count);
	if (opencl->platforms_count)
	{
		opencl->platforms = (cl_platform_id*)malloc(
			sizeof(cl_platform_id) * opencl->platforms_count);
		clGetPlatformIDs(opencl->platforms_count, opencl->platforms, NULL);
		return (1);
	}
	else
		ft_putstr("No platform available\n");
	return (0);
}

int			get_devices(t_opencl *opencl)
{
	opencl->devices_count = 0;
	clGetDeviceIDs(opencl->platform, CL_DEVICE_TYPE_ALL, 0, NULL,
		&opencl->devices_count);
	if (opencl->devices_count)
	{
		opencl->devices = (cl_device_id*)malloc(
			sizeof(cl_device_id) * opencl->devices_count);
		clGetDeviceIDs(opencl->platform, CL_DEVICE_TYPE_ALL,
			opencl->devices_count, opencl->devices, NULL);
		return (1);
	}
	else
		ft_putstr("No devices available\n");
	return (0);
}

int			load_kernel(t_opencl *opencl, char *kernel_name)
{
	char	*path;
	char	*tmp;
	char	*source_str;
	size_t	source_size;

	tmp = ft_strjoin("./srcs/kernel/", kernel_name);
	path = ft_strjoin(tmp, ".cl");
	free(tmp);
	source_str = ft_get_file(path);
	free(path);
	if (!source_str)
		return (0);
	source_size = ft_strlen(source_str);
	opencl->program = clCreateProgramWithSource(opencl->context, 1,
		(const char **)&source_str, (const size_t *)&source_size, &opencl->ret);
	opencl->ret = clBuildProgram(opencl->program, 1, &opencl->device,
		"-cl-fast-relaxed-math", NULL, NULL);
	opencl->kernel = clCreateKernel(opencl->program, kernel_name, &opencl->ret);
	free(source_str);
	if (opencl->ret)
		return (0);
	return (1);
}

t_opencl	*init_opencl(void)
{
	t_opencl	*opencl;

	opencl = (t_opencl*)malloc(sizeof(t_opencl));
	if (!opencl)
		return (NULL);
	ft_bzero(opencl, sizeof(t_opencl));
	ft_putstr("- Init OpenCl -\n");
	if (!get_platforms(opencl))
		return (NULL);
	if (!get_devices(opencl))
		return (NULL);
	opencl->platform = opencl->platforms[0];
	opencl->device = opencl->devices[1];
	opencl->context = clCreateContext(NULL, 1, &opencl->device, NULL, NULL,
		&opencl->ret);
	opencl->command_queue = clCreateCommandQueue(opencl->context,
		opencl->device, 0, &opencl->ret);
	free(opencl->platforms);
	free(opencl->devices);
	return (opencl);
}

int			set_kernel(t_opencl *opencl, t_mlxyz *mlxyz, char *fractale_name)
{
	if (!load_kernel(opencl, fractale_name))
		return (0);
	opencl->global_work_size[0] = mlxyz->screen->width;
	opencl->global_work_size[1] = mlxyz->screen->height;
	opencl->global_work_size[2] = 1;
	opencl->mem[0] = clCreateBuffer(opencl->context, CL_MEM_READ_WRITE,
		7 * sizeof(double), NULL, &opencl->ret);
	opencl->mem[1] = clCreateBuffer(opencl->context, CL_MEM_READ_WRITE,
		mlxyz->screen->width * mlxyz->screen->height * sizeof(int),
		NULL, &opencl->ret);
	opencl->ret = clSetKernelArg(opencl->kernel,
		0, sizeof(cl_mem), (void*)&opencl->mem[0]);
	opencl->ret = clSetKernelArg(opencl->kernel,
		1, sizeof(cl_mem), (void*)&opencl->mem[1]);
	return (1);
}
