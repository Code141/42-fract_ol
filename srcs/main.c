/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:44:58 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/12 09:52:24 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxyz.h>
#include <fractol.h>
#include <OpenCL/cl.h>

void		print_opencl()
{
	int				i;
	int				j;
	char*			value;
	size_t			valueSize;
	cl_uint			platformCount;
	cl_platform_id*	platforms;
	cl_uint			deviceCount;
	cl_device_id*	devices;
	cl_uint			maxComputeUnits;

	// get all platforms
	clGetPlatformIDs(0, NULL, &platformCount);
	platforms = (cl_platform_id*) malloc(sizeof(cl_platform_id) * platformCount);
	clGetPlatformIDs(platformCount, platforms, NULL);

	i = 0;
	while (i < platformCount)
	{
		// get all devices
		clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, 0, NULL, &deviceCount);
		devices = (cl_device_id*) malloc(sizeof(cl_device_id) * deviceCount);
		clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, deviceCount, devices, NULL);

		// for each device print critical attributes
		j = 0;
		while (j < deviceCount)
		{

			// print device name
			clGetDeviceInfo(devices[j], CL_DEVICE_NAME, 0, NULL, &valueSize);
			value = (char*) malloc(valueSize);
			clGetDeviceInfo(devices[j], CL_DEVICE_NAME, valueSize, value, NULL);
			printf("%d. Device: %s\n", j+1, value);
			free(value);

			// print hardware device version
			clGetDeviceInfo(devices[j], CL_DEVICE_VERSION, 0, NULL, &valueSize);
			value = (char*) malloc(valueSize);
			clGetDeviceInfo(devices[j], CL_DEVICE_VERSION, valueSize, value, NULL);
			printf(" %d.%d Hardware version: %s\n", j+1, 1, value);
			free(value);

			// print software driver version
			clGetDeviceInfo(devices[j], CL_DRIVER_VERSION, 0, NULL, &valueSize);
			value = (char*) malloc(valueSize);
			clGetDeviceInfo(devices[j], CL_DRIVER_VERSION, valueSize, value, NULL);
			printf(" %d.%d Software version: %s\n", j+1, 2, value);
			free(value);

			// print c version supported by compiler for device
			clGetDeviceInfo(devices[j], CL_DEVICE_OPENCL_C_VERSION, 0, NULL, &valueSize);
			value = (char*) malloc(valueSize);
			clGetDeviceInfo(devices[j], CL_DEVICE_OPENCL_C_VERSION, valueSize, value, NULL);
			printf(" %d.%d OpenCL C version: %s\n", j+1, 3, value);
			free(value);

			// print parallel compute units
			clGetDeviceInfo(devices[j], CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(maxComputeUnits), &maxComputeUnits, NULL);
			printf(" %d.%d Parallel compute units: %d\n", j+1, 4, maxComputeUnits);
			j++;
		}
		free(devices);
		i++;
	}
	free(platforms);
}

void		test()
{
	int						i;
	int						j;
	char*					info;
	size_t					infoSize;
	cl_uint					platformCount;
	cl_platform_id			*platforms;
	const char*				attributeNames[5] = { "Name", "Vendor", "Version", "Profile", "Extensions" };
	const cl_platform_info	attributeTypes[5] = { CL_PLATFORM_NAME, CL_PLATFORM_VENDOR, CL_PLATFORM_VERSION, CL_PLATFORM_PROFILE, CL_PLATFORM_EXTENSIONS };
	const int				attributeCount = sizeof(attributeNames) / sizeof(char*);

	// get platform count
	clGetPlatformIDs(5, NULL, &platformCount);

	// get all platforms
	platforms = (cl_platform_id*) malloc(sizeof(cl_platform_id) * platformCount);
	clGetPlatformIDs(platformCount, platforms, NULL);

	// for each platform print all attributes
	for (i = 0; i < platformCount; i++) {

		printf("\n %d. Platform \n", i+1);

		for (j = 0; j < attributeCount; j++) {

			// get platform attribute value size
			clGetPlatformInfo(platforms[i], attributeTypes[j], 0, NULL, &infoSize);
			info = (char*) malloc(infoSize);

			// get platform attribute value
			clGetPlatformInfo(platforms[i], attributeTypes[j], infoSize, info, NULL);

			printf("  %d.%d %-11s: %s\n", i+1, j+1, attributeNames[j], info);
			free(info);
		}
		printf("\n");
	}

	free(platforms);
}

cl_uint	get_platforms(cl_platform_id **platforms)
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

cl_uint	get_devices(cl_platform_id platform, cl_device_id	**devices)
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

	default_device = devices[0];
	print_device_info(default_device, "	Device		", CL_DEVICE_NAME);
	print_device_info(default_device, "	Hardware version", CL_DEVICE_VERSION);
	print_device_info(default_device, "	Software version", CL_DRIVER_VERSION);
	print_device_info(default_device, "	OpenCL C version", CL_DEVICE_OPENCL_C_VERSION);
	print_device_info(default_device, "	Parallel compute units", CL_DEVICE_MAX_COMPUTE_UNITS);

	cl_context	context;

	context = clCreateContext(NULL, 1, &default_device, NULL, NULL, NULL);



/* creation d'une queue de commande sur le premier GPU */ 
cl_command_queue queue;
queue = clCreateCommandQueue(context, default_device, 0, NULL);

/* allocation des tampons mémoire */
cl_mem memobjs[2];

memobjs[0] = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(float)*2*num_entries, srcA, NULL);
memobjs[1] = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(float)*2*num_entries, NULL, NULL);

/* création du programme de calcul (le programme qui s'execute sur le GPU) */ 
program = clCreateProgramWithSource(context, 1, &fft1D_1024_kernel_src, NULL, NULL);

/* compilation du programme */
clBuildProgram(program, 0, NULL, NULL, NULL, NULL);

/* création du noyau de calcul */
kernel = clCreateKernel(program, "fft1D_1024", NULL);

/* mise en place des paramètres */
clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&memobjs[0]);
clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&memobjs[1]);
clSetKernelArg(kernel, 2, sizeof(float)*(local_work_size[0]+1)*16, NULL);
clSetKernelArg(kernel, 3, sizeof(float)*(local_work_size[0]+1)*16, NULL);

/* création des objets de travail
 *    et lancement du calcul */
global_work_size[0] = num_entries;
local_work_size[0] = 64;
clEnqueueNDRangeKernel(queue, kernel, 1, NULL, global_work_size, local_work_size, 0, NULL, NULL);



	return (1);
}

int			main(int argc, char **argv)
{
	t_mlxyz		*mlxyz;
	t_fractol	fractol;

	argc--;
	argv++;
	//	if (argc != 1)
	//		show_usage();
	mlxyz = mlxyz_init();

	fractol.max_iter = 20;
	fractol.zoom = 150;
	fractol.x = 0;
	fractol.y = 0;


//	print_opencl();
	init_opencl();

	mlxyz->app = &fractol;
//	mlx_loop(mlxyz->mlx);

	return (0);
}
