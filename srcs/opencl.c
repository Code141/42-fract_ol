/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 02:15:09 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/15 08:01:01 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <OpenCL/cl.h>
#include <libft.h>

#define MEM_SIZE (128)
#define MAX_SOURCE_SIZE (0x100000)
cl_uint		get_platforms(cl_platform_id **platforms)
{
	cl_uint	platforms_count;

	platforms_count = 0;
	clGetPlatformIDs(0, NULL, &platforms_count);
	if (platforms_count)
	{
		*platforms = (cl_platform_id*)malloc(sizeof(cl_platform_id) * platforms_count);
		clGetPlatformIDs(platforms_count, *platforms, NULL);
	}
	else
		ft_putstr("No platform available\n");
	return (platforms_count);
}

cl_uint		get_devices(cl_platform_id platform, cl_device_id	**devices)
{
	cl_uint		devices_count;

	devices_count = 0;
	clGetDeviceIDs(platform, CL_DEVICE_TYPE_ALL, 0, NULL, &devices_count);
	if (devices_count)
	{
		*devices = (cl_device_id*)malloc(sizeof(cl_device_id) * devices_count);
		clGetDeviceIDs(platform, CL_DEVICE_TYPE_ALL, devices_count, *devices, NULL);
	}
	else
		ft_putstr("No devices available\n");
	return (devices_count);
}

void		print_plateform_info(cl_platform_id platform, char *name, cl_platform_info type)
{
	char*			info;
	size_t			info_size;

	clGetPlatformInfo(platform, type, 0, NULL, &info_size);
	info = (char*)malloc(info_size);
	clGetPlatformInfo(platform, type, info_size, info, NULL);
	ft_putstr(name);
	ft_putstr("	: ");
	ft_putstr(info);
	ft_putstr("\n");
	free(info);
}

void		print_device_info(cl_device_id device, char *name, cl_device_info type)
{
	char*			info;
	size_t			info_size;
	cl_uint			c_u;

	if (type == CL_DEVICE_MAX_COMPUTE_UNITS)
	{
		clGetDeviceInfo(device, type, sizeof(c_u), &c_u, NULL);
		ft_putstr(name);
		ft_putstr("	: ");
		ft_putnbr(c_u);
		ft_putstr("\n");
	}
	else
	{
		clGetDeviceInfo(device, type, 0, NULL, &info_size);
		info = (char*)malloc(info_size);
		clGetDeviceInfo(device, type, info_size, info, NULL);
		ft_putstr(name);
		ft_putstr("	: ");
		ft_putstr(info);
		ft_putstr("\n");
		free(info);
	}
}

void		print_available_plateforms(cl_platform_id *platforms, cl_uint num_platforms)
{
	int i;

	ft_putstr("Available plateforms :\n");
	i = 0;
	while (i < num_platforms)
	{
		ft_putstr("	Plateform [");
		ft_putnbr(i);
		ft_putstr("] :\n");
		print_plateform_info(platforms[i], "		Name	", CL_PLATFORM_NAME);
		print_plateform_info(platforms[i], "		Vendor	", CL_PLATFORM_VENDOR);
		print_plateform_info(platforms[i], "		Version	", CL_PLATFORM_VERSION);
		print_plateform_info(platforms[i], "		Profile	", CL_PLATFORM_PROFILE);
		print_plateform_info(platforms[i], "		Extensions", CL_PLATFORM_EXTENSIONS);
		ft_putstr("\n");
		i++;
	}
}

void		print_available_devices(cl_device_id *devices, cl_uint num_devices)
{
	int i;
	
	ft_putstr("Available devices :\n");
	i = 0;
	while (i < num_devices)
	{
		ft_putstr("	Device [");
		ft_putnbr(i);
		ft_putstr("] :\n");
		print_device_info(devices[i], "		device		", CL_DEVICE_NAME);
		print_device_info(devices[i], "		hardware version", CL_DEVICE_VERSION);
		print_device_info(devices[i], "		software version", CL_DRIVER_VERSION);
		print_device_info(devices[i], "		opencl c version", CL_DEVICE_OPENCL_C_VERSION);
		print_device_info(devices[i], "		parallel compute units", CL_DEVICE_MAX_COMPUTE_UNITS);
		ft_putstr("\n");
		i++;
	}
}


int			init_opencl()
{
	cl_uint			num_platforms;
	cl_platform_id	*platforms;
	cl_platform_id	platform;

	cl_uint			num_devices;
	cl_device_id	*devices;
	cl_device_id	device;


	ft_putstr("- Init OpenCl -\n");
	num_platforms = get_platforms(&platforms);
	if (!num_platforms)
		return (0);

	print_available_plateforms(platforms, num_platforms);

	platform = platforms[0];
	ft_putstr("Plateform [");
	ft_putnbr(0);
	ft_putstr("] selected.\n");
	ft_putstr("\n");

	num_devices = get_devices(platform, &devices);
	if (!num_devices)
		return (0);

	print_available_devices(devices, num_devices);
	device = devices[1];
	ft_putstr("Device [");
	ft_putnbr(1);
	ft_putstr("] selected.\n");

/******************************************************************************/

	cl_int ret;

	char string[MEM_SIZE];

	/* Load the source code containing the kernel*/
	char *loaded_kernel;
	loaded_kernel = "./srcs/kernel/mandelbrot.cl";
	char *source_str;
	size_t source_size;
	source_str = ft_get_file(loaded_kernel);
	if (!source_str)
	{
		ft_putstr("Failed to load kernel.\n");
		return (0);
	}
	source_size = ft_strlen(source_str);
	/* Create OpenCL context */
	cl_context context;
	context = clCreateContext(NULL, 1, &device, NULL, NULL, &ret);
	/* Create Command Queue */
	cl_command_queue command_queue;
	command_queue = clCreateCommandQueue(context, device, 0, &ret);
	/* Create Kernel Program from the source */
	cl_program program;
	program = clCreateProgramWithSource(context, 1, (const char **)&source_str,
			(const size_t *)&source_size, &ret);
	free(source_str);

	/* Build Kernel Program */
	ret = clBuildProgram(program, 1, &device, NULL, NULL, NULL);
	/* Create OpenCL Kernel */
	cl_kernel kernel;
	kernel = clCreateKernel(program, "mandelbrot", &ret);

	/* Create Memory Buffer */
	cl_mem mem_cr;
	cl_mem mem_ci;
	cl_mem mem_i;
	cl_mem mem_r;

	mem_cr = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(double), NULL, &ret);
	mem_ci = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(double), NULL, &ret);
	mem_i = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(int), NULL, &ret);
	mem_r = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(int), NULL, &ret);

	/* Set OpenCL Kernel Parameters */
	ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void*)&mem_cr);
	ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void*)&mem_ci);
	ret = clSetKernelArg(kernel, 2, sizeof(cl_mem), (void*)&mem_i);
	ret = clSetKernelArg(kernel, 3, sizeof(cl_mem), (void*)&mem_r);


	double cr;
	double ci;
	int i;
	int r;

	cr = 100;
	ci = 10;
	i = 1;
	r = 0;

	ret = clEnqueueWriteBuffer(command_queue, mem_cr, CL_TRUE, 0, sizeof(double), (void*)&cr, 0, NULL, NULL);
	ret = clEnqueueWriteBuffer(command_queue, mem_ci, CL_TRUE, 0, sizeof(double), (void*)&ci, 0, NULL, NULL);
	ret = clEnqueueWriteBuffer(command_queue, mem_i, CL_TRUE, 0, sizeof(int), (void*)&i, 0, NULL, NULL);

	/* Execute OpenCL Kernel */
	ret = clEnqueueTask(command_queue, kernel, 0, NULL, NULL);

	/* Copy results from the memory buffer */
	ret = clEnqueueReadBuffer(command_queue, mem_r, CL_TRUE, 0, sizeof(int), (void*)&r, 0, NULL, NULL);

	/* Display Result */
	ft_putnbr(r);


	/* Finalization */
	ret = clFlush(command_queue);
	ret = clFinish(command_queue);
	ret = clReleaseKernel(kernel);
	ret = clReleaseProgram(program);
	ret = clReleaseMemObject(mem_ci);
	ret = clReleaseMemObject(mem_cr);
	ret = clReleaseMemObject(mem_i);
	ret = clReleaseMemObject(mem_r);
	ret = clReleaseCommandQueue(command_queue);
	ret = clReleaseContext(context);
	return (1);
}
