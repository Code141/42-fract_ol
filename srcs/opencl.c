/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 02:15:09 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/16 08:09:57 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <OpenCL/cl.h>
#include <opencl.h>
#include <libft.h>

#define MEM_SIZE (128)
#define MAX_SOURCE_SIZE (0x100000)

int			get_platforms(t_opencl *opencl)
{
	cl_uint	platforms_count;

	opencl->platforms_count = 0;
	clGetPlatformIDs(0, NULL, &opencl->platforms_count);
	if (opencl->platforms_count)
	{
		opencl->platforms = (cl_platform_id*)malloc(sizeof(cl_platform_id) * opencl->platforms_count);
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
	clGetDeviceIDs(opencl->platform, CL_DEVICE_TYPE_ALL, 0, NULL, &opencl->devices_count);
	if (opencl->devices_count)
	{
		opencl->devices = (cl_device_id*)malloc(sizeof(cl_device_id) * opencl->devices_count);
		clGetDeviceIDs(opencl->platform, CL_DEVICE_TYPE_ALL, opencl->devices_count, opencl->devices, NULL);
		return (1);
	}
	else
		ft_putstr("No devices available\n");
	return (0);
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

void		print_device_info(cl_device_id device, char *name, cl_device_info type, int num)
{
	char*			info;
	size_t			info_size;
	cl_uint			c_u;

	if (num)
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
		print_device_info(devices[i], "		device			", CL_DEVICE_NAME, 0);
		print_device_info(devices[i], "		hardware version	", CL_DEVICE_VERSION, 0);
		print_device_info(devices[i], "		software version	", CL_DRIVER_VERSION, 0);
		print_device_info(devices[i], "		opencl c version	", CL_DEVICE_OPENCL_C_VERSION, 0);
		print_device_info(devices[i], "		parallel compute units	", CL_DEVICE_MAX_COMPUTE_UNITS, 1);
		print_device_info(devices[i], "		device adress bits	", CL_DEVICE_ADDRESS_BITS, 1);
		print_device_info(devices[i], "		max work groupe size	", CL_DEVICE_MAX_WORK_GROUP_SIZE, 1);
		print_device_info(devices[i], "		max work groupe item size", CL_DEVICE_MAX_WORK_ITEM_SIZES, 1);
		print_device_info(devices[i], "		max work item dimentions", CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, 1);

	
	ft_putstr("\n");
		i++;
	}
}

int			load_kernel(t_opencl *opencl, char *load_kernel, char *kernel_name)
{
	char	*source_str;
	size_t	source_size;
	
	source_str = ft_get_file(load_kernel);
	if (!source_str)
	{
		ft_putstr("Failed to load kernel file.\n");
		return (0);
	}
	source_size = ft_strlen(source_str);
	opencl->program = clCreateProgramWithSource(opencl->context, 1,
		(const char **)&source_str, (const size_t *)&source_size, &opencl->ret);
	opencl->ret = clBuildProgram(opencl->program, 1, &opencl->device,
		NULL, NULL, NULL);
	opencl->kernel = clCreateKernel(opencl->program, kernel_name, &opencl->ret);
	free(source_str);
	return (1);
}

int			init_opencl(t_opencl	*opencl)
{

	ft_putstr("- Init OpenCl -\n");
	opencl = (t_opencl*)malloc(sizeof(t_opencl));
	if (!opencl)
		return (0);
	ft_bzero(opencl, sizeof(t_opencl));
	if (!get_platforms(opencl))
		return (0);
	if (!get_devices(opencl))
		return (0);
	opencl->platform = opencl->platforms[0];
	opencl->device = opencl->devices[1];

// Create OpenCL context
	opencl->context = clCreateContext(NULL, 1, &opencl->device, NULL, NULL, &opencl->ret);
// Create Command Queue
	opencl->command_queue = clCreateCommandQueue(opencl->context, opencl->device, 0, &opencl->ret);

/******************************************************************************/
	print_available_plateforms(opencl->platforms, opencl->platforms_count);
	ft_putstr("Plateform [");
	ft_putnbr(0);
	ft_putstr("] selected.\n\n");
	print_available_devices(opencl->devices, opencl->devices_count);
	ft_putstr("Device	  [");
	ft_putnbr(1);
	ft_putstr("] selected.\n");
/******************************************************************************/

	if (!load_kernel(opencl, "./srcs/kernel/mandelbrot.cl", "mandelbrot"))
		return (0);

// Create Memory Buffer
	cl_mem mem_cr;
	cl_mem mem_ci;
	cl_mem mem_i;
	cl_mem mem_r;

	mem_cr = clCreateBuffer(opencl->context, CL_MEM_READ_WRITE, sizeof(double), NULL, &opencl->ret);
	mem_ci = clCreateBuffer(opencl->context, CL_MEM_READ_WRITE, sizeof(double), NULL, &opencl->ret);
	mem_i = clCreateBuffer(opencl->context, CL_MEM_READ_WRITE, sizeof(int), NULL, &opencl->ret);
	mem_r = clCreateBuffer(opencl->context, CL_MEM_READ_WRITE, 10*10*sizeof(size_t), NULL, &opencl->ret);

// Set OpenCL Kernel Parameters
	opencl->ret = clSetKernelArg(opencl->kernel, 0, sizeof(cl_mem), (void*)&mem_cr);
	opencl->ret = clSetKernelArg(opencl->kernel, 1, sizeof(cl_mem), (void*)&mem_ci);
	opencl->ret = clSetKernelArg(opencl->kernel, 2, sizeof(cl_mem), (void*)&mem_i);
	opencl->ret = clSetKernelArg(opencl->kernel, 3, sizeof(cl_mem), (void*)&mem_r);

	double cr;
	double ci;
	int i;
	size_t r[10][10];

	cr = 100;
	ci = 10;
	i = 1;

	opencl->ret = clEnqueueWriteBuffer(opencl->command_queue, mem_cr, CL_TRUE, 0, sizeof(double), (void*)&cr, 0, NULL, NULL);
	opencl->ret = clEnqueueWriteBuffer(opencl->command_queue, mem_ci, CL_TRUE, 0, sizeof(double), (void*)&ci, 0, NULL, NULL);
	opencl->ret = clEnqueueWriteBuffer(opencl->command_queue, mem_i, CL_TRUE, 0, sizeof(int), (void*)&i, 0, NULL, NULL);

	// Execute OpenCL Kernel
//	opencl->ret = clEnqueueTask(opencl->command_queue, opencl->kernel, 0, NULL, NULL);
	
	int x;
	int y;

	x = 1;
	y = 1;
	const size_t global_work_size = 10;//x * y;
	cl_uint work_dim;

	work_dim = 1;
	clEnqueueNDRangeKernel (
		opencl->command_queue,
		opencl->kernel,
		work_dim,
		NULL,
		&global_work_size,
		(const size_t*)NULL,
		0, NULL, NULL);


// Copy results from the memory buffer
	opencl->ret = clEnqueueReadBuffer(opencl->command_queue, mem_r, CL_TRUE, 0, 10*10*sizeof(size_t), (void*)&r, 0, NULL, NULL);

// Display Result
 int a;
	a = 0;
 printf("%zu, %zu, %zu, %zu, %zu, %zu, %zu\n",
		   r[a][0],r[a][1],r[a][2],r[a][3],r[a][4],r[a][5],r[a][6]);
	a = 1;
 printf("%zu, %zu, %zu, %zu, %zu, %zu, %zu\n",
		   r[a][0],r[a][1],r[a][2],r[a][3],r[a][4],r[a][5],r[a][6]);
	a = 2;
 printf("%zu, %zu, %zu, %zu, %zu, %zu, %zu\n",
		   r[a][0],r[a][1],r[a][2],r[a][3],r[a][4],r[a][5],r[a][6]);
	a = 3;
 printf("%zu, %zu, %zu, %zu, %zu, %zu, %zu\n",
		   r[a][0],r[a][1],r[a][2],r[a][3],r[a][4],r[a][5],r[a][6]);
	a = 4;
 printf("%zu, %zu, %zu, %zu, %zu, %zu, %zu\n",
		   r[a][0],r[a][1],r[a][2],r[a][3],r[a][4],r[a][5],r[a][6]);
	a = 5;
 printf("%zu, %zu, %zu, %zu, %zu, %zu, %zu\n",
		   r[a][0],r[a][1],r[a][2],r[a][3],r[a][4],r[a][5],r[a][6]);
	a = 6;
 printf("%zu, %zu, %zu, %zu, %zu, %zu, %zu\n",
		   r[a][0],r[a][1],r[a][2],r[a][3],r[a][4],r[a][5],r[a][6]);
	a = 7;
 printf("%zu, %zu, %zu, %zu, %zu, %zu, %zu\n",
		   r[a][0],r[a][1],r[a][2],r[a][3],r[a][4],r[a][5],r[a][6]);
	a = 8;
 printf("%zu, %zu, %zu, %zu, %zu, %zu, %zu\n",
		   r[a][0],r[a][1],r[a][2],r[a][3],r[a][4],r[a][5],r[a][6]);
	a = 9;
 printf("%zu, %zu, %zu, %zu, %zu, %zu, %zu\n",
		   r[a][0],r[a][1],r[a][2],r[a][3],r[a][4],r[a][5],r[a][6]);
	// Clear
	opencl->ret = clFlush(opencl->command_queue);
	opencl->ret = clFinish(opencl->command_queue);
	opencl->ret = clReleaseKernel(opencl->kernel);
	opencl->ret = clReleaseProgram(opencl->program);
	opencl->ret = clReleaseMemObject(mem_ci);
	opencl->ret = clReleaseMemObject(mem_cr);
	opencl->ret = clReleaseMemObject(mem_i);
	opencl->ret = clReleaseMemObject(mem_r);
	opencl->ret = clReleaseCommandQueue(opencl->command_queue);
	opencl->ret = clReleaseContext(opencl->context);
	return (1);
}
