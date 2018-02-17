/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 02:15:53 by gelambin          #+#    #+#             */
/*   Updated: 2018/02/17 06:11:35 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPENCL_H
# define OPENCL_H
# include <OpenCL/cl.h>

typedef struct	s_opencl
{
	cl_uint				platforms_count;
	cl_platform_id		*platforms;
	cl_platform_id		platform;
	cl_uint				devices_count;
	cl_device_id		*devices;
	cl_device_id		device;
	cl_context			context;
	cl_command_queue	command_queue;
	cl_program			program;
	cl_kernel			kernel;
	size_t				global_work_size[3];
	cl_mem				mem[2];
	cl_int				ret;
}				t_opencl;

int				init_opencl(t_opencl *opencl);

#endif
