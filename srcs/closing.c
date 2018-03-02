/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 12:52:57 by gelambin          #+#    #+#             */
/*   Updated: 2018/03/02 17:33:27 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <OpenCL/cl.h>
#include <opencl.h>
#include <mlx.h>
#include <mlxyz.h>
#include <fractol.h>

void	close_opencl(t_opencl *opencl)
{
	clFlush(opencl->command_queue);
	clFinish(opencl->command_queue);
	clReleaseKernel(opencl->kernel);
	clReleaseProgram(opencl->program);
	clReleaseMemObject(opencl->mem[0]);
	clReleaseMemObject(opencl->mem[1]);
	clReleaseCommandQueue(opencl->command_queue);
	clReleaseContext(opencl->context);
	free(opencl);
}

void	close_fractol(t_mlxyz *mlxyz)
{
	close_opencl(((t_fractol*)(mlxyz->app))->opencl);
	mlxyz_close(mlxyz);
	ft_putstr("Exit.");
	exit(0);
}

void	crash_fractol(char *str)
{
	ft_putendl("========== CRASH ==========");
	ft_putendl(str);
	ft_putendl("===========================");
	exit(1);
}
