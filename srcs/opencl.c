/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 02:15:09 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/13 07:14:18 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <OpenCL/cl.h>
#include <libft.h>

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

int			init_opencl()
{
	cl_uint			num_platforms;
	cl_platform_id	*platforms;
	cl_platform_id	default_platform;

	cl_uint			num_devices;
	cl_device_id	*devices;
	cl_device_id	default_device;


	ft_putstr("- Init OpenCl -\n");
	num_platforms = get_platforms(&platforms);
	if (!num_platforms)
	{
		ft_putstr("No cl_platform available\n");
		return (0);
	}

	default_platform = platforms[0];
	ft_putstr("Using plateform :\n");
	print_plateform_info(default_platform, "	Name	", CL_PLATFORM_NAME);
	print_plateform_info(default_platform, "	Vendor	", CL_PLATFORM_VENDOR);
	print_plateform_info(default_platform, "	Version	", CL_PLATFORM_VERSION);
	print_plateform_info(default_platform, "	Profile	", CL_PLATFORM_PROFILE);
	print_plateform_info(default_platform, "	Extensions", CL_PLATFORM_EXTENSIONS);
	ft_putstr("\n");

	num_devices = get_devices(default_platform, &devices);
	if (!num_devices)
	{
		ft_putstr("No cl_devices available\n");
		return (0);
	}

	default_device = devices[1];
	print_device_info(default_device, "	Device		", CL_DEVICE_NAME);
	print_device_info(default_device, "	Hardware version", CL_DEVICE_VERSION);
	print_device_info(default_device, "	Software version", CL_DRIVER_VERSION);
	print_device_info(default_device, "	OpenCL C version", CL_DEVICE_OPENCL_C_VERSION);
	print_device_info(default_device, "	Parallel compute units", CL_DEVICE_MAX_COMPUTE_UNITS);

	cl_context	context;

	context = clCreateContext(NULL, 1, &default_device, NULL, NULL, NULL);
/*

	// creation d'une queue de commande sur le premier GPU 
	cl_command_queue queue;
	queue = clCreateCommandQueue(context, default_device, 0, NULL);

	// allocation des tampons mémoire
	cl_mem memobjs[2];
	
	
	int num_entries;
	num_entries = 10;

	memobjs[0] = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(float)*2*num_entries, srcA, NULL);
	memobjs[1] = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(float)*2*num_entries, NULL, NULL);

	// création du programme de calcul (le programme qui s'execute sur le GPU)
	program = clCreateProgramWithSource(context, 1, &fft1D_1024_kernel_src, NULL, NULL);

	// compilation du programme
	clBuildProgram(program, 0, NULL, NULL, NULL, NULL);

	// création du noyau de calcul
	kernel = clCreateKernel(program, "fft1D_1024", NULL);

	// mise en place des paramètres
	clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&memobjs[0]);
	clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&memobjs[1]);
	clSetKernelArg(kernel, 2, sizeof(float)*(local_work_size[0]+1)*16, NULL);
	clSetKernelArg(kernel, 3, sizeof(float)*(local_work_size[0]+1)*16, NULL);

	// création des objets de travail et lancement du calcul
	global_work_size[0] = num_entries;
	local_work_size[0] = 64;
	clEnqueueNDRangeKernel(queue, kernel, 1, NULL, global_work_size, local_work_size, 0, NULL, NULL);
*/

	return (1);
}
/*
__kernel void fft1D_1024 (__global float2 *in, __global float2 *out, __local float *sMemx, __local float *sMemy)
{
	int tid = get_local_id(0);
	int blockIdx = get_group_id(0) * 1024 + tid;
	float2 data[16];

	// starting index of data to/from global memory
	in = in + blockIdx;
	out = out + blockIdx;
	globalLoads(data, in, 64);						// coalesced global reads
	fftRadix16Pass(data);							// in-place radix-16 pass
	twiddleFactorMul(data, tid, 1024, 0);
	// local shuffle using local memory
	localShuffle(data, sMemx, sMemy, tid, (((tid & 15) * 65) + (tid >> 4)));
	fftRadix16Pass(data);							// in-place radix-16 pass
	twiddleFactorMul(data, tid, 64, 4);				// twiddle factor multiplication
	localShuffle(data, sMemx, sMemy, tid, (((tid >> 4) * 64) + (tid & 15)));
	// four radix-4 function calls
	fftRadix4Pass(data);
	fftRadix4Pass(data + 4);
	fftRadix4Pass(data + 8);
	fftRadix4Pass(data + 12);
	// coalesced global writes
	globalStores(data, out, 64);

}
*/






#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>

#endif

#define MEM_SIZE (128)
#define MAX_SOURCE_SIZE (0x100000)
	 
int main()
{
	cl_device_id device_id = NULL;
	cl_context context = NULL;
	cl_command_queue command_queue = NULL;
	cl_mem memobj = NULL;
	cl_program program = NULL;
	cl_kernel kernel = NULL;
	cl_platform_id platform_id = NULL;
	cl_uint ret_num_devices;
	cl_uint ret_num_platforms;
	cl_int ret;
	 
	char string[MEM_SIZE];
	 
	FILE *fp;
	char fileName[] = "./hello.cl";
	char *source_str;
	size_t source_size;
	 
	/* Load the source code containing the kernel*/
	fp = fopen(fileName, "r");
	if (!fp) {
		fprintf(stderr, "Failed to load kernel.\n");
		exit(1);
	}
	source_str = (char*)malloc(MAX_SOURCE_SIZE);
	source_size = fread(source_str, 1, MAX_SOURCE_SIZE, fp);
	fclose(fp);
	 
	/* Get Platform and Device Info */
	ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
	ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_DEFAULT, 1, &device_id, &ret_num_devices);
	 
	/* Create OpenCL context */
	context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);
	 
	/* Create Command Queue */
	command_queue = clCreateCommandQueue(context, device_id, 0, &ret);
	 
	/* Create Memory Buffer */
	memobj = clCreateBuffer(context, CL_MEM_READ_WRITE,MEM_SIZE * sizeof(char), NULL, &ret);
	 
	/* Create Kernel Program from the source */
	program = clCreateProgramWithSource(context, 1, (const char **)&source_str,
			(const size_t *)&source_size, &ret);
	 
	/* Build Kernel Program */
	ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);
	 
	/* Create OpenCL Kernel */
	kernel = clCreateKernel(program, "hello", &ret);
	 
	/* Set OpenCL Kernel Parameters */
	ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&memobj);
	 
	/* Execute OpenCL Kernel */
	ret = clEnqueueTask(command_queue, kernel, 0, NULL,NULL);
	 
	/* Copy results from the memory buffer */
	ret = clEnqueueReadBuffer(command_queue, memobj, CL_TRUE, 0,
			MEM_SIZE * sizeof(char),string, 0, NULL, NULL);
	 
	/* Display Result */
	puts(string);
	 
	/* Finalization */
	ret = clFlush(command_queue);
	ret = clFinish(command_queue);
	ret = clReleaseKernel(kernel);
	ret = clReleaseProgram(program);
	ret = clReleaseMemObject(memobj);
	ret = clReleaseCommandQueue(command_queue);
	ret = clReleaseContext(context);
	 
	free(source_str);
	 
	return 0;
}
